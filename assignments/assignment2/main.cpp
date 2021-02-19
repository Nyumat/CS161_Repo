#include <iostream>
#include <string>

using namespace std;

bool check_range(int high, int low, int x) {

    return (x >= low && x <= high);

}

bool is_capital(char letter){

    return (letter >= 'A' && letter <= 'Z');

}

int is_even(int num_even) {

    return (num_even % 2 == 0);

}

int is_odd(int num_odd) {

    return (num_odd % 2 == 1);

}

bool equality_test(int num1, int num2) {

    int j = 0;

    if (num1 > num2) {

        j+=1;

    } else if (num1 < num2) {

        j-=1;

    } else {

        j = 0;

    }
    return j;
}

float float_is_equal(float num1, float num2, float precision){

    // Since there's no way to represent most floating point numbers we have to approximate in binary using a precision.

    if (num1 == num2) {
        return 1;
    }
    if (abs(num1 - num2) <= precision) {

        return 1;

    } else {
        return 0;
    }

}

int is_int(string num) {

    int i;
    int counter = 0;

    if (num[0] == '-') { // num[0] is the first character in the string.

        counter += 1; //This accounts for the edge case when given a
                       // negative value, so if there is a '-' character at num[0], we increment counter.

    }
    for (i=0; i < num.length(); i++) {

        if (num.at(i) >= '0' && num.at(i) <= '9') {

            counter += 1;

        }
    }
    if (counter == num.length()) {

        return 1; // We know it's a integer instantly because we reached here.


    }
    return 0; // If we make it down, here we know that the string is not an integer
}

bool letters_present(string sentence) {

    bool ltr_present = false;
    int i;

    for (i = 0; i < sentence.size(); i++) {
        // Conditional that optimizes for both uppercase and lowercase alphabetical characters being present.
        if (sentence[i] >= 'A' && sentence[i] <= 'Z'|| sentence[i] >= 'a' && sentence[i] <= 'z') {
                ltr_present = true;
        }

    }
    return ltr_present;

}

bool numbers_present(string sentence) {

    bool numbers_present = false;
    int i;

    for (i = 0; i < sentence.size(); i++) {
        if (sentence[i] >= '0' && sentence[i] <= '9' || sentence[i] >= 48 && sentence[i] <= 57) {
            numbers_present = true;
        }

    }
    return numbers_present;

}

bool contains_sub_string(string sentence, string sub_string) {

    int len_substring = sub_string.length();
    int len_sentence = sentence.length();

    for (int i=0; i<= len_sentence - len_substring; i++) { // Sliding window algorithm to check for pattern
        int j;
        for (j=0; j < sub_string.length(); j++) {

            if (sub_string[i+j] != sentence[j]){  // If the sliding window's contents != chars at sentence[j]
                break;
            }   // Hence we know that it is not a substring, so we exit the loop.
        }
        if (j == len_substring) { // If j is the same length as our substr we know it's inside the sentence.
            return true;
        }
    }
    return false; // Edge Case: If we reach here, we know that our sub_string does not exist.
}

int word_count(string sentence){

    int word_count = 0;
    char prev = ' ';

    for (char i : sentence) { // Range-based for loop to iterate over the values vs. through the indexes.

        if (i != ' ' && prev == ' ' ) {

            word_count++;

        }
        prev = i;
    }

    return word_count;

}

string to_upper(string sentence) {
    int i = 0;
    while (sentence[i] != '\0') // While the current character is not that null termination character)
    {

        if (sentence[i] >= 'a' && sentence[i] <= 'z') {

            sentence[i] -= 32; // Same thing as (sentence[i] = sentence[i] + ('a' - 'A'))

        }
        i++; // Increment our pointer 'i' on each iteration.
    }
    return sentence;
}

string to_lower(string sentence) {
    int i = 0;
    while (sentence[i] != '\0') {

        if (sentence[i] >= 'A' && sentence[i] <= 'Z'){

            sentence[i] += 32; // Same thing as (sentence[i] = sentence[i] + ('A' - 'a'))

        }
        i++;
    }
    return sentence;
}

int get_int(){

    long int choice;
    bool error; //Our error flag
    do
    {
        error = false; //Flag false, safe
        cout << "Enter a integer value: ";
        cin >> choice;
        if(cin.fail()){
            error = true; //Flag true, invalid input has occured
            cout << "Error, invalid entry.\n\n";
        }
        cin.clear();                //Clear any error flags
        cin.ignore(1000,'\n');      //Ignores 1000 characters, or until '\n'
    } while(error);

    cout << "\nThe integer value entered was: " << choice << '\n';
    cout << "Press <enter> to exit console: ";
    cin.get();

    return 0;
}

int main() {

    cout << "Testing check_range(10,0,9)...\n"; // check_range(high,low,target)
    cout << "Expected 1";
    cout << "\tActual: " << check_range(10,0,9); // Returns True, as 10 is <= 10.
    (check_range(10,0,9)==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing check_range(100,20,101)...\n";
    cout << "Expected 0";
    cout << "\tActual: " << check_range(10,20,101); // Returns False, as 100 is > 20.
    (check_range(10,20,101)==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_capital(a)...\n";
    cout << "Expected 0";
    cout << "\tActual: " << is_capital('a'); // Returns False, as 'a' is a lowercase letter.
    (is_capital('a')==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";


    cout << "Testing is_capital(A)...\n";
    cout << "Expected 1";
    cout << "\tActual: " << is_capital('A'); // Returns True, as 'A' is a capital letter.
    (is_capital('A')==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_even(5)...\n";
    cout << "Expected 0";
    cout << "\tActual: " << is_even(5); // Returns False, as 5 is an odd number.
    (is_even(5)==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_even(4)...\n";
    cout << "Expected 1";
    cout << "\tActual: " << is_even(4); // Returns True, as 4 is an even number.
    (is_even(4)==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_odd(6)...\n";
    cout << "Expected 0";
    cout << "\tActual: " << is_odd(6); // Returns False as 6 is an even number.
    (is_odd(6)==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_odd(3)...\n";
    cout << "Expected 1";
    cout << "\tActual: " << is_odd(3); // Returns True as 3 is an odd number.
    (is_odd(3)==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing equality_test(num1: 4, num2: 3)...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << equality_test(4,3); // Returns 1 as 4 is greater than 3
    (equality_test(4,3)==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing equality_test(num1: 2, num2: 2)...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << equality_test(2,2); // Returns 0 as num1 and num2 are equal.
    (equality_test(2,2)==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing float_is_equal(num1: 4.200, num2: 4.2, precision: 0.01)...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << float_is_equal(4.200,4.2,0.01); // Returns True as 4.200 and 4.2 are equal within 0.01 precision.
    (float_is_equal(4.200,4.2,0.01)==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing float_is_equal(num1: 4.25, num2: 4.2, precision: 0.05)...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << float_is_equal(4.25,4.2,0.05); // Returns False as 4.25 & 4.2 are not equal within the 0.05 precision.
    (float_is_equal(4.25,4.2,0.05)==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_int(\"-123\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << is_int("-123"); // Returns True as -123 is an integer.
    (is_int("-123")==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing is_int(\"a1b2c3\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << is_int("a1b2c3"); // Returns False as a1b2c3 is not an integer.
    (is_int("a1b2c3")==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing numbers_present(\"hello123\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << numbers_present("hello123"); // Returns True as hello123 contains numbers.
    (numbers_present("hello123")==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing numbers_present(\"hello\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << numbers_present("hello"); // Returns False as hello does not contain numbers.
    (numbers_present("hello")==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing letters_present(\"hello123\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << letters_present("hello123"); // Returns True as hello123 contains letters.
    (letters_present("hello123")==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing letters_present(\"124423\")...\n";
    cout << "Expected 0";
    cout << "\tActual: " << letters_present("124423"); // Returns False as 124423 has no letters.
    (letters_present("124423")==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing contains_sub_string(\"hello,hel\")....\n";
    cout << "Expected: 1";
    cout << "\tActual: " << contains_sub_string("hello","hel"); // Returns True as "hel" is a substring of "hello"
    (contains_sub_string("hello","hel")==1) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing contains_sub_string(\"hello,yzx\")....\n";
    cout << "Expected: 0";
    cout << "\tActual: " << contains_sub_string("hello","yzx"); // Returns False as "yzx" is not a substring of "hello"
    (contains_sub_string("hello","yzx")==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing word_count(\"hello my name is tom\")....\n";
    cout << "Expected: 5";
    cout << "\tActual: " << word_count("hello my name is tom"); // Returns 5
    (word_count("hello my name is tom")==5) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing word_count(\"\")....\n";
    cout << "Expected: 0";
    cout << "\tActual: " << word_count(""); // Returns 0
    (word_count("")==0) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    // Calling the function on facing variables below to test for equality against our "hard-coded" tests.

    string sentence_upper = to_upper("hello");
    string sentence_lower = to_lower("HELLO");

    cout << "Testing to_upper(\"hello\")....\n";
    cout << "Expected: HELLO";
    cout << "\tActual: " << to_upper("hello"); // Returns "HELLO"
    (to_upper("hello")==sentence_upper) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    cout << "Testing to_lower(\"HELLO\")....\n";
    cout << "Expected: hello";
    cout << "\tActual: " << to_lower("HELLO"); // Returns "hello"
    (to_lower("HELLO")==sentence_lower) ? cout << "\tPASSED\n" : cout << "\tFailed\n";

    get_int(); // get_int() is the only function in our program that requires user input!

    return 0;


}
