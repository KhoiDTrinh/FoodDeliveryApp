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