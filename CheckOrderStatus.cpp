#include "CheckOrderStatus.h"

using namespace std;

//Searches the database for all active orders with matching customer_id
//Send the order_id and status to boundary class OrderStatus to display results
int CheckOrderStatus::check_order_status_customer(int user_id) {
	vector<pair<int, int>> order_statuses;
	
	string record;
	string o_id, u_id;
	int status;

	ifstream file;
	file.open(Order::orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		getline(line, u_id, ',');
		if (stoi(u_id) == user_id) {
			status = stoi(record.substr(record.length() - 1, 1));
			if(status <= 6)
				order_statuses.push_back(pair<int, int>(stoi(o_id), status));
		}
	}
	file.close();


	return OrderStatus::display_order_status(order_statuses);
}



//Searches the database for all active orders with matching driver_id
//Send the order_id and status to boundary class OrderStatus to display results
int CheckOrderStatus::check_order_status_driver(int driver_id) {
	vector<pair<int, int>> order_statuses;

	string record;
	string o_id, d_id;
	int status;

	ifstream file;
	file.open(Order::orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		getline(line, d_id, ',');
		getline(line, d_id, ',');
		if (stoi(d_id) == driver_id) {
			status = stoi(record.substr(record.length() - 1, 1));
			if (status <= 5)
				order_statuses.push_back(pair<int, int>(stoi(o_id), status));
		}
	}
	file.close();


	return OrderStatus::display_order_status(order_statuses);
}