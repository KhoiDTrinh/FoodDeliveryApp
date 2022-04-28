#include "Cart.h"

using namespace std;

int userID;
vector<int> itemID;
vector<int> itemQuantity;
vector<float> itemPrice;
string itemComments;
int customerCart;

float Cart::getTotalAmount()
{
	float total = 0;
	for (int i = 0; i < itemID.size(); i++)
	{
		total += itemPrice[i] * itemQuantity[i];
	}
	return total;
}