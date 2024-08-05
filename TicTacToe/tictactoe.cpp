#include <iostream>
#include <vector>

// Function to draw the game board
void drawBoard(const std::vector<std::vector<char>>& board) {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    char currentPlayer = 'X';

    std::cout << "Tip: Enter row followed by a space and then the column, when asked to make your move \n";

    while (true) {
        // Display the current state of the board
        drawBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        std::cout <<"\n";
        std::cout <<"\n";
        std::cout << "Player " << currentPlayer << ", enter your move : ";
        std::cin >> row >> col;

        // Update the game board with the player's move
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            std::cout << "Invalid move, try again.\n";
            continue;
        }
        row--; col--;
        if (board[row][col] != '-') {
            std::cout << "Invalid move, try again.\n";
            continue;
        }
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            std::cout <<"\n";
            std::cout <<"\n";
            drawBoard(board);
            std::cout <<"\n";
            std::cout <<"\n";
            std::cout << "Player " << currentPlayer << " wins!\n";
            std::cout <<"\n";
            std::cout <<"\n";
            break;
            
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if the players want to play another game
    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
    if (playAgain == 'y') {
        main();
    }

    return 0;
}