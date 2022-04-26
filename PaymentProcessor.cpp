#include "PaymentProcessor.h"
#include <string>
#include <iostream>
using namespace std;

bool paypross::submitPayment(int paymentMethod, PaymentInformation paymentInfo, float totalCost)
{
	bool result = false;
	switch (paymentMethod)
	{
	case 1:					// PAYMENT TYPE IS VISA.
		bool results = true;
		return result;
	case 2:					// PAYMENT TYPE IS MASTERCARD.
		bool result = true;
		return results;
	case 3:					// PAYMENT TYPE IS AMERICAN EXPRESS.
		bool result = true;
		return result;
	default:
		cout << "Im sorry, your payment was unsuccessful\n";
		return result;
	}
}
/*
int PaymentProcessor::submitPayment(int paymentMethod, PaymentInformation paymentInfo, float totalCost){
	ofstream payment;
	payment.open("payement.txt", ios::app);

	try{
		switch(paymentMethod)
		{
			case 1;
			payment << paymentInformation.name << "," << paymentInformation.cardNumber <<"," << paymentInformation.cvc <<"," << paymentInformation.experation << endl;
			return 1;
			case 2;
			payment << paymentInformation.name << "," << paymentInformation.cardNumber <<"," << paymentInformation.cvc <<"," << paymentInformation.experation << endl;
			return 1;
			case 3;
			payment << paymentInformation.name << "," << paymentInformation.cardNumber <<"," << paymentInformation.cvc <<"," << paymentInformation.experation << endl;
			return 1;
			default:
				throw 0;
				cout << invalid;
		}

	catch(int result)
		return result;

	}
}

*/