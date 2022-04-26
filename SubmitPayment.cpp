#include "SubmitPayment.h"
#include <string>
#include <iostream>
using namespace std;



//submitOrder
bool submitOrder(float totalCost)
{
	int paymentMethod = getPaymentMethod();
	PaymentProcessorClass::PaymentInformation paymentInfo = getPaymentInformation();


	bool results = PaymentProcessorClass::submitPayment(paymentMethod, paymentInfo, totalCost);

	return results;
}

//Choose a payment method
int getPaymentMethod()
{
	//User input for chosen payment method. so paymentMethod == paymentoption.
	int paymentoption;

	//Users input for their card choice.
	cout << "Choose a payment method (Enter option number):\n";
	cout << "(1)Visa\n(2)Mastercard\n(3)American Express\n";
	cin >> paymentoption;

	return paymentoption;

}

//The payment information class
PaymentProcessorClass::PaymentInformation getPaymentInformation()
{
	// paymentInfo will push customers data into the PaymentInformation structure that contain the ccNumber, experation, CVC, and name on the card.
	PaymentProcessorClass::PaymentInformation pI = PaymentProcessorClass::PaymentInformation();

	// Customer enters the ccNumber, Experation date, CVC and the name on the card.
	cout << "Enter ccNumber: ";
	cin >> pI.ccNumber;

	cout << "Enter experation date (MMYYYY): ";
	cin >> pI.experation;

	cout << "Enter CVC: ";
	cin >> pI.cvc;

	cout << "Enter the name on the credit card: ";
	cin >> pI.name;

	return pI;
}



