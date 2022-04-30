#include "Alert.h"

using namespace std;



int Alert::find_driver(int order_id) {
	vector<string> driver_list;

	string record;
	string user_id, account_type;
	ifstream file;
	file.open(UserInformation::file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, user_id, ',');
		getline(line, account_type, ',');
		getline(line, account_type, ',');
		getline(line, account_type, ',');		//The 4th value in the database is account_type
		if (stoi(account_type) == 1)
			driver_list.push_back(user_id);
	}
	file.close();

	if (driver_list.size() == 0)
		return -1;

	srand(time(0));
	int index = rand() % driver_list.size();
	return Notification::send_new_delivery_alert_driver(order_id, stoi(driver_list[index]));
}


int Alert::customer_delivery(int order_id, int customer_id) {
	return Notification::send_delivered_alert_customer(order_id, customer_id);
}


int Alert::restaurant_decline(int order_id, int customer_id) {
	return Notification::send_order_notification_restaurant(order_id, customer_id);
}


int Alert::restaurant_new_order(int order_id, int restaurant_id) {
	return Notification::send_order_notification_restaurant(order_id, restaurant_id);
}