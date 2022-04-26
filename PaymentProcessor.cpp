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
