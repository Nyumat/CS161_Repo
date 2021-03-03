#include<iostream>

using namespace std;

// Print array
void print_array(int b[][3])
{

    for (int rows = 0 ; rows < 3; rows++) {


        for (int pegs = 0; pegs < 3; pegs++){

            cout << b[rows][pegs] << " ";

        }

        cout << "\n";

    }

    cout << "-------" << endl;

}


// Move function
void move(int number_of_disks,int b[][3],int from_col, int to_col)
{
    int low = 0;
    int max_d;
    for (max_d = 2 ; max_d >= 0 && b[max_d][from_col] != 0; max_d--){

        number_of_disks = max_d;

    }

    for (max_d = 2; max_d >= 0; max_d--){

        if (b[max_d][to_col] != 0){

            continue;

        } else {

            low = max_d;
            break;

        }


    }

    b[low][to_col] = b[number_of_disks][from_col];
    b[number_of_disks][from_col] = 0;

}

// Recursive function
void towers(int number_of_disks,int b[][3],int from_col,int to_col,int spare)
{


    if(number_of_disks >= 1) {



        towers(number_of_disks-1,b,from_col,spare,to_col);
        move(number_of_disks-1,b,from_col,to_col);
        print_array(b);
        towers(number_of_disks-1,b,spare,to_col,from_col);

    }
}

// Main function
int main(){

    int b[3][3];


    for (int rows = 0; rows < 3; rows++){

        for(int cols = 0;cols < 3; cols++){

            b[rows][cols] = 0;

        }
    }

    int cols = 0;

    for (int rows = 0; rows < 3;rows++){

        b[rows][cols] = rows + 1;

    }

    // First print pre solved matrix.

    print_array(b);
    // Next do recursive calls on the matrix.
    towers(3,b,0,1,2);


    return 0;

}
