# Simple Parser for Equations

This is a basic parser for evaluating equations written in less than 300 lines

## 	Features

- [x]   Addition 
- [x]   Multiplication
- [x]   Division
- [x]   Subtraction
- [x]   Percentage
- [x]   Parenthesis are allowed to use
- [x]   Negation
- [x]   Multi Digit Numbers
- [x]   Decimal Values
- [x]   Error Handling	
- [x]   Works on BODMAS rule of mathematics


## functions used

- checkFactor => checking if the current char is a number
- parseNumber => Helps checkFactor to parse multi-digit and decimal numbers
- parsePercent => Takes two factors from checkFactor and Gives out its percentage
- parseDivision => Takes two factors from parsePercent and divides them
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

To use the calc parser, You can use './calc' or './calc.exe' (in case of windows os) and as 2nd argument you have to enter the expression without spaces

```bash
    ./calc '(30+3)*34-54'
```

### For Windows OS

```bash
    ./calc.exe '(30+3)*34-54'
```

## Author

- Muteen K. (me)