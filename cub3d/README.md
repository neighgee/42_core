*This project has been created as part of the 42 curriculum by smariapp, mwin.*

# cub3D — My first RayCaster with miniLibX

## Description

cub3D is a 3D maze exploration program built in C using ray-casting techniques, inspired by the world-famous Wolfenstein 3D — the first true First Person Shooter in video game history.

The goal of the project is to render a realistic first-person view of the inside of a maze from a `.cub` scene description file. The program handles wall textures that vary depending on the cardinal direction they face (North, South, East, West), as well as configurable floor and ceiling colors. The player can navigate the maze using keyboard controls and look left or right to explore the environment.

This project combines low-level C programming, mathematical reasoning, and graphics rendering to produce an interactive real-time application using the miniLibX library.

## Instructions

### Requirements

- GCC or CC compiler
- miniLibX (included in the repository)
- libft (included in the repository)
- X11 and Xext libraries (Linux)

### Compilation

```bash
make
```

### Usage

```bash
./cub3D <path_to_map.cub>
```

Example:
```bash
./cub3D maps/good/cheese_maze.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `A` | Rotate left |
| `S` | Move backward |
| `D` | Rotate left |
| `←` | Rotate view left |
| `→` | Rotate view right |
| `ESC` | Close the window and exit |
| Cross | Close the window and exit |

### Map Format (`.cub`)

A valid `.cub` file must contain the following elements before the map:

```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm
F R,G,B
C R,G,B
```

Followed by the map, which must:
- Be the last element in the file
- Be composed only of: `0` (empty), `1` (wall), `N`/`S`/`E`/`W`, ` `(spaces) (player start + orientation)
- Be fully enclosed by walls

### Cleaning

```bash
make clean      # remove object files
make fclean     # remove object files and binary
make bonus      # create a executable with bonus
make re         # full recompilation
make it			# removes intermediary files with re
```

## Resources

### Ray-Casting & Graphics

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — The definitive guide to DDA-based ray-casting
- [miniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) — Reference for the miniLibX graphics library
- [Wolfenstein 3D](http://users.atw.hu/wolf3d/) — The original game that inspired this project

### Mathematics

- [Wikipedia: Ray casting](https://en.wikipedia.org/wiki/Ray_casting)
- [Wikipedia: Digital differential analyzer](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))

### credits
maps and textures: https://github.com/mcombeau/cub3D

### AI Usage

Claude (Anthropic) and ChatGPT was used throughout this project for the following purposes:

- **Debugging**: Identifying memory errors, incorrect pointer arithmetic, and logic bugs during parsing
- **Code review**: Spotting uninitialized variables, incorrect sizeof usage, and off-by-one errors
- **Explanations**: Clarifying C concepts such as pointer arithmetic, malloc sizing, and file descriptor handling
- **Makefile issues**: Diagnosing linker errors and flag typos

All AI-generated suggestions were reviewed, understood, and adapted before being integrated into the project.
