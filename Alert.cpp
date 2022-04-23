#include "Alert.h"

using namespace std;



int Alert::find_Driver(int order_ID) {
	/*Find driver in near by restaurant*/
	string driver_record, account_type;
	fstream read;
	read.open(UserInformation::file_name);
	while (getline(read, driver_record)) {
		stringstream ss(driver_record);

		getline(ss, account_type, ',');
		getline(ss, account_type, ',');
		getline(ss, account_type, ',');

		if (account_type.compare("1") == 0) {
			return Notification::send_Delivery_Alert_Driver(order_ID, driver_record);
		}
	}

	return 0;
}


int Alert::customer_Delivery(ifstream &picture) {
	return Notification::send_Delivery_Alert_Customer(picture);
}


int Alert::restaurant_Decline(string reason) {
	return Notification::send_Restaurant_Decline_Customer(reason);
}


int Alert::restaurant_New_Order(string name) {
	string customer_record, account_type;
	fstream read;
	read.open(UserInformation::file_name);
	while (getline(read, customer_record)) {
		stringstream ss(customer_record);

		getline(ss, account_type, ',');
		getline(ss, account_type, ',');
		getline(ss, account_type, ',');

		if (account_type.compare("0") == 0) {
			return Notification::send_Order_Alert_Restaurant(name, customer_record);
		}
	}
	return 0;
	
}