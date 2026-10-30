# Card spec

Costs are fixed in v0.1 but hidden until a card resolves once. The reveal is permanent for the run. Effects resolve immediately in queue order.

| Card | Hidden cost | Effect |
|---|---:|---|
| Frappe vive | 1 | Deal 3 damage. |
| Frappe lourde | 4 | Deal 7 damage. |
| Garde | 2 | Block up to 5 damage from the next enemy attack. |
| Pas de côté | 2 | Avoid the next enemy attack. |
| Reprendre souffle | 0 | Restore 3 stamina, up to the cap of 8. |

An action that cannot be paid for fails when it resolves, but still reveals its cost. Guard and Dodge expire after the next enemy attack. Repeated Guard actions stack up to 8 block; Dodge is a single-use evade.

These values are internal rules data. The HUD must not print cost, health, stamina, guard, or damage totals as numerals. Show an unknown cost as an obscured mark, then reveal its relative cost with ember pips after first use. Keep the combat read partial and diegetic.

