/*
        Assignment 4 Code.
        Created 100% by @Nyumat
        *EDUCATIONAL PURPOSES ONLY*
*/

#include <iostream>
#include <string>



using namespace std;

// Initializes the game board we will be using
char** makeBoard(int rows, int columns);

// Actually display the game board
void drawBoard(int rows, int columns, char** board);

// Begin Connect Four
void start(int rows, int columns, int connectX, int playerCount, int turn, char** board);

// Insert player x's move
bool executeMove(int rows, int columns, int selection, char piece, char** board);

// Check if any of the players have won
int findWinner(int rows, int columns, int connectX, char** board);

// Validate user input
bool validInput(string playerInput);

// Validate the Arguments given in the command line
bool checkArguments(int argc);

// Get the two players' input
int getPlayerOneInput(int columns);
// Aka. The Computer
int getPlayerTwoInput(int columns);

// Get the option that player x chooses
int getChoice(int rows, int columns, int turn, int playerCount);

bool checkArguments(int argc){

    // Conditionals to check if the arguments were satisfied.
    if (argc > 4) {

        cerr << "You have entered more than the required arguments! " << endl;
        return false;

    } else if (argc < 4) {

        cerr << "You have not entered enough arguments to run this program! " << endl;
        return false;

    } else { // If they entered the correct number of arguments on the command line

        return true;

    }

    /*
        We don't have to include a default because we've accounted for all cases (will always return either true or false).
    */
}

bool validInput(string playerInput) {

    // If there user's input is not a number
    if (!(isdigit(playerInput[0]))){
        return false;
    }

    // If we make it down here--it is a number, return true/1
    return true;

}

// Updates the board and checks the game status on each call
void start(int rows, int columns, int connectX, int playerCount, int turn, char** board) {

    bool loss = false;
    char XorO;
    int someoneWon;

    // While one of our players (computer or humans) have not lost
    while (!loss) {

        drawBoard(rows,columns,board);

        if (turn == 0) {

            XorO = 'X';

        } else {

            XorO = 'O';

        }

        while (!executeMove(rows,columns,getChoice(rows,columns,turn,playerCount),XorO,board));

        turn ^= 1;

        if ((someoneWon = findWinner(rows,columns,connectX,board))) {

            drawBoard(rows,columns,board);

            // Tie Case
            if (someoneWon == -1) {

                cout << "Tie." << endl;

            }

            else if (turn == 0) {

                if (playerCount == 1)
                    cout << "The CPU has Won! " << endl;
                else
                    cout << "Player 2 has Won! " << endl;


            }

            else {
                cout << "Player 1 has Won! " << endl;
            }

            loss = true;

        }

    }


}




int findWinner(int rows, int columns, int connectX, char** board) {

    bool connectFour;
    char XorO;
    int currConnected;
    int i,j;
    bool tie = true;

    for (i = 0; i < columns; i++) {

        // If the current column in our iteration has an empty slot a tie cannot occur.
        if (board[0][i] == ' ') {

            tie = false;

        }

    }
    // If there is a tie we must return -1 and prompt the user(s) to play again.
    if (tie) {
        return -1;
    }

    for (i = 0; i < rows; i++) {

        for (j = 0; j < columns; j++) {

            // Our piece to insert (X or O) needs to be intialized to a variable on the i'th row and j'th column
            XorO = board[i][j];

            // If we see an empty space in our row/column traversal we simply continue the loop because that is an open slot.
            if (XorO == ' ') {
                continue;
            }

            // Flag true after every win condition check because we return 0 at the end of our function.
            connectFour = true;

            // Check the j'th column for connect four
            if (j <= columns - connectX) {

                for (currConnected = 1; currConnected < connectX; currConnected++) {

                    if (board[i][j + currConnected] != XorO) {

                        connectFour = false;

                    }

                }

                if (connectFour) {
                    return 1;
                }

            }

            // Check for both the i'th row and j'th column for connect four
            if (i <= rows - connectX && j < columns) {

                for (currConnected = 1; currConnected < connectX; currConnected++) {

                    if (board[i + currConnected][j] != XorO) {

                        connectFour = true;

                    }

                }

                return connectFour;

            }

            connectFour = true;
            // Check along a diagonal row and column space for connect four
            if (i >= connectX - 1 && j <= columns - connectX) {

                for (currConnected = 1; currConnected < connectX; currConnected++) {

                    if (board[i - connectX][j + currConnected] != XorO) {
                        connectFour = false;
                    }

                }

                // If at this point it is true, we found a connect four along the diagonal
                if (connectFour) {
                    return 1;
                }

            }

            connectFour = true;
            // Check the opposite diagonal row and column space for connect four
            if (i <= rows - connectX && j <= columns - connectX) {

                for (currConnected = 1; currConnected < connectX; currConnected++) {

                    if (board[i + currConnected][j + currConnected] != XorO) {

                        connectFour = false;

                    }

                }
                // If our connectFour is true at this point, that means we found a diagonal connect four on the mirror slope.
                if (connectFour) {
                    return 1;
                }

            }


        }

    }

    // We return 0 at the end of this function because this function's goal is to find out if we have a winner after each move in our connect four.
    return 0;

}

char** makeBoard(int rows, int columns) {

    // Declare our board object
    char **board;
    // Allocate memory for our board
    board = new char*[rows];

    // We need to now allocate memory for each row
    for (int k = 0; k < rows; ++k) {

        board[k] = new char[columns];

    }

    // Traverse through the rows & columns we created to put an empty char which will be a placeholder for our X's and O's
    for (int x = 0; x < rows; ++x) {

        for (int y = 0; y < columns; ++y) {

            board[x][y] = ' ';

        }

    }
    // Return the board itself so we have access to it as an object throughout the game.
    return board;
}

// Since we have to show the board after each move, we'll be using this void function a lot.
// This code was given in the instructions of the assignment.

void drawBoard(int rows, int columns, char** board) {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j){

            if (i % 2 == 0 && j % 2 == 0)

                cout << "|\033[30;47m " << board[i][j] << " ";

            else if (i % 2 == 1 && j % 2 == 1)

                cout << "|\033[30;47m " << board[i][j] << " ";

            else

                cout << "|\033[0m " << board[i][j] << " ";
            cout << "\033[0m";


        }

        cout << "\n";

    }

}


bool executeMove(int rows, int columns, int selection, char piece, char** board) {

    // If the board's column is an X or O we can return 0 to know that the move can't be executed.
    if (board[0][selection] == 'O' || board[0][selection] == 'X') {

        return 0;

    }

    // Initialize local current piece and pointer to the row we're on.
    int ptr = rows - 1;
    char curr = board[ptr][selection];


    // Loop while there is a piece that can be inserted on the current column
    while (((curr == 'O') || (curr == 'X' )) && (ptr > -1)) {

        // Decrement the row
        ptr -= 1;
        // Then update the current piece
        curr = board[ptr][selection];

    }

    // Act of 'placing' the piece into the row we're pointing to and the column selection
    board[ptr][selection] = piece;
    // Return true to signal the move has occured
    return 1;

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


// Main will pass in our arguments and use them to set up our board and game loop.
int main(int argc, char* argv[]){

    int rows,columns,playerCount;
    int connectX = 4;
    int turn = 0;
    char **board, playerVsCPU;
    char toContinue = 'n';
    // srand() call for our CPU random choice.
    srand(time(nullptr));


    if (checkArguments(argc)) {

        playerCount = atoi(argv[1]);

        rows = atoi(argv[2]);

        while (rows > 20) {

            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Board dimensions must be positive and less than 20. \n";
            cout << "Enter the row length for the board: ";
            cin >> rows;

        }

        columns = atoi(argv[3]);

        while (columns > 20) {

            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Board dimensions must be positive and less than 20. \n";
            cout << "Enter the column length for the board: ";
            cin >> columns;

        }


    } else {

        cout << "Number of players [1 or 2]: ";
        cin >> playerCount;

        do {
            cout << "Enter the desired row length: ";
            cin >> rows;
        } while (rows > 20);

        do {
            cout << "Enter the desired column width: ";
            cin >> columns;
        } while (columns > 20);

    }

    do {



        board = makeBoard(rows,columns);

        if (playerCount == 1) {

            cout << "Player vs Computer " << endl;
            cout << ">> Enter a key to make the computer move first. ";
            cin.get();
            cin.ignore(1000,'\n');

            if (playerVsCPU == 'y' || playerVsCPU == 'Y') {
                turn = 0;
            } else {
                turn = 1;
            }

        } else {
            cout << "Player One vs Player Two " << endl;
        }

        start(rows,columns,connectX,playerCount,turn,board);

        cout << ">> Would you like to play again? \n";
        cout << ">> Type 'y' or 'Y' to continue..or any key to quit: ";
        cin >> toContinue;
        turn ^= 1;

    } while (toContinue == 'y' || toContinue == 'Y');

    for (int f = 0; f < rows; ++f) {

        delete board[f];

    }

    delete [] board;
    cout << "Thanks for playing..." << endl;
    exit(0);


}
