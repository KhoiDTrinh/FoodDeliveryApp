#include "Notification.h"

using namespace std;

string Notification::notifications_file_name = "Notifications.txt";

int Notification::send_new_delivery_alert_driver(int order_id, int driver_id) {
	return send_notification(order_id, driver_id, "new delivery");
}


int Notification::send_delivered_alert_customer(int order_id, int customer_id) {
	return send_notification(order_id, customer_id, "order delivered");
}


int Notification::send_order_notification_restaurant(int order_id, int restaurant_id) {
	return send_notification(order_id, restaurant_id, "new order");
}
	

int Notification::send_restaurant_decline_customer(int order_id, int customer_id) {
	return send_notification(order_id, customer_id, "retaurant declined order");
}

int Notification::send_notification(int order_id, int user_id, string message) {
	string output = to_string(user_id) + "," + to_string(order_id) + "," + message;
	ofstream file;
	file.open(notifications_file_name, ios::app);
	file << output << endl;
	file.close();
	return 1;
}


int Notification::delete_notification(int order_id, int user_id, string message) {
	vector<string> database;
	string record;
	string u_id, o_id, msg;

	ifstream infile;
	infile.open(notifications_file_name);
	getline(infile, record);
	database.push_back(record);
	while (getline(infile, record)) {
		stringstream line(record);
		getline(line, u_id, ',');
		getline(line, o_id, ',');
		getline(line, msg, ',');

		if (stoi(u_id) != user_id || stoi(o_id) != order_id || msg.compare(message) != 0)
			database.push_back(record);
	}
	infile.close();

	ofstream outfile;
	outfile.open(notifications_file_name);
	for (string str : database)
		outfile << str << endl;
	outfile.close();
	return 1;
}