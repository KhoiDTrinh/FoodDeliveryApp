#include "Order.h"

using namespace std;

string Order::orders_file_name = "Orders.txt";
string Order::order_items_file_name = "OrderItems.txt";

//-------------------- Constructor/Destructors --------------------
Order::Order() {
	order_id = get_next_order_id();
	user_id = 0;
	driver_id = 0;
	restaurant_id = 0;
	delivery_address = "";
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

int Order::add_item_to_order(int item_id, int quantity, string comment) {
	order_items.push_back(OrderItem(item_id, quantity, comment));
	return 1;
}

Restaurant::MenuItem Order::get_item_by_id(int item_id) {
	load_restaurant_record();
	return restaurant->get_item_by_id(item_id);
}

int Order::remove_item_from_order(Order::OrderItem item) {
	for (auto itr = order_items.begin(); itr != order_items.end(); ++itr) {
		if ((*itr) == item) {
			order_items.erase(itr);
			return 1;
		}
	}

	return 0;
}

vector<Order::OrderItem> Order::get_order_items_list() {
	return order_items;
}

int Order::generate_order(string address) {
	string output = to_string(order_id) + ",";
	output += to_string(user_id) + ",";
	output += to_string(driver_id) + ",";
	output += to_string(restaurant_id) + ",";
	output += address + ",";
	output += "0";

	ofstream file;
	file.open(orders_file_name, ios::app);
	file << output << endl;
	file.close();


	file.open(order_items_file_name, ios::app);
	for (auto item : order_items) {
		output = to_string(order_id) + ",";
		output += to_string(item.item_id) + ",";
		output += to_string(item.quantity) + ",";
		output += item.comments;
		file << output << endl;
	}
	file.close();

	return 1;
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