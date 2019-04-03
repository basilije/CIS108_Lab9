#include <iostream>
#include <string>
#include "conio.h"
#include "Calculator.h"

using namespace std;

Calculator calculator;
double first_number_for_the_operation, second_number_for_the_operation;
string keys_before_the_operation_typed, keys_after_the_operation_typed;
int active_number;
char operation_in_progress, key_pressed;
bool decimal_key_is_pressed;
string wakka = "> ";

// reset all variables to the default value
void resetVariables()
{
	keys_before_the_operation_typed = "";
	keys_after_the_operation_typed = "";
	first_number_for_the_operation = 0;
	second_number_for_the_operation = 0;
	active_number = 1;
	decimal_key_is_pressed = false;
}

// auxiliary function for printing the first number and set other values
void printNewLineResultAndPutFirstNumberBackToTheString()
	{
	cout << endl << wakka << first_number_for_the_operation; // and use it as a first number for the next operation
	keys_before_the_operation_typed = to_string(first_number_for_the_operation);  // convert number to the left string 
	decimal_key_is_pressed = (keys_before_the_operation_typed.find('.') != string::npos); // find if number is decimal and set the bool value
	}


int main()
{
	
	cout << wakka;
	resetVariables();

	do
	{

		key_pressed = toupper(char(_getch())); // get the key pressed, convert it to char and to upper case of the key pressed
		
		switch (key_pressed)
		{
			// if the digit or dot is pressed
		case '1': case '2': case'3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case'.':
			if ((key_pressed != '.') || (key_pressed == '.' && !decimal_key_is_pressed))
			{
				if (active_number == 1)
					keys_before_the_operation_typed += key_pressed;
				else
					keys_after_the_operation_typed += key_pressed;
				cout << key_pressed;
			}
			if (key_pressed == '.')
				decimal_key_is_pressed = true;				
			break;
				
			// if some of the operation key is pressed
		case '*': case '+': case '-': case '/': case '^':
			if (active_number == 1)
			{
				first_number_for_the_operation = stod(keys_before_the_operation_typed);
				active_number = 2;
				decimal_key_is_pressed = false;  // decimal key should be false when changing the active number
				keys_before_the_operation_typed = "";
				keys_after_the_operation_typed = "";
			}
			cout << key_pressed;
			operation_in_progress = key_pressed;
			break;

			// if "Enter" is pressed
			case char(13) :
				cout << endl;
				if (keys_after_the_operation_typed != "")
				{
					second_number_for_the_operation = stod(keys_after_the_operation_typed); // get the keys after operation key pressed as second number

					// do a neccessary operation that depends of a key that is earlier pressed as a operation key, and put the result in first number double variable
					switch (operation_in_progress)
					{
					case '+':
						first_number_for_the_operation = calculator.makeAddition(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '-':
						first_number_for_the_operation = calculator.makeSubtraction(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '*':
						first_number_for_the_operation = calculator.makeMultiplication(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '/':
						first_number_for_the_operation = calculator.makeDivision(first_number_for_the_operation, second_number_for_the_operation);
						break;
					case '^':
						first_number_for_the_operation = calculator.makePower(first_number_for_the_operation, second_number_for_the_operation);
						break;
					default:
						break;
					}
				}
				cout << wakka << first_number_for_the_operation; // print the result
				keys_before_the_operation_typed = to_string(first_number_for_the_operation); // put first number back in the string before the operation
				keys_after_the_operation_typed = ""; // clear the 'after the operation' string 
				active_number = 1; // set active number as first
				decimal_key_is_pressed = (keys_before_the_operation_typed.find('.') != string::npos);  // find if number is decimal and set the bool value
				break;

				// if "S" is pressed
			case 'S':
				if (keys_before_the_operation_typed != "")
					first_number_for_the_operation = stod(keys_before_the_operation_typed);
				calculator.memoryStore(first_number_for_the_operation); // call the function for storing the number in the memory
				break;

				// if "R" is pressed
			case 'R':
				first_number_for_the_operation = calculator.memoryRecall(); // get the number from the memory
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

				// if "M" is pressed
			case 'M':
				calculator.memoryClear(); // clear the memory
				break;

				// if "I" is pressed
			case 'I':
				first_number_for_the_operation = calculator.invertSign(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will invert it
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

				// if "C" is pressed
			case 'C':
				cout << endl << wakka; // print the default char in a new row;
				resetVariables(); // reset all variables
				break;

				// if "Q" is pressed
			case 'Q':
				first_number_for_the_operation = calculator.squareRoot(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will square root it
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

				// if "L" is pressed
			case 'L':
				first_number_for_the_operation = calculator.logarithm(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will logarithm it
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

				// if "N" is pressed
			case 'N':
				first_number_for_the_operation = calculator.sineFunction(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will sine it
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

				// if "O" is pressed
			case 'O':
				first_number_for_the_operation = calculator.cosineFunction(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will cosine it
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

				// if "T" is pressed
			case 'T':
				first_number_for_the_operation = calculator.tangentFunction(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will tangent it
				printNewLineResultAndPutFirstNumberBackToTheString();
				break;

			default:
				break;
		}

	} while (key_pressed != 'X');

	return 0;
}
