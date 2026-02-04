*This project has been created as part of the 42 curriculum by hcissoko.*

## Description
This project is about creating a small 2D game where the player must collect all items and reach the exit on a map defined by a `.ber` file. The graphical rendering is handled by the MiniLibX library.

## Features
- Map parsing and validation
- Graphical display with MiniLibX
- Player movement (arrows)
- Collision and collection management
- Move counter
- Memory cleanup (valgrind OK)

## Compilation
Use the provided Makefile:

```sh
make
```

To clean object files:

```sh
make clean
make fclean
```

## Run the game

```sh
./so_long map.ber
```

## Map format
- Text file with `.ber` extension
- Valid characters: `0` (floor), `1` (wall), `C` (collectible), `E` (exit), `P` (player)
- The map must be rectangular, surrounded by walls, and contain only one player, one exit, and at least one collectible

## Dependencies
- MiniLibX (already included in the `minilibx-linux` folder)
- X11 (Linux)

## Bonus
- Sprite animations
- On-screen move counter