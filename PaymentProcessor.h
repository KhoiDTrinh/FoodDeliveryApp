#pragma once
#include <iostream>
#include <string>
using namespace std;

class paypross
{
private:

public:
	static const struct PaymentInformation
	{
		int ccNumber;
		int experation;
		int cvc;
		string name;
	};
	static bool submitPayment(string paymentM, PaymentInformation paymentInfo, float price);
};