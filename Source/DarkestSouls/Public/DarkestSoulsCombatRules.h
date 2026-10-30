#pragma once

#include "CoreMinimal.h"

enum class EDarkSoulsCard : uint8
{
    QuickStrike,
    HeavyStrike,
    Guard,
    Dodge,
    Recover
};

struct FDarkSoulsCombatState
{
    int32 PlayerHealth = 24;
    int32 EnemyHealth = 22;
    int32 Stamina = 5;
    int32 Guard = 0;
    int32 TurnIndex = 0;
    bool bDodge = false;
    bool bSecondBout = false;
    TArray<EDarkSoulsCard> Queue;
    TSet<EDarkSoulsCard> KnownCosts;
};

struct FDarkSoulsActionResolution
{
    EDarkSoulsCard Card = EDarkSoulsCard::QuickStrike;
    int32 Cost = 0;
    int32 Damage = 0;
    bool bHasCard = false;
    bool bPaid = false;
};

class FDarkSoulsCombatRules final
{
public:
    static constexpr int32 MaximumQueueSize = 3;
    static bool TryQueueCard(FDarkSoulsCombatState& State, EDarkSoulsCard Card);
    static FDarkSoulsActionResolution ResolveNextQueuedCard(FDarkSoulsCombatState& State);
    static int32 ApplyEnemyAttack(FDarkSoulsCombatState& State);
    static void CompleteTurn(FDarkSoulsCombatState& State);
    static bool BeginSecondBout(FDarkSoulsCombatState& State);
    static int32 CostFor(EDarkSoulsCard Card);
    static int32 DamageFor(EDarkSoulsCard Card);
};
