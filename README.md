# Tic-Tac-Toe Game

Welcome to Compiler Gamings' implementation of the classic Tic-Tac-Toe game in C. This simple console-based game allows two players to play Tic-Tac-Toe against each other.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [How to Play](#how-to-play)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project is a basic implementation of the Tic-Tac-Toe game using C. It includes functions for player moves, checking for wins, and displaying the game board. The game supports two players and checks for winning conditions across rows, columns, and diagonals.

## Features

- Two-player gameplay
- Clear and interactive console-based interface
- Automatic detection of invalid moves
- Check for win conditions
- Option to play again after a game ends

## How to Play

1. Run the game.
2. Players take turns to enter their moves in the format `col row`.
3. The game checks for a win or a draw after each move.
4. The game ends when a player wins or when there are no more valid moves (a draw).
5. Players are prompted to play again or exit the game after each match.

## Installation

To install and run this game, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/amit712singhal/Tic-Tac-Toe.git
    ```
2. Navigate to the project directory:
    ```sh
    cd tic-tac-toe
    ```
3. Compile the code:
    ```sh
    gcc main.c -o main
    ```
4. Run the game:
    ```sh
    ./main
    ```

## Usage

Once the game is running, follow the on-screen instructions. Players will be prompted to enter their moves in the format `col row`, where `col` is the column index and `row` is the row index (both 0-based).

Example:
 ```sh
 Player 1 Move (col,row) :: 1 2
 ```
 
## Code Overview

The main functions and their purposes are:

- `main()`: The driver function that initializes the game and handles replay logic.
- `playerMove(int matrix[N][N], int player)`: Manages player moves and checks for win or draw conditions.
- `draw(int a[N][N])`: Checks if the game is a draw.
- `display(int a[N][N])`: Displays the current state of the game board.
- `check_rows(int array[N][N], int player)`, `check_columns(int array[N][N], int player)`, `check_diagonals(int array[N][N], int player)`: Check for win conditions in rows, columns, and diagonals respectively.
- `win(int a[N][N], int player)`: Checks if the current player has won.
- `set(int a[N][N], int m, int n, int player)`: Sets the player's move on the game board.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/YourFeature`).
3. Commit your changes (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeature`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
