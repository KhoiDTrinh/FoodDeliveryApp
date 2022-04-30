#include "AcceptDeclineOrder.h"


/*
Date: April 29, 2022
Name: William Cao(Phuoc)
Artifact Name: Accept Function

Description:
	Send Update Order Status Order ID, and update the status to Confirmed. Send over Notification to Restaurant
	with Order ID, Restaurant ID, and sned mesasage "New Order".
*/
int AcceptDeclineOrder::accept_order(int order_id, int restaurant_id) {
	Notification::delete_notification(order_id, restaurant_id, "new order");
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::confirmed);
}


/*
Date: April 29, 2022
Name: William Cao(Phuoc)
Artifact Name: Decline Function

Description:
	Send Update Order Status Order ID, and update the status to Declined. Send over Notification to Restaurant
	with Order ID, Restaurant ID, and sned mesasage "New Order". 
*/
int AcceptDeclineOrder::decline_order(int order_id, int restaurant_id) {
	Notification::delete_notification(order_id, restaurant_id, "new order");
	Order order(order_id);
	Alert::restaurant_decline(order_id, order.get_user_id());
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::declined);
}


/*
Date: April 29, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: New Order Requests Function

Description:
	The function read in notification file, then get new order from notification file.
*/
vector<int> AcceptDeclineOrder::get_new_order_requests(int restaurant_id) {
	vector<int> order_ids;

	string record;
	string u_id, o_id, message;
	ifstream file;
	file.open(Notification::notifications_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, u_id, ',');
		if (stoi(u_id) == restaurant_id) {
			getline(line, o_id, ',');
			getline(line, message, ',');
			if(message.compare("new order") == 0)
				order_ids.push_back(stoi(o_id));
		}
	}
	file.close();

	return order_ids;
}