
/*

	This is a mini parser for parsing equations

	Features :
	[x] Addition 
	[x] Multiplication
	[x] Division
	[x] Subtraction
	[x]	Percentage
	[x] Parenthesis
	[x] Negation
	[x] Multi Digit Numbers
	[x] Decimal Values
	[x] Error Handling	
	[x] Equations as command line arguments

	functions used =>
		checkFactor - checking if the current char is a number
		parseNumber - Helps checkFactor to parse multi-digit and decimal numbers
		parsePercent - Takes two factors from checkFactor and Gives out its percentage
		parseDivision - Takes two factors from parsePercent and divides them
		parseProduct - Takes two factors from parseDivision and multiplies them
		parseSum - Takes two factors from parseProduct and adds them
		parseSubtraction - Takes two factors from parseSum and Subracts them
		parseFormula - the main function which does all the parsing and returns result to main function

*/


#include <stdio.h>
#include "parser.h"




//////////////////////
// Main Function
//////////////////////

int main(int argc, char *argv[]){

	if (argc > 2){
		printf("Fatal Error:\nMore than one arguments entered !\n");
	}
	else if(argc < 2){
		printf("Fatal Error:\nToo less arguments were given !\n");
	}
	else if(argc == 2){
		// Assigning the argument as equation
		eqn = argv[1];

		float result = parseFormula();
		printf("%f\n", result);
	}

	return 0;
}








