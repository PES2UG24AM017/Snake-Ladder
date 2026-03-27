# Snake and Ladder Game in C
A text-based Snake and Ladder game implemented in C, playable in the terminal. This project simulates the classic board game for two players using simple console input and output.


## Features
* Two-player gameplay
* Random dice rolling using `rand()`
* Snakes that move players down
* Ladders that move players up
* Option to replay the game
* Fully console-based (no GUI)

## Technologies Used
* C Programming Language
* Standard Libraries: 'stdio.h', 'stdlib.h', 'time.h', 'ctype.h'

## How to Run

### 1. Compile the program
```bash
gcc snake_ladder.c -o snake_ladder
```

### 2. Run the program

```bash
./snake_ladder
```

*(On Windows PowerShell use: `.\snake_ladder`)*

## Project Structure

```
snake-ladder-console-c/
│
├── snake_ladder.c
├── README.md
└── .gitignore
```

---

## Game Rules

* Players take turns rolling a dice
* Landing on a ladder moves the player up
* Landing on a snake moves the player down
* First player to reach position **100** wins
* Exact roll required to reach 100

## Future Improvements

* Add single-player mode (vs computer)
* Improve UI using graphics
* Add score tracking

## Acknowledgment

Inspired by the classic Snake and Ladder board game.
