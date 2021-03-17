/*

    Assignment 3 main.cpp code. 
    Done 100% by @nyumat
    *EDUCATIONAL PURPOSES ONLY*

*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


// Function Headers.
bool toLowestTerms(int &numerator, int &denominator);
char *purge_string(const char *sentence);
void vowelsCon(const char *sentence);
bool is_palindrome(char *sentence);
void word_frequency(char *sentence);
int count_words(char * sentence, string search);


bool is_palindrome(char *sentence){

    purge_string(sentence);

    for (int k = 0; k < strlen(sentence); k++) {
        if (sentence[k] != sentence[strlen(sentence)-k-1]){
            k += 1;
            return false;
        }

    }
    return true;
}


int count_words(char *sentence, string search) {

    int freq = 0;
    int window = 0;

    // Growing Window Algorithm

    for(int t = 0; t < strlen(sentence); t++){
        // If the size of the window is equal to the length of the word we're searching for
        // Increment the frequency and shrink the window back to 0.
        if (window == search.length()) {
            freq += 1;
            window = 0;
        }
        // Grow our window if there is a match.
        if (sentence[t] == search[window]) {
            window++;
        }

    }
    // Return the # of times the word was found.
    return freq;
}


void word_frequency(char *sentence) {

    int N;

    cout << "The number words do you want to look for: ";
    cin >> N;

    // Declare our heap string array.
    auto* wordArr = new string[N];

    // Dynamically add words to the array we just declared on the heap.
    for (int i = 0; i < N; i++) {
        cin.ignore();
        cout << "New word: ";
        cin >> wordArr[i];
    }
    // For each word that the user enters we have to find the # of times it's inside of the sentence.
    for (int i = 0; i < N; i++) {

        cout << wordArr[i] << ":" << count_words(sentence,wordArr[i]) << endl;

    }

    // Free our allocated memory.
    delete [] wordArr;

}


char *purge_string(const char *sentence) {

    char *copy = new char[1024];
    int counter = 0;
    int x = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        
        // Only add letters of the alphabet to the copy.
        if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {

            copy[x] = sentence[i];
            counter += 1;
            x += 1;

        }

    }
    copy[counter] = '\0';

    return copy;

}

bool toLowestTerms(int &numerator, int &denominator) {
    int x,y,remainder;

    if (denominator == 0) { // Edge case -- Undefined fraction
        return false;
    }

    if (numerator == 0) { // Base Case. We need to exit somehow!
        cout << "\n The lowest terms of your fraction: " << 0 << endl;
    }

    x = numerator;
    y = denominator;

    while(y != 0){ //
        remainder = x % y;
        x = y;
        y = remainder;
    }
    numerator /= x;
    denominator /= x;
    // Return true so we can check status for input error handling.
    return true;

}

void vowelsCon(const char *sentence) {

    int consonants = 0;
    int vowels = 0;

    // Iterate through every character in the string or until '\0'
    for (int i = 0; sentence[i] != '\0'; i++) {

        char sentenceChar = sentence[i];

        if ((sentenceChar >= 'a' && sentenceChar <= 'z') || (sentenceChar >= 'A' && sentenceChar <= 'Z')) {
            if (sentenceChar == 'a' || sentenceChar == 'e' || sentenceChar == 'i' || sentenceChar == 'o' || sentenceChar == 'u' ||
                sentenceChar == 'A' || sentenceChar == 'E' || sentenceChar == 'I' || sentenceChar == 'O' || sentenceChar == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    if (vowels == consonants) {
        cout << "# vowels = # consonants. " << endl;
    } else if (vowels != consonants) {
        cout << "# vowels != # consonants. " << endl;
    } else {
        cout << "No vowels or consonants. " << endl;
    }

}

int main(){
    
    int num = 0, dom = 0;
    int operation_choice;
    bool partA_Again;
    bool partB_Again;
    // bool isPositive = ((num < 0 && dom < 0) || (num > 0 && dom > 0));

    do {

        cin.clear();
        cout << "Enter your numerator: \n";
        cin >> num;
        cout << "Enter your denominator \n";
        cin >> dom;
        while (!toLowestTerms(num, dom)) {
            cout << "Invalid input, denominator cannot be 0!" << endl;
            cout << "Enter a denominator again: ";
            cin >> dom;
        }
        toLowestTerms(num, dom);
        printf("Your fraction in lowest terms: %d/%d\n\n", num, dom);
        cout << "Would you like to go again or quit? (0-Quit) (1-Again): ";
        cin >> partA_Again;

    } while (partA_Again);

    do {

        char sentence[1024];
        cout << "Enter a sentence or paragraph: ";
        cin.ignore();
        cin.getline(sentence, 1024);
        cout << endl;

        cout << " Choose an operation to perform on your input or quit\n";
        cout << "--------------Choices-----------\n";
        cout << "1: (Suggested) Purge String. \n";
        cout << "2: Vowels vs Consonants \n";
        cout << "3: Palindrome Detector \n";
        cout << "4: Word Frequency \n";
        cout << "0: Quit \n";

        cin.clear();

        cin >> operation_choice;

        if (operation_choice == 1) {
            cout << purge_string(sentence) << endl;
        } else if (operation_choice == 2) {
            vowelsCon(sentence);
        } else if (operation_choice == 3) {
            purge_string(sentence);
            if (is_palindrome(sentence)==0){
                cout << sentence << " is not a palindrome.\n";
            } else if (is_palindrome(sentence)==1) {
                cout << sentence << " is a palindrome\n";
            }
        } else if (operation_choice == 4) {
            word_frequency(sentence);
        } else if (operation_choice == 0) {
            return 0;
        } else {
            cout << "Invalid entry. Try again. \n";
        }

        cout << "Would you like to go again or quit? (0-Quit) (1-Again): ";
        cin >> partB_Again;


    } while (partB_Again);

    return 0;
}
