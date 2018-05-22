/*
IntToRoman.h
Author: Anthony Jaghab
*/

#pragma once
#include <iostream>

using namespace std;

class IntToRoman {

private:

public:
	string toRoman(int i) const; // converts a number to roman numerals
	char iRoman[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' }; // integer to roman
};