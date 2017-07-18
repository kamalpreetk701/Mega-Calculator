//provides the definition for MegaInt class

//METHOD M1 USED FOR MULTIPLICATION 
//METHOD D1 USED FOR DIVISION

#include<iostream>
#include "MegaCalc.h"
#include"MegaInt.h"
#include<string>
#include<algorithm>

using namespace std;

MegaInt::MegaInt()
{
}


void MegaInt::intialize(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		this->mega_int.push_back(str[i]);
	}
}

MegaInt & MegaInt::operator=(MegaInt & operand)
{
	this->mega_int = operand.mega_int;
	return *this ;
}



void MegaInt::normalize()
{
	MegaInt temp;
	std::string str(this->mega_int.begin(), this->mega_int.end());
	
	string str2=str.erase(0, min(str.find_first_not_of('0'), str.size() - 1));
	
	temp.intialize(str2);
	*this = temp;
}

void MegaInt::left_shift()
{
	MegaInt temp;
	temp.mega_int.push_front('0');
	
	for (int i = this->mega_int.size()-1; i>=0; i--)
	{
		temp.mega_int.push_front(this->mega_int[i]);
	}
	
	*this = temp;
}

void MegaInt::equalto(MegaInt operand)
{
	*this = operand;
}

void MegaInt::multiplication(MegaInt & operand2)	//multiplies two megaint using method M2
{
	MegaInt acc = *this;
	char sign1 = acc.sign;
	char sign2 = operand2.sign;

	if (sign1 == sign2)
		this->sign = '+';
	else
		this->sign = '-';

	*this = acc*operand2;
}

void MegaInt::division(MegaInt & operand2)// divides two mega ints using method D1
{
	MegaInt acc = *this;
	char sign1 = acc.sign;
	char sign2 = operand2.sign;

	if (sign1 == sign2)
		this->sign = '+';
	else
		this->sign = '-';

	*this = acc/operand2;
}

char & MegaInt::operator[](int i)		//subscript operator overload
{
	return this->mega_int[i];
}



MegaInt & MegaInt::addition(MegaInt operand2)//adds two mega int
{
	MegaInt acc = *this;
	char sign1 = acc.sign;
	char sign2 = operand2.sign;

	MegaInt result;
	

	if (sign1 == sign2)
	{
		
		*this= acc+operand2;
		this->sign=sign1;
	}
	else
	{
		if (acc > operand2)
		{
			*this =acc-operand2;
			this->sign=sign1;
		}
		else if (acc<operand2)
		{
			*this = operand2-acc;
			this->sign=compliment(sign1);
		}
		else
		{
			this->mega_int.push_back('0');
		}
	}
	return *this;
}


MegaInt & MegaInt::subtraction(MegaInt operand2)
{
	MegaInt operand1 = *this;
	char sign1 = operand1.sign;
	char sign2 = operand2.sign;

	
	if (sign1 != sign2)
	{
		
		*this = operand1 + operand2;
		this->sign = sign1;
	}
	else
	{
		if (operand1 > operand2)
		{	*this = operand1- operand2;
			this->sign=(sign1);
		}
		else if (operand1 < operand2)
		{	*this = operand2-operand1;
			this->sign=compliment(sign1);
		}
		else
		{
			this->clear();
		}
	}
	return *this;
}



int MegaInt::size()
{
	return mega_int.size();
}


char MegaInt::compliment(char sign)
{
	if (sign == '+')
		sign = '-';
	else
		sign = '+';

	return sign;
}


char MegaInt::int_to_char(int i)
{
	return static_cast<char>( i+'0');
}


int MegaInt::max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int MegaInt::char_to_int(char c)
{
	return c - '0';
}


MegaInt  operator+( MegaInt & operand1,  MegaInt & operand2)
{
	int temp;
	MegaInt result_value;
	
	int carry = 0;;
	int size1 = operand1.size()-1;
	int size2 = operand2.size()-1;
	int i= (size1> size2?size1:size2)+1;
	
	while (size1 >= 0 && size2 >= 0)
	{
		int firstdigit = operand1.char_to_int(operand1.mega_int[size1]);
		
		int seconddigit = operand2.char_to_int(operand2.mega_int[size2]);
		
		temp=firstdigit+ seconddigit+carry;
		result_value.mega_int.push_front (result_value.int_to_char (temp % 10));
		carry = temp / 10;
		size1--;
		size2--;
		i--;
	}
	while (size1 >= 0)
	{
		temp = operand1.char_to_int(operand1.mega_int[size1]) + carry; 
		result_value.mega_int.push_front(result_value.int_to_char(temp % 10));
		carry = temp / 10;
		size1--;
		i--;
	}
	while (size2 >= 0)
	{
		temp=operand1.char_to_int(operand2.mega_int[size2]) + carry;
		result_value.mega_int.push_front(result_value.int_to_char(temp % 10));
		carry = temp / 10;
		size2--;
		i--;
	}
	result_value.mega_int.push_front(result_value.int_to_char(carry));
	result_value.normalize();
	return result_value;
}


MegaInt &  MegaInt::operator++()
{
	MegaInt temp;
	temp.intialize("1");
	*this =*this+temp;
	
	return *this;

}

MegaInt& MegaInt::operator++(int)
{
	MegaInt temp,temp2;
	temp2.intialize("1");
	temp = *this;
	*this=*this+temp2;
	return temp;
}

MegaInt & MegaInt::operator--()
{
	MegaInt temp;
	temp.intialize("1");
	*this = *this - temp;

	return *this;
}

MegaInt & MegaInt::operator--(int)
{
	MegaInt temp, temp2;
	temp2.intialize("1");
	temp = *this;
	*this = *this - temp2;
	return temp;
}

MegaInt & MegaInt::operator+=(MegaInt & rhs)
{
	*this = *this + rhs;
	return *this;
}


MegaInt &  MegaInt::operator-=(MegaInt & rhs)
{
	*this = *this - rhs;
	return *this;
}

MegaInt & MegaInt::operator/=(MegaInt & rhs)
{
	*this = *this / rhs;
	return *this;
}

MegaInt& MegaInt::operator*=(MegaInt & rhs)
{
	*this = *this * rhs;
	return *this;
}

MegaInt & MegaInt::operator%=(MegaInt & rhs)
{
	*this = *this % rhs;
	return *this;
}

MegaInt operator-(MegaInt & operand1, MegaInt & operand2)
{
	
	int temp;
	MegaInt result_value;
	int borrow = 0;;
	int size1 = operand1.size() - 1;
	int size2 = operand2.size() - 1;
	int i = (size1> size2 ? size1 : size2);

	while (size1 >= 0 && size2 >= 0)
	{
		temp = (operand1.char_to_int(operand1.mega_int[size1]) - operand2.char_to_int(operand2.mega_int[size2]) -borrow);
		borrow = 0;
		if (temp < 0)
		{	borrow = 1;
			temp = 10 + temp;
		}
		result_value.mega_int.push_front(operand1.int_to_char(temp));
		size1--;
		size2--;
		i--;
	}
	while (size1 >= 0)
	{
		temp = (operand1.char_to_int(operand1.mega_int[size1]) -borrow);
		borrow = 0;
		if (temp < 0)
		{	borrow = 1;
			temp = temp + 10;
		}
		result_value.mega_int.push_front( operand1.int_to_char(temp));
		size1--;
		i--;
	}
	if (borrow == 1 || size2 > 0)
		throw  "X cannot be grater than Y ";
	
	result_value.normalize();
	return result_value;
}





MegaInt  operator*(MegaInt & op1, MegaInt & op2)
{
	//operand1 is always the number with more digits
	MegaInt operand1, operand2,result;
	int carry = 0, temp;
	if (op1 < op2)
	{
		operand1 = op2;
		operand2 = op1;
	}
	else
	{
		operand1 = op1;
		operand2 = op2;
	}
	
		for (int i = operand2.size()-1; i >=0 ; i--)
		{
			carry = 0;
			MegaInt tempresult;
			for (int j = operand1.size() - 1; j >= 00; j--)
			{
				
				temp = (operand1.char_to_int(operand1.mega_int[j])*operand2.char_to_int(operand2.mega_int[i])+carry);
				tempresult.mega_int.push_front(result.int_to_char(temp % 10));
				carry = temp / 10;
			}
			tempresult.mega_int.push_front(tempresult.int_to_char(carry));
			int k = operand2.size()-1;
			while (k > i)
			{
				tempresult.left_shift();
				k--;
			}
			
			result = result + tempresult;
			result.normalize();
		}
		return result;
}





MegaInt operator/(MegaInt & op1, MegaInt & op2)
{
	
	MegaInt operand1, operand2,temp,r,q;
	MegaInt zero;
	zero.intialize("0");
	q.intialize("0");
	temp = op1;
	
	if ((op1 < op2))
	{
			cout << "cannot divide smaller number with larger number";
			exit(0);
	}

	else
	{
		int size1 = op1.size();
		int size2 = op2.size();

		while (temp >= op2)
		{
			
			temp = temp - op2;
			q++;
		}
		r = temp;
		temp.normalize();
		if (!(r == zero))
		{
			cout << "Remainder:" << r<<endl;
		}
		
			return q;
	}
}
	


MegaInt operator%(MegaInt & op1, MegaInt & op2)
{
	MegaInt  temp, r, q, div;
	MegaInt zero;

	q.intialize("0");
	temp = op1;

	if ((op1 < op2))
	{
		cout << "cannot divide smaller number with larger number";
		exit(0);
	}

	else
	{
		int size1 = op1.size();
		int size2 = op2.size();
		while (temp >= op2)
		{
			temp = temp - op2;
			q++;
		}
		r = temp;
		temp.normalize();
		return temp;
	}
}






//RELATIONAL OPERATOR OVERLOADS

ostream& operator<<(ostream & out, MegaInt & operand)
{
	out << operand.sign;
	for (int i = 0; i < operand.size(); i++)
	{
		out << operand.mega_int[i];
	}
	return out;
}


bool operator<(MegaInt & operand1, MegaInt & operand2)
{
	bool flag = false;
	if(operand1.size()<operand2.size())
	flag= true;
	else if (operand1.size() == operand2.size())
	{
		int i = 0;
		while( i<operand1.size())
		{
			if (operand1[i] == operand2[i])
			{	i++;
				flag = false;
			}
			else if (operand1[i] < operand2[i])
			{	flag= true;	i++;
				break;
			}
			else
			{	flag = false; i++; 
				break;	
			}
		}
	}
	return flag;
}


bool operator==(MegaInt & operand1, MegaInt & operand2)
{
	bool flag = false;
	if (operand1.size() != operand2.size())
		flag= false;
	else if (operand1.size() == operand2.size())
	{
		int i = 0;
		while (i<operand1.size())
		{
			if (operand1[i] == operand2[i])
			{	i++;
				flag = true;
			}
			else
			{	flag = false;
				i++;
			}
		}
	}
	return flag;
}


bool operator>(MegaInt & operand1, MegaInt & operand2)
{
	
	return !((operand1<operand2)||(operand1==operand2));
}


bool operator>=(MegaInt & operand1, MegaInt & operand2)
{
	return !(operand1<operand2);
}


bool operator<=(MegaInt & operand1, MegaInt & operand2)
{
	return (operand1==operand2||operand1<operand2);
}


bool operator!=(MegaInt & operand1, MegaInt & operand2)
{
	return !(operand1 == operand2);
}

void MegaInt::clear()
{
	this->mega_int.erase(this->mega_int.begin(), this->mega_int.end());
	this->mega_int.push_back('0');
	this->sign = '+';
}

void MegaInt::negate()
{
	this->sign = '-';
}

