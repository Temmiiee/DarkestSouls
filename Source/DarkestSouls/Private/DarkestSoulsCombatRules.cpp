#include "DarkestSoulsCombatRules.h"

bool FDarkSoulsCombatRules::TryQueueCard(FDarkSoulsCombatState& State, EDarkSoulsCard Card)
{
    if (State.Queue.Num() >= MaximumQueueSize) return false;
    State.Queue.Add(Card);
    return true;
}

FDarkSoulsActionResolution FDarkSoulsCombatRules::ResolveNextQueuedCard(FDarkSoulsCombatState& State)
{
    return {};
}

int32 FDarkSoulsCombatRules::ApplyEnemyAttack(FDarkSoulsCombatState& State)
{
    return 0;
}

void FDarkSoulsCombatRules::CompleteTurn(FDarkSoulsCombatState& State)
{
}

bool FDarkSoulsCombatRules::BeginSecondBout(FDarkSoulsCombatState& State)
{
    return false;
}

int32 FDarkSoulsCombatRules::CostFor(EDarkSoulsCard Card)
{
    return 0;
}

int32 FDarkSoulsCombatRules::DamageFor(EDarkSoulsCard Card)
{
    return 0;
}
