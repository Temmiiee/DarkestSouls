# Unreal tasks

The browser slice in `prototype/index.html` is the rules reference. Port the same values before changing balance.

## First UE 5.8 implementation

1. Create the Blueprint project using the supplied layout: `Content/Blueprints`, `Content/Data`, and `Content/UI`.
2. Add `DA_ActionCard` and `DA_Enemy` data assets in `Content/Data` for the five cards and the Veilleur creux.
3. Build `BP_CombatManager` in `Content/Blueprints` with player/enemy state, a three-card FIFO queue, first-use cost discovery, stamina checks, enemy telegraphs, turn resolution, and the two-bout return of the same Veilleur.
4. Build `WBP_CombatScreen` in `Content/UI` with the hand, queue, qualitative stamina/health bars, enemy posture tell, and brief contextual feedback. Do not show numeric health, stamina, damage, turn, queue, or guard totals in the HUD; learned costs use ember marks rather than numerals.
5. Keep stamina between turns and across the Veilleur's return. Do not refill at the bout transition; preserve Champion health and learned card costs too.
6. Replace the text/Unicode combat portraits with temporary UE meshes or silhouettes only after the rules pass playtesting.

## Acceptance checks

- Queue order controls action order and recovery can make a later card affordable.
- A hidden cost is revealed after the card's first resolution, including an unaffordable attempt.
- Guard blocks the next telegraphed hit; Dodge avoids it.
- End-turn recovery adds 2 stamina up to a cap of 8.
- Win and defeat states both offer a clean restart.
- After the first bout, the same Veilleur returns while Champion health, stamina, and learned costs remain; the HUD shows no numeric totals.

No `.uproject` is included yet; the engine is still downloading, so Unreal compilation and editor verification have not been run.

