#include "UpdateOrderStatus.h"

int UpdateOrderStatus::updateOrderStatus()
{
	int status;

	cout << "New Order Status: " << endl; 
	cin >> status;

	return Order::updateOrderStatus(status);
}

int UpdateOrderStatus::orderDelivered(ifstream &picture)
{

	return 0;
}
