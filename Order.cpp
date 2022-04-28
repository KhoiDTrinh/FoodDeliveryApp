#include "Order.h"
#include "Cart.h"
using namespace std;

int Order::updateOrderStatus(int status)
{
	return 0;
}

void Order::createOrderFromClass(Cart cart)
{
	int orderID = getNextID();
	vector<float> itemList = cart.getItemQuantity();
	int itemQuantity = cart.getItemComments();
	string orderComments = cart.getItemComments();
	int resturantID = cart.restaurantID;
	int userID = cart.userID;

	Alert::find_Driver(orderID);
	Alert::restaurant_New_Order(orderID);
}

// Restaurant declines order and sends notice.
void Order::restaurantDecline(string reason)
{
	Alert::restaurant_Decline(reason);
}

// Pass alert that driver has declined the order
void Order::driverDecline()
{
	Alert::find_Driver(orderID);
}