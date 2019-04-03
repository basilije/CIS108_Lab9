#include <math.h>
#include "calculator.h"

// probably unneccessary for a now
/*
	Calculator::Calculator() {	double memory; };

	Calculator::~Calculator() {	};
*/


// make an addition of a two numbers and return the result
double Calculator::makeAddition(double first_number, double second_number)
{
	return first_number + second_number;
}

// make a subtraction of a two numbers and return the result
double Calculator::makeSubtraction(double first_number, double second_number)
{
	return first_number - second_number;;
}

// make a multiplication of a two numbers and return the result
double Calculator::makeMultiplication(double first_number, double second_number)
{
	return first_number * second_number;
}

// make a division of a two numbers and return the result
double Calculator::makeDivision(double first_number, double second_number)
{
	return first_number / second_number;
}

// make a power function of a two numbers and return the result
double Calculator::makePower(double first_number, double second_number)
{
	return pow(first_number, second_number);
}

// store the number in the variable called "memory"
void Calculator::memoryStore(double input_number)
{
	memory = input_number;
}

// return the value of the variable called "memory"
double Calculator::memoryRecall()
{
	return memory;
}

// clear the value of the variable called "memory"
void Calculator::memoryClear()
{
	memory = 0;
}

// make a invert sign of a number and return the result
double Calculator::invertSign(double input_number)
{
	return 0.0 - input_number;
}


// make a square root of a number and return the result
double Calculator::squareRoot(double input_number)
{
	return sqrt(input_number);
}

// make a square root of a number and return the result
double Calculator::logarithm(double input_number)
{
	return log(input_number);
}

// make a sine function of a number and return the result
double Calculator::sineFunction(double input_number)
{
	return sin(input_number);
}

// make a cosine function of a number and return the result
double Calculator::cosineFunction(double input_number)
{
	return cos(input_number);
}

// make a tangent function of a number and return the result
double Calculator::tangentFunction(double input_number)
{
	return tan(input_number);
}


