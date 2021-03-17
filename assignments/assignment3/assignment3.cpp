#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>


using namespace std;

char * purge_string(const char *str);
void words_frequency(char *sentence);

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

    printf("Your fraction in lowest terms: %d/%d\n\n", numerator,denominator);
    return true;

}

bool is_palindrome(char *str);

void purge_stringg(char *str){

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[j] = str[i] - 'A' + 'a';
            j++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';

}

char* purge_string(char *sentence){

    char *copy = new char[1024];
    int counter = 0;
    int x = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {

        if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')){

            copy[x] = sentence[i];
            x += 1;
            counter += 1;

        }

    }
    copy[counter] = '\0';
    return copy;

}

void word_frequency(char *sentence) {

    int n;
    cout << "How many words would you like to search for? \n";
    cin >> n;
    char *words = new char[n];

    cout << "Enter " <<  n << "words to search for " << endl;
    for (int i=0; i<n;i++){
        words[i] = i + 1;
        scanf("%s",&words[i]);

    }
    cout << *words;

    delete [] words;


}

int main(){
    int num,dom;
    int route = 1;
    int operation_choice = 0;
    char * sentence[1024];
    bool again;

    do {
        cout << "Enter your numerator: \n";
        cin >> num;
        cout << "Enter your denominator \n";
        cin >> dom;
        toLowestTerms(num,dom);
        cout << "Would you like to do another conversion? (0-no,quit , 1-yes,another)\n";
        cin >> again;

    } while(again == 1);


    cout << "Entering Part B...\n";
    again = false;

    printf("Enter a sentence");
    cin.get(sentence);


    cout << " Choose an operation to perform on your input or quit\n";
    cout << "--------------Choices-----------\n";
    cout << "1: (Suggested) Purge String. \n";
    cout << "2: Vowels vs Consonants \n";
    cout << "3: Palindrome Detector \n";
    cout << "4: Word Frequency \n";
    cout << "0: Quit \n";

    cin >> operation_choice;


    if (operation_choice == 1) {
        cout << purge_string(sentence) << endl;
        purge_stringg(sentence);
        cout << sentence << endl;
    } else if (operation_choice == 2) {

        word_frequency(sentence);

    }

    return 0;
}
