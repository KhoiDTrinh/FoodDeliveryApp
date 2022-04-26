#include "PaymentProcessor.h"
#include <string>
using namespace std;

bool paypross::submitPayment(string paymentMethod, PaymentInformation paymentInfo, float totalCost)
{
	bool result = false;
	switch (paymentMethod)
	{
	case "Visa":
		bool results = 1;
		return result;
	case "American Express":
		bool result = 1;
		return results;
	case 'Matercard':
		bool result = 1;
		return result;
	default: return result;
	}
}