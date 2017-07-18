
//provides the declaration for  MegaInt class
#pragma once
#include<iostream>
#include<deque>
#include<string>

using namespace std;

#ifndef MEGAINT_H
#define MEGAINT_H

class MegaInt
{
	
private:

public:
	std::deque<char>mega_int;		//deque 
	char sign = '+';				//sign

	MegaInt();
	MegaInt& operator=(MegaInt&);

	void clear();				//to clear accumulator
	void negate();				//negates accumulator
	int size();					//finds size of megaint
	char compliment(char sign);		//find compliment of sign
	char int_to_char(int);			//converts integer to character
	int max(int, int);				
	int char_to_int(char);			//converts character to integer
	void intialize(string);			//intalize a MegaInt with string
	void normalize();				//remove front zeros
	void left_shift();				//left shift the deque
	void equalto(MegaInt i);		//asssigns the value to accumulator
	MegaInt& addition(MegaInt operand2);
	MegaInt& subtraction(MegaInt oprand2);
	void multiplication(MegaInt &);
	void division(MegaInt &);

	//Arithemetic operator operloads
	 friend MegaInt operator-(MegaInt&, MegaInt&);
	 friend MegaInt operator+(MegaInt&, MegaInt&);
	 friend MegaInt  operator*(MegaInt&, MegaInt&);
	 friend MegaInt operator/(MegaInt&, MegaInt&);
	 friend MegaInt operator%(MegaInt &, MegaInt &);
	 MegaInt &  operator++();
	 MegaInt & operator++(int);
	 MegaInt &  operator--();
	 MegaInt & operator--(int);


	 MegaInt& operator+=(MegaInt&);
	 MegaInt& operator-=(MegaInt&);
	 MegaInt & operator/=(MegaInt&);
	 MegaInt& operator*=(MegaInt&);
	MegaInt& operator%=(MegaInt&);
	
	//Relational operator overloads
		
	 friend bool operator<(MegaInt&, MegaInt&);
	 friend bool operator==(MegaInt&, MegaInt&);
	 friend bool operator>(MegaInt&, MegaInt&);

	 friend bool operator>=(MegaInt&, MegaInt&);
	 friend bool operator<=(MegaInt&, MegaInt&);
	 friend bool operator!=(MegaInt&, MegaInt&);
	
	
	 friend ostream & operator<<(ostream &out, MegaInt&);
	 char & operator[](int i);
	

};
#endif