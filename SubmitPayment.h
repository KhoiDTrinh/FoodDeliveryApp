#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PaymentProcessorClass
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

	static bool submitPayment(int paymentM, PaymentInformation paymentInfo, float price)
	{
		fstream card_info;
		card_info.open("CardInformation");

		if (card_info.is_open())
		{
			card_info << paymentM;			//It will write into the file the type (in number) of payment: Visa = 1, Mastercard = 2, Ame. Ex = 3.

			PaymentInformation payI;
			//card_info << payI.lat << ' ' << ;
			card_info << price;				// It will write into the file the total price that the person will pay.

		}


	};
};
