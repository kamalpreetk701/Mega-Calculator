#include<iostream>
//provides definitions for class MegaCalc

#include "MegaCalc.h"
#include"MegaInt.h"
#include<string>

MegaCalc::MegaCalc() :command{ NULL }, sign{'+'} {}

void MegaCalc::factorial(MegaInt & operand)			//calculates the factorial
{
	MegaInt i, result;
	result.intialize("1");
	i.intialize("1");
	
	for (i; i <=operand; ++i)
	{
		result =result*i;
		cout <<i<<"! ="<< result<<endl;
	}
	
}


void MegaCalc::run()					//runs the Mega Calculator
{
	string input;
	
	accumulator.sign = '+';
	accumulator.mega_int.push_back('0');
	cout << "WELCOME TO MEGACALCULATOR" << endl;
	cout << "=========================" << endl << endl;
	do{
		cout << "Accumulator:" << accumulator<<endl;
		
		cout << "Enter Input:";
		getline(cin,input);
		cout << endl;
		parse(input,accumulator);
	 } while (command != 'q');

}

void MegaCalc::hailStone(MegaInt & operand)			//find hailstone of a megaint
{
	MegaInt temp = operand;
	MegaInt two,zero,three,one;
	one.intialize("1");
	two.intialize("2");
	zero.intialize("0");
	three.intialize("3");
	int counter=0;

	while (!( temp == one))
	{
		
		if ((temp % two) == zero)
		{
			temp = temp / two;
			cout << temp<<endl;
		}
		else
		{
			temp = (temp * three) + one;
			cout << temp<<endl;
		}
		counter = counter + 1;
	}
	cout << "length of hailstrone sequence:" << counter;

}




void MegaCalc::execute(char command, MegaInt & operand,MegaInt& acc)		//executes the appropriate command
{
	
	operand.normalize();
	if (command == '+')
		accumulator.addition(operand);
	else if (command == '-')
		accumulator.subtraction(operand);
	else if (command == '*')
		accumulator.multiplication(operand);
	else if (command == '/')
		accumulator.division(operand);
	else if (command == '=')
		accumulator.equalto(operand);
	else if (command == 'h')
		hailStone(acc);
	else if (command == 'f')
		factorial(acc);
	else if (command == 'c')
		accumulator.clear();
	else if (command == 'n')
		accumulator.negate();
}

void MegaCalc::parse(string input,MegaInt & acc)			//parses the user entered input
{
	MegaInt operand;
		command = input[0];
	
			if(input[1]=='+'|| input[1]=='-')
		{
			operand.sign = input[1];
			operand.intialize(input.substr(2,input.size()-1));
		}
		else
		{
			operand.intialize(input.substr(1, input.size() - 1));
		}
			execute(command, operand,acc);
}


