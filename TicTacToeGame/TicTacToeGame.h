#pragma once
// Include necessary libraries
#include <iostream> // For input and output to the console
#include <fstream>  // For file input/output operations
#include <cstdlib>  // For general purpose functions including random number generation
#include <ctime>    // For time-related functions, used here to seed the random number generator

// Definition of the TicTacToeGame class
class TicTacToeGame {
public:
    TicTacToeGame(); // Constructor to initialize an object of TicTacToeGame
    void playGame(); // Public method to start the game process

private:
    char board[3][3]; // 3x3 array representing the Tic Tac Toe board
    int choice; // Variable to store the current move's position chosen by the player
    int row, column; // Variables to store the row and column of the board where the current move is made
    char turn; // Variable to indicate whose turn it is, 'X' or 'O'
    bool draw; // Flag to indicate if the game has ended in a draw
    bool isPlayer2NPC; // Flag to indicate if the second player is an NPC

    // Private methods for internal game logic
    void initialize_game(); // Initializes the board and other variables at the start of a game
    void display_board(); // Displays the current state of the game board
    bool gameover(); // Checks if the game has ended in a win or a draw
    void npc_turn(); // Handles the NPC's move if there is an NPC player
    void announce_winner(std::ofstream& file); // Announces the game's winner or if it's a draw
    char get_winner(); // Determines and returns the symbol of the winning player
};
