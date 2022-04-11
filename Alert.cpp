#include "Alert.h"

using namespace std;



int Alert::find_Driver(int order_ID) {

	return 1;
}


int Alert::customer_Delivery() {
	/*Find driver in near by restaurant*/
	return 1;
}


int Alert::restaurant_Decline(string reason) {
	try
	{
		Notification::send_Restaurant_Decline_Customer(reason);
	}
	catch (const exception&)
	{
		return 0;
	}
	return 1;
}


int Alert::restaurant_New_Order() {
	try
	{
		Notification::send_Order_Alert_Restaurant();
	}
	catch (const exception&)
	{
		return 0;
	}
	return 1;
}