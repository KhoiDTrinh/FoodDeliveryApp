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
		int ccNumber;	//cardNumber
		int experation; // Date of Experation
		int cvc;        // CVC/ security number
		string name;    // Name on the card
	};

	static int submitPayment(int paymentM, PaymentInformation paymentInfo, float price)
	{
		fstream card_info;
		card_info.open("payment.txt");

		if (card_info.is_open())
		{
			card_info << paymentM;			// It will write into the file the type (in number) of payment: Visa = 1, Mastercard = 2, Ame. Ex = 3.

			PaymentInformation payI;		// Identify paymentInfo as payI to pass numbers and name on card to a file
			card_info << payI.ccNumber;		// Push the ccNumber
			card_info << payI.cvc;			// Push the cvc/ security number
			card_info << payI.experation;   // Push the experation date
			card_info << payI.name;			// Push the name on the card

			card_info << price;				// It will write into the file the total price that the person will pay.

			cout << "Payment is successful.\n";
			return 1;
		}
		else
		{
			cout << "Im sorry this payment method was unsuccessful";
			return 0;
		}
	};
};
