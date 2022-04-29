#include "CreateOrder.h"

int CreateOrder::start_new_order(int user_id, int restaurant_id, string address) {
	order.set_user_id(user_id);
	order.set_restaurant_id(restaurant_id);
	order.set_delivery_address(address);


	return 1;
}

vector<pair<int, string>>  CreateOrder::get_menu_options() {
	return order.get_menu_options();;
}


int CreateOrder::add_item_to_order(int item_id, int quantity, string comment) {
	return order.add_item_to_order(item_id, quantity, comment);
}

Restaurant::MenuItem CreateOrder::get_item_by_id(int item_id) {
	return order.get_item_by_id(item_id);
}


int CreateOrder::remove_item_from_order(Order::OrderItem item) {
	return order.remove_item_from_order(item);
}

vector<Order::OrderItem> CreateOrder::get_order_items_list() {
	return order.get_order_items_list();
}

vector<pair<string,string>> CreateOrder::get_saved_payments(int user_id) {
	string record;
	string value;
	vector<pair<string, string>> saved_cc;

	ifstream file;
	file.open(UserInformation::cc_info_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, value, ',');
		if (stoi(value) == user_id) {
			string last_four_cc = "************";
			last_four_cc += value.substr(value.length() - 4, 4);
			saved_cc.push_back(pair<string, string>(last_four_cc, record));
		}
	}
	file.close();

	return saved_cc;
}

int CreateOrder::submit_payment(string payment_info, double tax_rate, string address, bool save_payment) {
	if (save_payment) {
		ofstream file;
		file.open(UserInformation::cc_info_file_name, ios::app);
		file << payment_info << endl;
		file.close();
	}
	
	int result =  SubmitPayment::submit_payment(order.get_order_id(), get_total_price(tax_rate), payment_info);

	if (result == 1)
		result = order.generate_order(address);

	return result;
}

double CreateOrder::get_total_price(double tax_rate) {
	double total = 0.00;
	auto order_list = order.get_order_items_list();
	for (auto item : order_list) {
		total += order.get_item_by_id(item.item_id).item_price * item.quantity;
	}
	total *= (1 + tax_rate);
	return total;
}