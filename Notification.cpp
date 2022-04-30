#include "Notification.h"

/*
Date: April 8, 2022
Name: William Cao(Phuoc)
Artifact Name: Notifiucation Class

Description:
	notify to driver, restaurant, and customer for case of event, like new delivery, ordered delivery, 
	new order and restaurant declined order. The notification is include order id, user id, and message if necessary.
	every thing will be send to notifications.txt file. 

*/

using namespace std;

string Notification::notifications_file_name = "Notifications.txt";


/*
Date: April 8, 2022
Name: William Cao(Phuoc)
Artifact Name: Send New Delivery Alert Driver Function

Description:
	Pass message "New Delivery" to notification function with Order ID and Driver ID.
*/
int Notification::send_new_delivery_alert_driver(int order_id, int driver_id) {
	return send_notification(order_id, driver_id, "new delivery");
}

/*
Date: April 8, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: Send Delivered Alert Customer Function

Description:
	Pass message "Order Delivered" to notification function with Order ID and Customer ID.
*/
int Notification::send_delivered_alert_customer(int order_id, int customer_id) {
	return send_notification(order_id, customer_id, "order delivered");
}

/*
Date: April 8, 2022
Name: William Cao(Phuoc)
Artifact Name: Send Order Notification Restaurant Function

Description:
	Pass message "New Order" to notification function with Order ID and Restaurant ID.
*/
int Notification::send_order_notification_restaurant(int order_id, int restaurant_id) {
	return send_notification(order_id, restaurant_id, "new order");
}
	
/*
Date: April 8, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: Send Restaurant Delcine Customer Function

Description:
	Pass message "Retaurant Declined Order" to notification function with Order ID and Customer ID.
*/
int Notification::send_restaurant_decline_customer(int order_id, int customer_id) {
	return send_notification(order_id, customer_id, "retaurant declined order");
}

/*
Date: April 8, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: Send Notification Function

Description:
	output the message, Order Id, and User ID to file. Then return 1;
*/
int Notification::send_notification(int order_id, int user_id, string message) {
	string output = to_string(user_id) + "," + to_string(order_id) + "," + message;
	ofstream file;
	file.open(notifications_file_name, ios::app);
	file << output << endl;
	file.close();
	return 1;
}

/*
Date: April 8, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: Delete Notification Function

Description:
	Delete notification
*/
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
		getline(line, u_id, ',');		//user ID
		getline(line, o_id, ',');		//Order ID
		getline(line, msg, ',');		//Message

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