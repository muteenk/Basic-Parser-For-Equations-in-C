

#include <stdio.h>
#include <math.h>


///////////////////////
// Function Prototypes 
////////////////////////

double checkFactor();
double parseNumber();
double parsePercent();
double parseExponent();
double parseDivision();
double parseProduct();
double parseSum();
double parseSubtraction();

double parseFormula();








//////////////////////////////////////
// Will store equation from arguments
//////////////////////////////////////

char *eqn;






////////////////////////
// Function Definitions
///////////////////////







// Parsing Numbers
double parseNumber(){

    // For Error Handling

    if (*eqn != '(' && !(*eqn >= '0' && *eqn <= '9')){
        printf("Error:\nInvalid Character '%c' Found !\n", *eqn);
        return 0;
    }


    // Will work in case of negation of an expression inside bracket
    if (*eqn == '('){
        eqn++;  // Ignoring '('
        double result = parseSubtraction();
        eqn++;  // Ignoring ')'
        return result;
    }

    double number = 0;

    // 123 = (((0*10 + 1)*10 + 2)*10 + 3)

    while (*eqn >= '0' && *eqn <= '9')
    {
        number = number * 10;
        number = number + (*eqn - '0');
        eqn++;  // next char
    }

    // 0.123 = 1*0.1 + 2*0.01 + 3*0.001

    if (*eqn == '.'){
        
        eqn++;  //ignore '.'

        double scale = 1;
        while (*eqn >= '0' && *eqn <= '9')
        {
            scale = scale / 10;
            double decimalNum = (*eqn - '0') * scale;
            number = number + decimalNum;
            eqn++;  // next char
        }
        

    }

    return number;

}





// Returns number if current character in the string is a number
double checkFactor(){

    // For handling Numbers
	if (*eqn >= '0' && *eqn <= '9'){
		return parseNumber();
	}
    // For handling Negative characters
    else if(*eqn == '-'){
        eqn++;  // ignoring '-'
        return parseNumber() * -1;
    }
    // For handling brackets
    else if (*eqn == '('){
        eqn++;  // ignoring '('
        double result = parseSubtraction();
        eqn++;  // ignoring ')'
        return result;
    }
	else{
		printf("Error:\nExpected Digit but got '%c' !\n", *eqn);
	}

}







// Parse Percent (if any)
double parsePercent(){

    double fact1 = checkFactor();
    while (*eqn == '%')
    {
        eqn++;  // ignoring '%'
        double fact2 = checkFactor();
        fact1 = (fact1/100)*fact2;
    }
    
    return fact1;
}








// Parsing Exponent (if any)
double parseExponent(){

    double per1 = parsePercent();

    while (*eqn == '^')
    {
        eqn++;  // Ignoring '^'
        double per2 = parsePercent();
        per1 = pow(per1, per2);        
    }
    return per1;


}







// Parses Division (if any)
double parseDivision(){

    double exp1 = parseExponent();
	while (*eqn == '/'){
		eqn++;  // ignoring '/'
		double exp2 = parseExponent();
		exp1 = exp1 / exp2;
	}
	return exp1;

}



// Parses Product (if any)
double parseProduct(){

    double div1 = parseDivision();
    while (*eqn == '*'){
        eqn++;  // ignoring '*'
        double div2 = parseDivision();
        div1 = div1 * div2;
    }
    return div1;

}


// Parses Sum (if any)
double parseSum(){

	double prod1 = parseProduct();
	while (*eqn == '+'){
		eqn++;  // ignoring '+'
		double prod2 = parseProduct();
		prod1 = prod1 + prod2;
	}
	return prod1;

}



// Parses Subtraction (if any)
double parseSubtraction(){

    double sum1 = parseSum();
    while (*eqn == '-'){
        eqn++;  // ignoring '-'
        double sum2 = parseSum();
        sum1 = sum1 - sum2;
    }

    // Checking for an invalid character
    if (*eqn != '-' && *eqn != '\0' && *eqn != ')'){

        printf("Invalid Character '%c' Found !\n", *eqn);
        return 0;

    }

    return sum1;

}


// Returns result to the main function
double parseFormula(){

    return parseSubtraction();

}