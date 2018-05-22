#include <iostream>
#include "IntToRoman.h"
#include <string>

using namespace std;

/*
Converts an integer to the equivalent roman numeral.
*/
string IntToRoman::toRoman(int input) const {
	string roman = ""; // roman numeral to return
	int m, d, c, l, x, v, i, sum; // all roman numerals, and sum.
	
	// uses modulus to count how many numerals you need.
	m = input / 1000; // represents how many 'M' are in the input and etc.
	d = ((input % 1000) / 500);
	c = ((input % 500) / 100);
	l = ((input % 100) / 50);
	x = ((input % 50) / 10);
	v = ((input % 10) / 5);
	i = (input % 5);

	// number of roman numeral characters to print
	sum = m + d + c + l + x + v + i;
	
	while (sum > 0) {

		// print each roman numeral for each one.
		if (m > 0) {
			roman += "M"; // print the character
			m--; // decrement the respective character
			sum--; // decrement the summation of all the roman numerals needed for input
		}

		else if (d > 0) {
			roman += "D";
			d--;
			sum--;
		}
		else if (c > 0) {
			roman += "C";
			c--;
			sum--;
		}
		else if (l > 0) {
			roman += "L";
			l--;
			sum--;
		}
		else if (x > 0) {
			roman += "X";
			x--;
			sum--;
		}
		else if (v > 0) {
			roman += "V";
			v--;
			sum--;
		}
		else if (i > 0) {
			roman += "I";
			input--;
			sum--;
		}
	}
	return roman;
}

