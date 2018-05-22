#include <iostream>
#include "RomanToInt.h"
#include <string>
#include <locale>

using namespace std;

/*
Checks to see if a string contains roman numerals only.
Returns a number greater than 0 if all characters are roman, 
else returns -1 if a character is not roman.
*/
int RomanToInt::isRoman(string & s) {
	int charIsRoman = 0; // increments if character is roman

	// check to see if each character is contained in the cRoman array.
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] == cRoman[0] || s[i] == cRoman[1]) || (s[i] == cRoman[2] ||
			s[i] == cRoman[3]) || (s[i] == cRoman[4] ||
			s[i] == cRoman[5]) || s[i] == cRoman[6]) 
			charIsRoman++;
		else 
			return -1; // return -1 if 
	}
	return charIsRoman;
}

/*
Converts a Roman numeral to the equivalent integer. Returns -1 if
the conversion is not successful.
*/
int RomanToInt::toInt(string & s) const {
	int i = 0, sum = 0, previous = 0;

	while (i < s.length()) {
		switch (s[i]) {

			// starting from highest to lowest because of how roman numerals
			// are defined, we increment sum by the roman numeral and set the previous 
			// the roman numeral to be used for the next case.
		case 'M':
			sum += 1000;

			if (previous < 1000) // if the prvious is smaller, apply roman rules to sum
				sum -= 2 * previous; // applying the roman rules to the sum

			previous = 1000; 
			break;
		case 'D':
			sum += 500;

			if (previous < 500)
				sum -= 2 * previous;

			previous = 500;
			break;
		case 'C':
			sum += 100;

			if (previous < 100)
				sum -= 2 * previous;

			previous = 100;
			break;
		case 'L':
			sum += 50;

			if (previous < 50)
				sum -= 2 * previous;

			previous = 50;
			break;
		case 'X':
			sum += 10;

			if (previous < 10)
				sum -= 2 * previous;

			previous = 10;
			break;
		case 'V':
			sum += 5;

			if (previous < 5)
				sum -= 2 * previous; 

			previous = 5;
			break;
		case 'I':
			sum += 1;

			if (previous < 1)
				sum -= 2 * previous;

			previous = 1;
			break;
		default: // if none of the other cases fire, there is a character thats invalid
			cout << s[i] << " is not a Roman Numeral!" << endl; // print the character thats in valid
			sum = 0;
			return -1;
		}
		i++; // increment the loop control variable
	}
	return sum;
}




