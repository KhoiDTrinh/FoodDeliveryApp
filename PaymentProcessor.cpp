#include "PaymentProcessor.h"
#include "SubmitPayment.h"
#include <string>
#include <iostream>
using namespace std;

int PaymentProcessorClass::submitPayment(int paymentMethod, PaymentInformation paymentInfo, float totalCost)
{
	PaymentInformation paymentInformation;
	ofstream payment;
	payment.open("payement.txt", ios::app);

	try {
		switch (paymentMethod)
		{
		case 1:					// PAYMENT TYPE IS VISA.
			payment << paymentInformation.name << "," << paymentInformation.ccNumber << "," << paymentInformation.cvc << "," << paymentInformation.experation << endl;
			return 1;
		case 2:					// PAYMENT TYPE IS MASTERCARD.
			payment << paymentInformation.name << "," << paymentInformation.ccNumber << "," << paymentInformation.cvc << "," << paymentInformation.experation << endl;
			return 1;
		case 3:					// PAYMENT TYPE IS AMERICAN EXPRESS.
			payment << paymentInformation.name << "," << paymentInformation.ccNumber << "," << paymentInformation.cvc << "," << paymentInformation.experation << endl;
			return 1;
		default:
			cout << "Im sorry, your payment was unsuccessful\n";
			throw 0;
		}
	}
	catch (int result)
	{
		return result;
	}
}