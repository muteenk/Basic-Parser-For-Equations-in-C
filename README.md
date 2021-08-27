# Simple Parser for Equations

This is a basic parser for evaluating equations written in less than 300 lines

## 	Features

- [x]   Addition 
- [x]   Multiplication
- [x]   Division
- [x]   Subtraction
- [x]   Percentage
- [x]   Exponent
- [x]   Parenthesis are allowed to use
- [x]   Negation
- [x]   Multi Digit Numbers
- [x]   Decimal Values
- [x]   Error Handling	
- [x]   Works on BODMAS and BEDMAS rule of mathematics


## functions used

- checkFactor => checking if the current char is a number
- parseNumber => Helps checkFactor to parse multi-digit and decimal numbers
- parsePercent => Takes two factors from checkFactor and Gives out its percentage
- parseExponent => Takes two factors from parsePercent and Performs exponent operation
- parseDivision => Takes two factors from parseExponent and divides them
- parseProduct => Takes two factors from parseDivision and multiplies them
- parseSum => Takes two factors from parseProduct and adds them
- parseSubtraction => Takes two factors from parseSum and Subracts them
- parseFormula => the main function which does all the parsing and returns result to main function

## Installation 

Clone this Repository to Your Local Setup

```bash
    git clone https://github.com/muteenk/Basic-Parser-For-Equations-in-C.git
```

Installation 

Write 'make' in your CLI, if gcc is installed on your computer it will compile calc.c

```bash
    make
```

## How to use

To use the calc parser, You can use './calc' or './calc.exe' (in case of windows os) and as 2nd argument you have to enter the expression without spaces in single quotes

```bash
    ./calc '(30+3)*34-54'
```

### For Windows OS

```bash
    ./calc.exe '(30+3)*34-54'
```

### Operators allowed

- You can perform Addition Operation using '+' operator

```bash
    ./calc '1+2+3'
```
will give the output :

```bash
    $ ./calc '1+2+3'
    6.000000
```

- You can perform Subtraction Operation using '-' operator

```bash
    $ ./calc '12-3'
    9.000000
```
- You can perform Multiplication Operation using '*' operator

```bash
    $ ./calc '5*2'
    10.000000
```
- You can perform Division Operation using '/' operator

```bash
    $ ./calc '32/2'
    16.000000
```
- You can perform Exponent Operations using '^' operator

```bash
    $ ./calc '2^2^2'
    16.000000
```
- You can perform Percentage Operations using '%' operator

```bash
    $ ./calc '50%1'
    0.500000
```
- You can use parenthesis '()' in your expressions

```bash
    $ ./calc '20-(2*5)'
    10.000000
```
- You can use negation '-' in your expressions 

```bash
    $ ./calc '-(2*5)'
    -10.000000
```

### Errors and Fixes

- Less Arguments
    This error occurs when only './calc' or './calc.exe' is written as command without any expression

```bash
    $ ./calc
    Fatal Error:
    Too less arguments were given !
``` 

- Too Many Arguments
    This error occurs when more than one argument is given or spaces are used in expression

```bash
    $ ./calc 4+ 3
    Fatal Error:
    More than one arguments entered !
``` 

- Zero Division Errors: 
    These may occur when you divide something with zero, It could be any number including zero itself

  When You Divide any number by zero, it will give 'inf' as output representing infinity :

```bash
    $ ./calc '23/0'
    inf
``` 
  When you divide zero by zero, it will give '-nan' as output representing not a number :

```bash
    $ ./calc '0/0'
    -nan
``` 

- Using More than one operator together:
    When you use multiple operators together, It will throw an invalid character error along with some garbage value

```bash
    $ ./calc '2+*3'
    Error:
    Expected Digit but got '*' !
    2.000000
``` 

- Unexpected Character Error:
    When you use an unexpected character in the expression, It will throw an error with some garbage output

```bash
    $ ./calc '4+a'
    Error:
    Expected Digit but got 'a' !
    Invalid Character 'a' Found !
    0.000000
```

- Invalid Character Error:
    When you use an invalid operator or character in the expression, It will throw error with some garbage output

```bash
    $ ./calc '4#2'
    Invalid Character '#' Found !
    0.000000
```

## Author

- Muteen K. (me)