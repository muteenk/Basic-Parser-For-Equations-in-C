

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








