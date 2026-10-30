#include "DarkestSoulsCombatRules.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDarkSoulsQueueFifoTest, "DarkestSouls.Combat.QueueFifoAndLearning", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FDarkestSoulsQueueFifoTest::RunTest(const FString& Parameters)
{
    FDarkSoulsCombatState State;
    TestTrue(TEXT("Recover queues"), FDarkSoulsCombatRules::TryQueueCard(State, EDarkSoulsCard::Recover));
    TestTrue(TEXT("First heavy queues"), FDarkSoulsCombatRules::TryQueueCard(State, EDarkSoulsCard::HeavyStrike));
    TestTrue(TEXT("Second heavy queues"), FDarkSoulsCombatRules::TryQueueCard(State, EDarkSoulsCard::HeavyStrike));
    TestFalse(TEXT("Fourth action is refused"), FDarkSoulsCombatRules::TryQueueCard(State, EDarkSoulsCard::QuickStrike));

    const FDarkSoulsActionResolution Recover = FDarkSoulsCombatRules::ResolveNextQueuedCard(State);
    TestTrue(TEXT("Recover resolves first"), Recover.bHasCard && Recover.Card == EDarkSoulsCard::Recover);
    TestEqual(TEXT("Recovery restores stamina"), State.Stamina, 8);

    const FDarkSoulsActionResolution FirstHeavy = FDarkSoulsCombatRules::ResolveNextQueuedCard(State);
    TestTrue(TEXT("First heavy is paid"), FirstHeavy.bPaid);
    TestEqual(TEXT("First heavy deals its damage"), State.EnemyHealth, 15);
    const FDarkSoulsActionResolution SecondHeavy = FDarkSoulsCombatRules::ResolveNextQueuedCard(State);
    TestTrue(TEXT("Second heavy is paid in FIFO order"), SecondHeavy.bPaid);
    TestEqual(TEXT("Both heavy strikes resolve"), State.EnemyHealth, 8);
    TestEqual(TEXT("Stamina is spent in order"), State.Stamina, 0);
    TestTrue(TEXT("Heavy cost is learned"), State.KnownCosts.Contains(EDarkSoulsCard::HeavyStrike));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDarkSoulsCostRevealTest, "DarkestSouls.Combat.CostRevealsOnFailure", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FDarkSoulsCostRevealTest::RunTest(const FString& Parameters)
{
    FDarkSoulsCombatState State;
    State.Stamina = 1;
    FDarkSoulsCombatRules::TryQueueCard(State, EDarkSoulsCard::HeavyStrike);
    const FDarkSoulsActionResolution Result = FDarkSoulsCombatRules::ResolveNextQueuedCard(State);
    TestTrue(TEXT("The attempted card is returned"), Result.bHasCard);
    TestFalse(TEXT("Unaffordable action does not execute"), Result.bPaid);
    TestTrue(TEXT("Unaffordable attempt still teaches the cost"), State.KnownCosts.Contains(EDarkSoulsCard::HeavyStrike));
    TestEqual(TEXT("Enemy remains unharmed"), State.EnemyHealth, 22);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDarkSoulsSecondBoutTest, "DarkestSouls.Combat.SecondBoutCarriesState", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FDarkSoulsSecondBoutTest::RunTest(const FString& Parameters)
{
    FDarkSoulsCombatState State;
    State.PlayerHealth = 12;
    State.Stamina = 2;
    State.EnemyHealth = 0;
    State.KnownCosts.Add(EDarkSoulsCard::HeavyStrike);
    TestTrue(TEXT("The Veilleur returns for a second bout"), FDarkSoulsCombatRules::BeginSecondBout(State));
    TestEqual(TEXT("Enemy health resets for the return"), State.EnemyHealth, 22);
    TestEqual(TEXT("Player health carries forward"), State.PlayerHealth, 12);
    TestEqual(TEXT("Stamina carries forward without refill"), State.Stamina, 2);
    TestTrue(TEXT("Learned costs carry forward"), State.KnownCosts.Contains(EDarkSoulsCard::HeavyStrike));
    TestTrue(TEXT("Second-bout state is recorded"), State.bSecondBout);
    return true;
}
#endif
