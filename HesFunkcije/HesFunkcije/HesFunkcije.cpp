// HesFunkcije.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

static int Size = 128;

int metodKvadrata(unsigned int k) {
    int exponent = 0;
    int pom = Size;
    while (pom != 1) {
        pom /= 2;
        exponent++;
    }
    cout << exponent << endl;
    return k * k >> (32 - exponent);
}

int fibonacijevMetod(unsigned int k) {
    int exponent = 0;
    int pom = Size;
    while (pom != 1) {
        pom /= 2;
        exponent++;
    }
    cout << exponent << endl;
    return (k * 2654435769U) >> (32 - exponent);
}

int linearnoTrazenje(unsigned int i) {
    int alpha = Size - 1;
    while (alpha % 7 != 0 && alpha % 5 != 0 && alpha % 3 != 0 && alpha % 2 != 0)
        alpha--;
    return alpha * i;
}

int kvadratnoTrazenje(unsigned int i) {
    int alpha = Size-1;
    while (alpha % 7 != 0 && alpha % 5 != 0 && alpha % 3 != 0 && alpha % 2 != 0)
        alpha--;
    return alpha * i * i;
}


int main()
{
    cout << metodKvadrata(125645680) << endl;
    cout << fibonacijevMetod(214718974) << endl;
}
