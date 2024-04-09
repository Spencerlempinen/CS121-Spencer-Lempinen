/*
 * @SpencerLempinen
 *
 * 12/2/23
 *
 * What's new:
 * We use srand() and rand().
 * srand() and rand() are used to allow the NPC to make random moves
 *
 * srand(): This function is called each time npc_turn() is executed to seed the random number generator.
 * The seed is based on the current time (from time(0)),
 * ensuring that the sequence of random numbers is different for each game
 *
 * rand(): This function is used to generate a pseudo-random number within the npc_turn() method.
 * The % 9 operation is applied to the result of rand() to scale it down to a range between 0 and 8,
 * which corresponds to the indices of the Tic Tac Toe board.
 *
 *
 */
#include "TicTacToeGame.h"
// Entry point of the program
int main() {

    TicTacToeGame game; // Instantiate the TicTacToeGame class

    game.playGame(); // Begin playing the game

    return 0; // Indicate that the program ended successfully
}
// Constructor that initializes the game when a TicTacToeGame object is created
TicTacToeGame:
:TicTacToeGame() : row(0), column(0), turn(
        'X'
), draw(false), isPlayer2NPC(false) {

    initialize_game(); // Set the board and initial game state
}
// Initializes the game board with numbers and sets the current turn to 'X'
void TicTacToeGame:
:initialize_game() {

    turn = 'X'; // Set the first turn to player 'X'

    draw = false; // Reset the draw state to false

// Initialize the board with numbers 1-9, which will be later replaced by 'X' or 'O'

    board[0]
    [0] = '1'; board[0]
               [1] = '2'; board[0]
                          [2] = '3';

    board[1]
    [0] = '4'; board[1]
               [1] = '5'; board[1]
                          [2] = '6';

    board[2]
    [0] = '7'; board[2]
               [1] = '8'; board[2]
                          [2] = '9';
}
// Prints the current game board to the console with player indicators
void TicTacToeGame:
:display_board() {

// Display the board and player turn indicators

    std:
    :cout << "Player - 1 [X] Player - 2 [O]\n\n";

    std:
    :cout << "
     |
     |
    \n";

    std:
    :cout << " " << board[0]
    [0] << "
     | " << board[0]
     [1] << "
     | " << board[0]
     [2] << " \n";

    std:
    :cout << "
    _____|_____|_____\n";

    std:
    :cout << "
     |
     |
    \n";

    std:
    :cout << " " << board[1]
    [0] << "
     | " << board[1]
     [1] << "
     | " << board[1]
     [2] << " \n";

    std:
    :cout << "
    _____|_____|_____\n";

    std:
    :cout << "
     |
     |
    \n";

    std:
    :cout << " " << board[2]
    [0] << "
     | " << board[2]
     [1] << "
     | " << board[2]
     [2] << " \n";

    std:
    :cout << "
     |
     |
    \n";
}
// Checks if the game is over by looking for a win or a draw
bool TicTacToeGame:
:gameover() {

// Check for win conditions for each row and column

    for (int i = 0; i < 3; i++) {

        if (board[i]
            [0] == board[i]
            [1] && board[i]
                   [0] == board[i]
                   [2]
                ) return false;

        if (board[0]
            [i] == board[1]
            [i] && board[0]
                   [i] == board[2]
                   [i]
                ) return false;

    }

// Check for win conditions for both diagonals

    if (board[0]
        [0] == board[1]
        [1] && board[0]
               [0] == board[2]
               [2]
            ) return false;

    if (board[0]
        [2] == board[1]
        [1] && board[0]
               [2] == board[2]
               [0]
            ) return false;

// Check for any unfilled cells, which means the game can continue

    for (int i = 0; i < 3; i++)

        for (int j = 0; j < 3; j++)

            if (board[i]
                [j] != 'X' && board[i]
                              [j] != 'O'
                    )

                return true; // There are still moves to be made, game continues

// If no win and no moves left, it's a draw

    draw = true;

    return false; // No moves can be made, game is over
}
// Function that controls the NPC turn
void TicTacToeGame:
:npc_turn() {

    srand(
            (unsigned)time(0)
    ); // Seed the random number generator

    int choice;

    do {

        choice = rand() % 9; // Generate a random number for the board position

        row = choice / 3; // Translate to row index

        column = choice % 3; // Translate to column index

    } while (board[row]
             [column] == 'X' |
             | board[row]
               [column] == 'O'
            ); // Keep trying if cell is taken

    board[row]
    [column] = 'O'; // Place 'O' in the chosen cell

    std:
    :cout << "NPC Played " << (row * 3 + column + 1) << std:
    :endl; // Output the NPC's move
}
// Announces the winner of the game or if it's a draw
void TicTacToeGame:
:announce_winner(std:
:ofstream& file) {

if (draw) {

std:
:cout << "Game ended in a draw.\n"; // Announce a draw to the console

file << "Game ended in a draw.\n"; // Write the draw to the file

} else {

char winner = get_winner(); // Get the winner's symbol

std:
:cout << "Player " << winner << " wins!\n"; // Announce the winner to the console

file << "Player " << winner << " wins!\n"; // Write the winner to the file

}
}
// Determines and returns the winning player's symbol
char TicTacToeGame:
:get_winner() {

    if (draw) return 'D'; // Return 'D' for a draw

    return (turn == 'X' ? 'O' : 'X'
    ); // Return the symbol of the winner
}
// Main function to play the game; contains the game loop
void TicTacToeGame:
:playGame() {

    std:
    :ofstream resultFile("gameResults.txt", std:
    :ios:
    :app); // Open the game results file

    char playAgain;

    do {

        initialize_game(); // Set up the game

        std:
        :cout << "Tic Tac Toe Game\n";

        std:
        :cout << "Do you want to play with an NPC? (y/n)
        : "; // Ask if the player wants to play against an NPC

        std:
        :cin >> playAgain;

        isPlayer2NPC = (playAgain == 'y' |
                        | playAgain == 'Y'
        ); // Set the flag for playing against NPC

        display_board(); // Show the initial game board

        while (gameover()
                ) { // Continue playing until the game is over

            if (
                    !
                            (isPlayer2NPC && turn == 'O'
                            )
                    ) { // If it's not the NPC's turn

                std:
                :cout << "Player " << turn << ", enter a number: "; // Prompt the player for a move

                std:
                :cin >> choice; // Read the player's choice

                choice--; // Adjust the choice to correspond to board index

                row = choice / 3; // Determine the row from the choice

                column = choice % 3; // Determine the column from the choice

                if (choice < 0 |
                    | choice > 8 |
                    | board[row]
                      [column] == 'X' |
                    | board[row]
                      [column] == 'O'
                        ) {

                    std:
                    :cout << "Invalid Move\n"; // If the move is invalid, notify the player

                    continue; // Skip the rest of the loop and prompt for a move again

                }

                board[row]
                [column] = turn; // Place the player's symbol on the board

            } else {

                npc_turn(); // If it's the NPC's turn, make a move

            }

            turn = (turn == 'X'
                   ) ? 'O' : 'X'; // Alternate turns

            display_board(); // Display the board after the turn

        }

        announce_winner(resultFile); // Announce the winner or a draw

        std:
        :cout << "Would you like to play again? (y/n)
        : "; // Ask if the players want to play again

        std:
        :cin >> playAgain; // Get the player's decision

    } while (playAgain == 'y' |
             | playAgain == 'Y'
            ); // Repeat if yes

    resultFile.close(); // Close the results file
