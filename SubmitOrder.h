#pragma once
#include <iostream>
#include <string>
using namespace std;

class PaymentProcessorClass
{
	static const struct PaymentInformation
	{
		int ccNumber;
		int experation;
		int cvc;
		string name;
	};
};
