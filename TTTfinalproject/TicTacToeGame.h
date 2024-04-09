#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <iostream>
#include <fstream>
#include <ctime>

class TicTacToeGame {
public:
    TicTacToeGame() : row(0), column(0), turn('X'), draw(false), isPlayer2NPC(false) {
        initialize_game();
    }

    void playGame();

private:
    char board[3][3]; // 3x3 array representing the Tic Tac Toe board
    int choice; // Variable to store the current move's position chosen by the player
    int row, column; // Variables to store the row and column of the board where the current move is made
    char turn; // Variable to indicate whose turn it is, 'X' or 'O'
    bool draw; // Flag to indicate if the game has ended in a draw
    bool isPlayer2NPC; // Flag to indicate if the second player is an NPC

    void initialize_game() {
        turn = 'X'; // Set the first turn to player 'X'
        draw = false; // Reset the draw state to false
        // Initialize the board with numbers 1-9, which will be later replaced by 'X' or 'O'
        board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
    }

    void display_board() {
        std::cout << "Player - 1 [X]  Player - 2 [O]\n\n";
        std::cout << "     |     |     \n";
        std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
        std::cout << "_____|_____|_____\n";
        std::cout << "     |     |     \n";
        std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
        std::cout << "_____|_____|_____\n";
        std::cout << "     |     |     \n";
        std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
        std::cout << "     |     |     \n\n";
    }

    bool gameover() {
        // Check for win conditions for each row and column
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) return false;
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) return false;
        }
        // Check for win conditions for both diagonals
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return false;
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) return false;

        // Check for any unfilled cells, which means the game can continue
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return true; // There are still moves to be made, game continues

        // If no win and no moves left, it's a draw
        draw = true;
        return false; // No moves can be made, game is over
    }

    void npc_turn() {
        srand((unsigned)time(0)); // Seed the random number generator
        int choice;
        do {
            choice = rand() % 9; // Generate a random number for the board position
            row = choice / 3; // Translate to row index
            column = choice % 3; // Translate to column index
        } while (board[row][column] == 'X' || board[row][column] == 'O'); // Keep trying if cell is taken
        board[row][column] = 'O'; // Place 'O' in the chosen cell
        std::cout << "NPC Played " << (row * 3 + column + 1) << std::endl; // Output the NPC's move
    }

    void announce_winner(std::ofstream& file) {
        if (draw) {
            std::cout << "Game ended in a draw.\n"; // Announce a draw to the console
            file << "Game ended in a draw.\n"; // Write the draw to the file
        } else {
            char winner = get_winner(); // Get the winner's symbol
            std::cout << "Player " << winner << " wins!\n"; // Announce the winner to the console
            file << "Player " << winner << " wins!\n"; // Write the winner to the file
        }
    }

    char get_winner() {
        if (draw) return 'D'; // Return 'D' for a draw
        return (turn == 'X' ? 'O' : 'X'); // Return the symbol of the winner
    }
};

#endif // TICTACTOEGAME_H
