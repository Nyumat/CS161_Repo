/*

    Assignment 3 main.cpp code. 
    Done 100% by @nyumat
    *EDUCATIONAL/REFERENCE PURPOSES ONLY*

*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define maxChar 1000
using namespace std;

char ** purge_string(const char *str);
void word_frequency(char *sentence);
void vowels_vs_consontants(char * sentence);

bool toLowestTerms(int &numerator, int &denominator){
    int x,y,remainder;

    if (denominator == 0) { // Edge case -- Undefined fraction
        return false;
    }

    x = numerator;
    y = denominator;

    while(y != 0){
        remainder = x % y;
        x = y;
        y = remainder;
    }
    numerator /= x;
    denominator /= x;

    return true;

}

void vowels_vs_consontants(char* sentence){

    int consonants = 0;
    int vowels = 0;

    // Iterate through every character in the string or until '\n'
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
    } else {
        cout << "# vowels != # consonants. " << endl;
    }

}


bool is_palindrome(char *sentence){

   purge_string(sentence);

   for (int k=0; k < strlen(sentence); k++){

       if (sentence[k] != sentence[strlen(sentence) - k - 1]) {

           return false;

       }
   }
   return true;
}
char * purge_string(char *sentence);
int count_words(char * sentence, string search);

int count_words(char *sentence, string search) {

    int freq = 0;
    int window = 0;

    for(int t = 0; t < strlen(sentence); t++){

        if (window == search.length()) {
            freq += 1;
            window = 0;
        }

        if (sentence[t] == search[window]) {
            window++;
        }

    }
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

    // Delete dynamic array off the heap.
    delete [] wordArr;

}

char *purge_string(char *sentence) {

    char *copy = new char[1024];
    int counter = 0;
    int x = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {

        if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')){

            copy[x] = sentence[i];
            counter += 1;
            x += 1;

        }

    }
    copy[counter] = '\0';
    return copy;

}

int main(){
    
    int num,dom;
    int operation_choice;


    cout << "Enter your numerator: \n";
    cin >> num;
    cout << "Enter your denominator \n";
    cin >> dom;
    toLowestTerms(num,dom);
    printf("Your fraction in lowest terms: %d/%d\n\n", num,dom);


    char sentence[1024];
    cout << "Enter a sentence or paragraph: ";
    cin.ignore();
    cin.getline(sentence,1024);
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
        cout << "2";
    } else if (operation_choice == 3) {
        cout << "3";
    } else if (operation_choice == 4) {
        word_frequency(sentence);
    } else if (operation_choice == 0) {
        return 0;
    } else {
        cout << "Invalid entry. Try again. \n";
    }


    return 0;
}
