# RPG Game in C (Terminal-based)

## Description
This project is a small RPG game written in C that runs in the terminal. Players use `W, S, A, D` keys to move around, encounter enemies, use weapons and scrolls to cast abilities, gain experience points (XP), and choose stuts upgrades to progress in the game.

## Features
- Terminal-based RPG gameplay.
- Movement controls `(W, S, A, D)`.
- Weapons.
- Scrolls that cast abilities.
- XP system with leveling up.

## Controls
- `W, S, A, D` - Move character up, down, left, right.
- `E` - To Battle with Enemies
- `W, S, E, Q` Key mappings for selecting actions (W, S), use (E), escape(Q).

## Compile
``` 
gcc Game.c Enemies.c Items.c Maps.c Scrolls.c Talisman.c Weapons.c Battle.c Quests.c Drops.c Public.c -o Game
```

## Future Development
- Adding more story qust for the game play
- More Weapons
- More Scrolls
- More Enemies
- More structurs and maps

## Contributing
Feel free to fork this repository and make improvements. Open issues or pull requests if you'd like to contribute to the development of this interactive showcase.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
