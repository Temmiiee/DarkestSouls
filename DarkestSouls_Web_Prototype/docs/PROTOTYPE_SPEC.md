# Prototype spec

## v0.1 slice

A single-path combat test: one Champion, one Veilleur creux, and five reusable action cards. The Veilleur falls once, rises for a second bout, and remains the only opponent. The player queues up to three cards, then watches them resolve in FIFO order. Each card's stamina cost stays hidden until its first resolution; after that, its relative cost appears as ember marks for the rest of the run, never as a numeral.

The enemy telegraphs its next attack before the player commits. Guard reduces that attack, while Dodge avoids it. If a queued action costs more stamina than remains when it reaches the front of the queue, it fails and reveals its cost. Recover can be queued before or after another card, so order changes what is affordable.

## Information and uncertainty

Combat should preserve pressure, not read like a dashboard. The HUD shows no numeric health or stamina totals, no damage values, no turn counter, and no queue counter. Health and stamina appear only as unnumbered bars. The enemy gives a qualitative body-language tell, not exact damage or a fully spelled-out attack result. Card costs stay concealed until first use; learned costs appear as ember marks, never digits. Keep exact values in rules data and design docs, not on the combat screen. Feedback should be brief and contextual rather than a permanent numerical log.

## Starting values

- Champion: 24 HP, 5 stamina.
- Veilleur: 22 HP per bout.
- Stamina cap: 8; regain 2 at the end of each survived turn. Unspent stamina carries over. It does not refill at the start of a turn or between the Veilleur's bouts.
- The Veilleur's attack alternates between a 5-damage descending strike and a 7-damage thrust.
- Queue size: 3 cards.
- After the first bout, the Veilleur returns at full health; Champion health, stamina, and learned card costs carry forward unchanged.

## Out of scope for this slice

No additional enemy archetypes, procedural costs, equipment, persistent currency, or animation assets yet. The one Veilleur returns for a second bout so the prototype can test stamina carry-over without introducing another enemy design.

## Playable reference

`prototype/index.html` is the local, dependency-free browser build used to test the rules before UE 5.8 is available.

