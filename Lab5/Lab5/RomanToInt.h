/*
RomanToInt.h
Author: Anthony Jaghab
*/
#pragma once
#include <iostream>

using namespace std;

class RomanToInt {

private:

public:
	int isRoman(string &s); // check if a string contains only roman numerals
	int toInt(string &s) const; // roman to integer
	char cRoman[7] =  {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; // char array storing all roman numerals.
};
