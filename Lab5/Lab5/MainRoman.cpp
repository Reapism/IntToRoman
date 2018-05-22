/*
Anthony Jaghab
Lab 5: Roman Numeral Converter. 
*/

#include <iostream>
#include "RomanToInt.h"
#include "IntToRoman.h"
#include <windows.h> // used to interact with the coordinates.
#include <string>

using namespace std;


// prototypes for the methods
void menu();
void gotoxy(int, int);
void romanToIntMenu();
void intToRomanMenu();

COORD c = {0,0}; // coord variable to change the coords

/*
Go to the x, y coordinate on the console.
Code reused from BCS120.
*/
void gotoxy(int x, int y) { 
	c.X = x; 
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


/*
Menu for integer to roman. Prints the output of the integer to roman conversion.
*/
void intToRomanMenu() {
	system("Color 80");
	system("CLS");
	cout << "Integer to roman converter:\n\n";

	int i;
	cout << "Please enter your number to convert: ";
	cin >> i;

	IntToRoman ir;
	
	while (i < 1) {
		cout << "\nInvalid number, please enter a whole number > 0. Please reenter: ";
		cin >> i;
	}
	cout << i << " converts to " << ir.toRoman(i) << endl;
	system("\npause"); 
	menu(); // go back to menu
}

/*
Menu for roman to integer. Prints the output of the roman to integer conversion.
*/
void romanToIntMenu() {
	system("Color 80");
	system("CLS");
	cout << "Roman to integer converter:\n\n";

	string s;
	cout << "Please enter your roman numeral(s): ";
	cin >> s;

	RomanToInt ri;
	while (ri.isRoman(s) == -1) {
		cout << "The following string is invalid. Please enter: \n";
		cin >> s;
		if (s == "-1")
			menu();
	}
	cout << s << " converts to " << ri.toInt(s) << endl;
	system("\npause");
	menu(); // go back to menu
}

/*
Displays a magical menu from where a user can select either RomanToInt or IntToRoman.
*/
void menu() {
	system("Color 84"); //change color of console
	system("CLS");
	cout << string(50, '*') << endl; // string(int, char) prints a character int times.
	cout << "" << endl;
	cout << string(3, ' ') << "Roman to Numeral Converter by Anthony Jaghab" << endl;
	cout << "" << endl;
	cout << string(50, '*') << endl << endl;

	// the menu

	cout << "Please select either option:\n";
	cout << "1.) Roman numeral to integer:\n";
	cout << "2.) Integer to Roman numeral.:\n";
	cout << "-1.) Quit:\n\n";
	cout << "=================================\n\n";
	cout << "Enter your selection: ";

	int input;
	cin >> input;

	// cases for the menus
	switch (input)
	{
	case 1: 
		romanToIntMenu();
		break;
	case 2:
		intToRomanMenu();
		break;
	case -1:
		cout << "PEACE!";
		exit;
		break;
	}
}

/*
Main method.
*/
int main() {
	menu();
}