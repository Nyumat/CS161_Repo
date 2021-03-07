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
char** makeBoard(int rows, int columns);  

// Actually display the game board
void drawBoard(int rows, int columns, char** board); 

// Begin Connect Four
void start(int rows, int columns, int score, char** board, int playerCount, int turn); 

// Insert x player's move
bool executeMove(int rows, int columns, char** board, int selection, char piece); 

// Check if one of the players have won
int findWinner(int rows, int columns, char** board, int score);

// Validate user input
bool checkInput(string playerInput); 
bool validInput(string playerInput);

// Validate the Arguments given in the command line
bool checkArguments(int argc); 

// Get the two players' input
int getPlayerOneInput(int columns);
// Aka. The Computer
int getPlayerTwoInput(int columns); 

// Get the option that x player choses
int getChoice(int rows, int columns, int turn, int playerCount);

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

bool validInput(string playerInput) {

    // If there user's input is not a number
    if (!(isdigit(playerInput[0]))){
        return 0;
    }

    // We're assuming most inputs' are valid
    return 1;

}


void start(int rows, int columns, int score, int playerCount, int turn, char** board) {

    bool loss = false;
    char XorO;
    int res;

    // While one of our players (computer or humans) have not lost
    while (!(loss == true)) {

        drawBoard(rows,columns,board);

        if (turn == 0) {

            XorO = 'X';

        } else {

            XorO = 'O';

        }

    }


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

// Since we have to show the board after each move, we'll be using this void function a lot.
void drawBoard(int rows, int columns, char** board) {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j) {

            if (i % 2 == 0 && j % 2 == 0) {

                cout << "|\033[30;47m " << board[i][j] << " " << "\033[30;0m";

            } else if ( i % 2 == 1 && j % 2 == 1) {

                cout << "|\033[30;47m " << board[i][j] << " " << "\033[30;0m"; 

            } else {

                cout << "|\033[30;0m " << board[i][j] << " ";

            }

        }

        cout << "\n";

    }

}

int getPlayerOneInput(int columns) {

    string sInput;
    int iInput;

    cout << "Enter a slot to insert in between 1 and " << columns;
    cin >> sInput;

    // When the input isn't valid, or the integer version of it is less than the number of columns OR greater than the number of columns..
    while(!validInput(sInput) || (stoi(sInput) < 1 ) || (stoi(sInput) > columns)) {

        // Flag error
        cerr << ">> Error. Enter a column between 1 and " << columns << " to continue.";
        cin >> sInput;

    } 

    // If we get down here, we have to convert the entered input to a integer to return the status as per our function type.
    iInput = stoi(sInput);
    return iInput;

}

// Get the randomized computer input within the number of columns specified in the main() argument
int getPlayerTwoInput(int columns) {

    int randomInput;
    
    randomInput = (int)((rand() % (columns)) + 1);

    return randomInput;

}

// To keep track of the column selection by the computer and human or two players. 
int getChoice(int rows, int columns, int turn, int playerCount) {

    cin.clear();
    cin.ignore(1000,'\n');
    cout << endl;

    if (playerCount == 2) {

        if (turn == 0) {

            cout << "P1's Turn: " << endl;

        } else {

            cout << "P2's Turn: " << endl;

        }

        // We need the value returned by this function to update our board
        return getPlayerOneInput(columns) - 1;

    } else {

        if (turn == 0) {

            cout << "Humans turn: " << endl;
            return getPlayerOneInput(columns) - 1;

        } else {

            cout << "Computer's turn: " << endl;
            return getPlayerTwoInput(columns) - 1;

        }

    }


}


int main(int argc, char* argv[]){






}

