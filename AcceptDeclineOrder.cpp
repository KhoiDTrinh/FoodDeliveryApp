#include "AcceptDeclineOrder.h"

int AcceptDeclineOrder::accept_order(int order_id) {
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::confirmed);
}

int AcceptDeclineOrder::decline_order(int order_id) {
	Order order(order_id);
	Alert::restaurant_decline(order_id, order.get_user_id());
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::declined);
}

vector<int> AcceptDeclineOrder::get_new_order_requests(int restaurant_id) {
	vector<int> order_ids;

	string record;
	string value;
	ifstream file;
	file.open(Notification::notifications_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, value, ',');
		if (stoi(value) == restaurant_id) {
			getline(line, value, ',');
			order_ids.push_back(stoi(value));
		}
	}
	file.close();

	return order_ids;
}