# Darkest Souls UE Prototype Starter

A small combat prototype for testing hidden action costs, FIFO resolution, and stamina management. The HUD keeps combat information qualitative; exact values stay in the rules data.

## Play the current slice

Open [`prototype/index.html`](prototype/index.html) in a browser. It runs locally and does not need Unreal Engine.

## Project notes

- [`docs/PROTOTYPE_SPEC.md`](docs/PROTOTYPE_SPEC.md): scope and rules for v0.1.
- [`docs/CARD_SPEC.md`](docs/CARD_SPEC.md): action costs and effects.
- [`docs/PLAYTEST_CHECKLIST.md`](docs/PLAYTEST_CHECKLIST.md): first balance questions.
- [`docs/UNREAL_TASKS.md`](docs/UNREAL_TASKS.md): porting plan for UE 5.8 after installation.

The browser build is a mechanic test, not the final Unreal implementation. Its one path has two bouts against the same Veilleur; stamina carries over without a refill between them. The earlier website-layout pass is archived as `prototype/index-v0.1-website-layout.html`; `prototype/index.html` is the current HUD.

