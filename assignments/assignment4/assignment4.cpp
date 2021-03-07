/*

        Assignment 4 Code.
        Created 100% by @Nyumat
        *EDUCATIONAL PURPOSES ONLY*

*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Function Headers

// Initializes the game board we will be using
char** makeBoard(int rows, int columns);   // initialize_board

// Actually display the game board
void drawBoard(int rows, int columns, char** board); // display_game_board

// Begin Connect Four
void start(int rows, int columns, int score, char** board, int playerCount, int turn); // start_the_game

// Insert x player's move
bool executeMove(int rows, int columns, char** board, int selection, char piece); // insert_player_piece

// Check if one of the players have won
int findWinner(int rows, int columns, char** board, int score); // checkForPlayersWin

// Validate user input
bool checkInput(string user_input); // getPlayerInput

// Validate the Arguments given in the command line
bool checkArguments(int argc);  // read_validate_args

// Get the two players' input
int getPlayerOneInput(int columns); // getPlayerInput
int getPlayerTwoInput(int columns); // getComputerInput

// Get the option that x player choses
int getChoice(int rows, int columns, int turn, int playerCount); // get_the_move

bool checkArguments(int argc){

    // Conditionals to check if the arguments were satisfied.
    if (argc > 4) {

        cerr << "You have entered more than the required arguments! " << endl;
        return 0;

    } else if (argc < 4) {

        cerr << "You have not entered enough arguments to run this program! " << endl;
        return 0;

    } else { // If they entered the correct number of arguments on the command line

        return 1;

    }

    // We don't return anything because we've accounted for all cases (will always return either true or false).

}

void start(int rows, int columns, int score, int playerCount, int turn, char** board) {

    bool loss = false;
    char XorO;


}

char** makeBoard(int rows, int columns) {

    char **board;
    // Allocate memory for our board
    board = new char*[rows];

    // We need to now allocate memory for each row
    for (int k = 0; k < rows; ++k) {

        board[k] = new char*[rows];

    }

    // Traverse through the rows & columns we created to put an empty char which will be a placeholder soon for our X's and O's

    for (int x = 0; x < rows; ++x) {

        for (int y = 0; y < columns; ++y) {

            board[x][y] = ' ';

        }

    }
    // Return the board itself so we have access to it as an object throughout the game.
    return board;
}


int main(int argc, char* argv[]){






}

