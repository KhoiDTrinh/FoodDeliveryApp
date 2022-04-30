#include "AcceptRejectDelivery.h"

using namespace std;

int AcceptRejectDelivery::accept_delivery(int driver_id, int order_id)
{
	Order order(order_id);
	return order.update_driver(driver_id);
}

int AcceptRejectDelivery::reject_delivery(int order_id) {
	Order order(order_id);
	return order.find_driver();
}

vector<int> AcceptRejectDelivery::get_new_delivery_requests(int driver_id) {
	vector<int> order_ids;
	
	string record;
	string value;
	ifstream file;
	file.open(Notification::notifications_file_name);
	getline(file, record);
	while(getline(file, record)) {
		stringstream line(record);
		getline(line, value, ',');
		if (stoi(value) == driver_id) {
			getline(line, value, ',');
			order_ids.push_back(stoi(value));
		}
		
	}
	file.close();

	return order_ids;
}