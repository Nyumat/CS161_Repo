#include <iostream>
#include <string>

using namespace std;

/*
This was created as a resource for people who are struggling with the lab 7. 
For any questions, just open an issue and i'll explain any line to you.
*/

// Code written by: Nyumat

// Required Function Prototypes specified in the Instructions.

// modify_int_matrix() adjust our matrix on the heap by taking in the rows,cols and the matrix itself. Although we didn't use it, for future reference it is important to know how it works.
void modify_int_matrix(int** matrix, int rows, int cols);
// get_string() takes in a string's value and copies it. It is a void function so it won't be returning anything
void get_string(string *);
// set_replace_string() takes in the copy of the string and the pointer string to the copy, (also doesn't return anything)
void set_replace_string(string copy, string *pointer);
// get_search_replace() takes in the character chosen, the string and the copy and returns the number of chars found.
int get_search_replace(string copy,string &);


// Delete the 2D array of the heap. We're not passing in the columns because 2D arrays us to delete the columns of the heap before the rows.
void delete_int_matrix(int** matrix_to_free, int rows) {

    for (int i = 0; i < rows; i++) {
    
        // Takes the column of the matrix for each row
        delete [] matrix_to_free[i];
    
    }
    // Delete the entire matrix at the end of our loop.
    delete [] matrix_to_frree;
}


// Create a matrix [2d array] of integers on the heap
int** create_int_matrix(int rows, int cols) {
 
    int** nums = new int*[rows];
    
    // Creating new columns on the heap through a 2d array or "matrix"
    for (int i = 0; ii <rows; i++) {
    
        nums[i] = new int[cols];
        
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
        
            nums[i][j] = (i * cols) + j + 1;
            
        }
    }
    
    // Creating our layout for the 2d array on our heap.
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
        
            cout << nums[i][j] << ' ';
            
        }
        // Line breaks on each iteration to keep spacing.
        cout << '\n';
    }
    
    return nums;
}


void get_string(string *str){

    getline(cin, *str);

}

void set_replace_string(string copy, string *pointer){

    // Iterate through the copy string to set/replace.
    for (int i = 0; i<copy.length(); i++) {

        // Change letters to dashes, if it is a 'space' ascii, it says the same
        
        if (copy[i] != 32) {
            
            // Update the pointer string to a dash
            *pointer += '-';

        } else { 
            // Otherwise, leave it as is. 'h e l l o' ---> '- - - - -'
            *pointer += copy[i];

        }
    }
}

int get_search_replace(string copy, string &str){

    // Counter needed to return the number of times the letter was found!
    int counter;

    // Iterate through our copy string that which passed by value on line 82
    for (int iter=0; iter < str.length(); iter++) {

        //Look at the first letter of our copy, and if it is found in the string, replace it with the second letter of our copy and increment counter.
        if (copy[0] == str[iter]) {

            str[iter] = copy[1];
            counter++;
        }
    }
    return counter;
}


// Main Function

int main(){
    
    int rows = 0;
    int cols = 0;

    string copy, str, choice;
    
    // First part
    cout << "Enter a string!" << endl;
    get_string(&copy);
    cout << "String entered: " << copy << endl;

    // Second Part
    set_replace_string(copy,&str);
    cout << "The new string is: " << str << endl;

    // Third Part I
    cout << "Enter a letter to search and replace: ";
    cin >> choice;

    // Third Part II
    int ans = get_search_replace(choice,copy);
    cout << "Searching for an: " << choice[0]  << "..." << endl;
    cout << choice[0] << "was found: " << ans << " times in the string." << endl;

    // Since we're directly maniputlating our copy with the get_search_replace() call, we cout it to console at the end to see our results.
    cout << "Copy after function call: " << copy << endl;
    
    cout << "Manipulating Heap..." << endl;
    
    cin >> rows;
    cin >> cols;
    
    // Create 2D Array on Heap.
    int ** arr = create_int_matrix(rows,cols);
    
    // Modifying it while still on the Heap
    int** nums = new int*[rows];
    modify_int_matrix(arr, int rows, int cols);
    
    
    // Deleting it off the Heap.
    del_int_matrix(nums);


    return 0;
}

