#include "Notification.h"

using namespace std;



void Notification::send_Delivery_Alert_Driver(int order_ID) {
	/* find driver*/
}


void Notification::send_Delivery_Alert_Customer(/*file*/) {
	if (Alert::customer_Delivery() == 1) {
		cout << "You recieved a new Order.\n";
	}
	else
	{
		cout << "error";
	}
}


void Notification::send_Order_Alert_Restaurant() {
	if (Alert::restaurant_New_Order() == 1) {
		cout << "You recieved a new Order.\n";
	}
	else
	{
		cout << "error";
	}
}
	

void Notification::send_Restaurant_Decline_Customer(string reason) {
	
	if (Alert::restaurant_Decline(reason) == 1) {
		cout << "The Order was canceled due to: " << reason << endl;
		cout << "Sorry for the inconvenience.";
	}
	else
	{
		cout << "error";
	}
}
