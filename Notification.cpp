#include "Notification.h"

using namespace std;

//Send to file instead of console. (Notification.txt)

//Try and catch here
ofstream alert;

int Notification::send_Delivery_Alert_Driver(int order_ID) {
	alert.open("alert.txt", ios::app);

	try
	{
		alert << "New Order:\t" << order_ID;
		if (Alert::find_Driver(order_ID) == false){
			throw 0;
		}
		return 1;
	}
	catch (int x)
	{
		return x; 
		alert << "error";
	}

	alert.close();
}


int Notification::send_Delivery_Alert_Customer(ifstream &picture) {
	
	alert.open("alert.txt", ios::app);
	picture.open("picture.txt");
	try
	{
		alert << "You recieved a new Order.\n";
		if (Alert::customer_Delivery(picture) == false) {
			throw 0;
		}
		return 1;
	}
	catch (int x)
	{
		alert << "error";
		return x;
	}

	alert.close();
	picture.close();
}


int Notification::send_Order_Alert_Restaurant(string name) {

	alert.open("alert.txt", ios::app);
	try 
	{
		alert << "You recieved a new Order.\n" << name << endl;
		if (Alert::restaurant_New_Order(name) == false) {
			throw 0;
		}
		return 1;
	}
	catch (int x)
	{
		alert << "error";
		return x;
	}

	alert.close();
}
	

int Notification::send_Restaurant_Decline_Customer(string reason) {
	
	alert.open("alert.txt", ios::app);

	try
	{
		alert << "The Order was canceled due to: " << reason << endl;
		alert << "Sorry for the inconvenience.";

		if (Alert::restaurant_Decline(reason) == false) {
			throw 0;
		}
		return 1;
	}
	catch (int x)
	{
		alert << "error";
		return x;
	}

	alert.close();

}
