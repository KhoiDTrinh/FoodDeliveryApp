#include "ConfirmDelivery.h"

using namespace std;

int ConfirmDelivery::confirm_delivery(int order_id) {
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::delivered);
}

vector<int> ConfirmDelivery::get_active_orders(int driver_id) {
	vector<int> order_ids;

	string record;
	string o_id, u_id;

	ifstream file;
	file.open(Order::orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		getline(line, u_id, ',');
		if (stoi(u_id) == driver_id) {
			order_ids.push_back(stoi(o_id));
		}
	}
	file.close();

	return order_ids;
}
