#include "Order.h"

using namespace std;

string Order::orders_file_name = "Orders.txt";

//-------------------- Constructor/Destructors --------------------
Order::Order(int u_id = 0, int r_id = 0, string address = "") {
	order_id = get_next_order_id();
	user_id = u_id;
	driver_id = 0;
	restaurant_id = r_id;
	delivery_address = address;
	order_status = -1;
}

Order::Order(string record) {
	string value;
	stringstream line(record);
	getline(line, value, ',');
	order_id = stoi(value);
	getline(line, value, ',');
	user_id = stoi(value);
	getline(line, value, ',');
	driver_id = stoi(value);
	getline(line, value, ',');
	restaurant_id = stoi(value);
	getline(line, value, ',');
	delivery_address = value;
	getline(line, value, ',');
	order_status = stoi(value);
}

Order::~Order() {
	delete restaurant;
}


//-------------------- Public Functions --------------------
vector<pair<int, string>> Order::get_menu_options() {
	load_restaurant_record();
	return restaurant->get_list_menu_item_names();
}


//-------------------- Private Helper Functions --------------------
int Order::get_next_order_id() {
	string record, id;
	int max_id = 1;

	ifstream file;
	file.open(orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, id, ',');
		max_id = stoi(id);
	}
	file.close();

	return max_id + 1;
}

void Order::load_restaurant_record() {
	if (!restaurant && restaurant_id > 0) {
		int result = Restaurant::get_restaurant_record(restaurant_id, restaurant);
		if (result == 0) {
			cout << "Fatal error in Order::load_restaurant_record\n\nTerminating application\n\n";
			exit(1);
		}
	}
}