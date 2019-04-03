#pragma once

class Calculator{

public:

// probably unneccessary for a now
/*
	Calculator();
	
	~Calculator();
*/

	double memory;

	double makeAddition(double first_number, double second_number);

	double makeSubtraction(double first_number, double second_number);

	double makeMultiplication(double first_number, double second_number);

	double makeDivision(double first_number, double second_number);

	double makePower(double first_number, double second_number);

	void memoryStore(double input_number);

	double memoryRecall();

	void memoryClear();

	double invertSign(double input_number);

	double squareRoot(double input_number);

	double logarithm(double input_number);

	double sineFunction(double input_number);

	double cosineFunction(double input_number);

	double tangentFunction(double input_number);


};
