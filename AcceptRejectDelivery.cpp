#include "AcceptRejectDelivery.h"

using namespace std;

int AcceptRejectDelivery::accept_delivery(int order_id, int driver_id){
	Notification::delete_notification(order_id, driver_id, "new delivery");
	Order order(order_id);
	return order.update_driver(driver_id);
}

int AcceptRejectDelivery::reject_delivery(int order_id, int driver_id) {
	Notification::delete_notification(order_id, driver_id, "new delivery");
	Order order(order_id);
	return order.find_driver();
}

vector<int> AcceptRejectDelivery::get_new_delivery_requests(int driver_id) {
	vector<int> order_ids;
	
	string record;
	string u_id, o_id, message;
	ifstream file;
	file.open(Notification::notifications_file_name);
	getline(file, record);
	while(getline(file, record)) {
		stringstream line(record);
		getline(line, u_id, ',');
		if (stoi(u_id) == driver_id) {
			getline(line, o_id, ',');
			getline(line, message, ',');
			if (message.compare("new delivery") == 0);
				order_ids.push_back(stoi(o_id));
		}
	}
	file.close();

	return order_ids;
}