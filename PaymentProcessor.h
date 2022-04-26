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
	static int submitPayment(int paymentM, PaymentInformation paymentInfo, float price);
};
