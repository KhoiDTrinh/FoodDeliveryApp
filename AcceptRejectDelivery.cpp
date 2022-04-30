#include "AcceptRejectDelivery.h"

using namespace std;

/*
Date: April 29, 2022
Name: William Cao(Phuoc)
Artifact Name: Accept Delivery Function

Description:
	send over to notification class Order ID, Driver ID, and "New Delivery" message. then return the fucntion update the 
	driver with driver ID pass.
*/
int AcceptRejectDelivery::accept_delivery(int order_id, int driver_id){
	Notification::delete_notification(order_id, driver_id, "new delivery");
	Order order(order_id);
	return order.update_driver(driver_id);
}

/*
Date: April 29, 2022
Name: William Cao(Phuoc)
Artifact Name: Reject Delivery Function

Description:
	send over to notification class Order ID, Driver ID, and "New Delivery" message. Then return the function find Driver.
*/
int AcceptRejectDelivery::reject_delivery(int order_id, int driver_id) {
	Notification::delete_notification(order_id, driver_id, "new delivery");
	Order order(order_id);
	return order.find_driver();
}


/*
Date: April 29, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: New Delivery Requests Function

Description:
	The function read in notification file, then get new order from notification file.
*/
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