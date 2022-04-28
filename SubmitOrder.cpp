#include "SubmitOrder.h"
#include "Cart.h"
#include "Order.h"
#include <iostream>
using namespace std;

bool submitOrder(int userID)
{
	Cart customerCart; // = search for cart data by userID
	float totalCart = customerCart.getTotalCost();
	bool paymentVerified = SubmitPaymentClass.submitOrder(totalCost);

	if (paymentVerified)
	{
		Order order = new Order();
		order.createOrderFromCart(customerCart);
	}
	else
	{
		return paymentVerified;
	}
}