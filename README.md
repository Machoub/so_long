# 🎮 so_long – 42 Project

A simple 2D tile-based game using the MiniLibX graphics library.  
The goal: create a small game where a player moves through a map, collects items, and reaches the exit, all while respecting strict constraints and memory safety.

---

## 📌 Description

`so_long` is a 42 project that introduces basic game rendering and input handling using the **MiniLibX** library.  
You must render a map, handle keyboard input, and respect specific gameplay rules such as collectibles, walls, and exit conditions.

---

## 🧱 Game Rules

- You must load a `.ber` map file containing:
  - `1` → wall
  - `0` → empty space
  - `P` → player
  - `C` → collectible
  - `E` → exit

- The player must:
  - Collect all `C`s before exiting via `E`
  - Only move using arrow keys or `WASD`
  - The number of moves must be printed to the terminal

---

## 📂 Project Structure

├── Makefile
├── README.md
├── img_xpm
│   ├── dj_close.xpm
│   ├── dj_open.xpm
│   ├── floor.xpm
│   ├── item.xpm
│   ├── player.xpm
│   ├── player_left.xpm
│   ├── player_right.xpm
│   ├── player_up.xpm
│   └── wall.xpm
├── libft
├── maps
│   ├── map_invalid.ber
│   ├── map_invalid2_empty_line.ber
│   ├── map_invalid3_no_collect.ber
│   ├── map_invalid_path.ber
│   ├── map_invalid_wall.ber
│   ├── map_no_valid1.ber
│   ├── map_valid1.ber
│   ├── map_valid2.ber
│   ├── map_valid3.ber
│   ├── map_valid4.ber
│   └── triangle_map.ber
└── sources
    ├── aff
    │   ├── display.c
    │   ├── display_utils.c
    │   └── render_map.c
    ├── end_game.c
    ├── map
    │   ├── correct_map.c
    │   ├── init_map.c
    │   ├── map_utils.c
    │   ├── parsing_map.c
    │   ├── path_utils.c
    │   └── path_valid.c
    ├── mouv
    │   ├── move_down.c
    │   ├── move_left.c
    │   ├── move_right.c
    │   ├── move_up.c
    │   └── move_utils.c
    ├── so_long.c
    └── so_long.h

---

## 🧠 What I Learned

- Using the **MiniLibX** library for graphics
- Basic **event-driven programming** with keyhooks
- Managing **2D arrays and map parsing**
- Handling **keyboard input** and refreshing the display
- Creating a small **game loop**
- Ensuring proper **error handling and memory leaks protection**

---

## 🛠️ Build & Run

### Compile:
```
make
```
Run the game:
```
./so_long maps/map1.ber
```
## 🧪 Map Format
Example .ber map:

```
111111
1P0C01
100001
1C0E11
111111
```
## ✅ The map must:

Be rectangular

Be surrounded by walls

Contain 1 player, 1+ collectibles, and 1 exit

---

## ❌ Error Handling
The program exits gracefully in case of:

Invalid or non-rectangular maps

Missing elements (no P, C, or E)

Unreachable collectibles or exit

Memory allocation failure

---