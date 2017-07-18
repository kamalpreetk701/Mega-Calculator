
#include<iostream>
#include<deque>
#include "MegaInt.h"
using namespace std;

#ifndef MEGACALC_H
#define MEGACALC_H

class MegaCalc
{
private:char command;
		MegaInt accumulator;
		
		char sign;
public:		MegaCalc();
	void factorial(MegaInt & );
	void run();
	void hailStone(MegaInt &);
	void execute(char,MegaInt &,MegaInt &);
	void parse(string,MegaInt& );
	
};


#endif