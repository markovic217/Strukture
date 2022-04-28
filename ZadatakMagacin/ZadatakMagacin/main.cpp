#include "Stack.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
double calcPrefix(char* inStr) {
	Stack s(strlen(inStr));
	double rez = 0;
	int a, b;
	for (int i = strlen(inStr) - 1; i >= 0; i--) {
		if (isdigit(inStr[i])) {
			s.push(inStr[i] -'0');
		}
		else {
			a = s.pop();
			b = s.pop();
			switch (inStr[i]) {
			case '+': rez = a + b; break;
			case '-': rez = a - b; break;
			case '/': rez = a / b; break;
			case '*': rez = a * b; break;
			default:break;
			}
			s.push(rez);
		}
	}
	return rez;
}

void main()
{
	double rez = calcPrefix("**+3/35-934");
	std::cout << rez;
}