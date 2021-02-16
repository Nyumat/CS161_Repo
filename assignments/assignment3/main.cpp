#include <iostream>

#include <cstring>
#include <cstdlib>
#include <cmath>

// Use getline() for C-Style strings since it reads 254 chars

// Part A: Fractions in Lowest Terms



int lowest_terms(int &numerator, int dom) {

    if (dom == 0) {
        printf("Denominator cannot be 0\n");


    }

}

int g_c_d(int num1, int num2) {

    if (num2 != 0) {
        g_c_d(num2,num1 % num2);
    }
    return num1;
}



int main() {

    scanf(g_c_d("8,4));

    return 0;
}
