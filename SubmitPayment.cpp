#include "SubmitPayment.h"
#include <string>
#include <iostream>
using namespace std;



//submitOrder
bool submitOrder(float totalCost)
{
	string paymentMethod = getPaymentMethod();
	PaymentProcessClass::PaymentInformation paymentInfo = getPaymentInformation();


	bool results = PaymentProcessClass::submitPayment(paymentMethod, paymentInfo, totalCost);

	return results;
}

//Choose a payment method
string getPaymentMethod()
{
	//User input for chosen payment method.
	string paymentMethod;

	//Users input for their card choice.
	cout << "Choose a payment method:\n";
	cout << "Visa\nMastercard\nAmerican Express\n";
	cin >> paymentMethod;

	return paymentMethod;

}

//The payment information class
PaymentProcessClass::PaymentInformation getPaymentInformation()
{
	PaymentProcessClass::PaymentInformation pI;
	PaymentProcessClass::PaymentInformation paymentInfo = PaymentProcessClass::PaymentInformation();
	cout << "Enter ccNumber: ";
	cin >> pI.ccNumber;

	cout << "Enter experation date: ";
	cin >> pI.experation;

	cout << "Enter CVC: ";
	cin >> pI.cvc;

	cout << "Enter the name on the credit card: ";
	cin >> pI.name;

	return paymentInfo;
}


