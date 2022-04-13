#include "Alert.h"

using namespace std;



int Alert::find_Driver(int order_ID) {
	/*Find driver in near by restaurant*/

	return Notification::send_Delivery_Alert_Driver(order_ID);
}


int Alert::customer_Delivery(ifstream &picture) {
	return Notification::send_Delivery_Alert_Customer(picture);
}


int Alert::restaurant_Decline(string reason) {
	return Notification::send_Restaurant_Decline_Customer(reason);
}


int Alert::restaurant_New_Order(string name) {
	return Notification::send_Order_Alert_Restaurant(name);
}