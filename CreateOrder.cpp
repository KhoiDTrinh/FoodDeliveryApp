#include "CreateOrder.h"

//Start New Order
//Initializes variables to create a new order
//Khoi Trinh
//04/27/2022
int CreateOrder::start_new_order(int user_id, int restaurant_id, string address) {
	order.set_user_id(user_id);
	order.set_restaurant_id(restaurant_id);
	order.set_delivery_address(address);


	return 1;
}

//Get Menu Options
//Gets current menu items from Order and 
//Khoi Trinh
//04/27/2022
vector<pair<int, string>>  CreateOrder::get_menu_options() {
	return order.get_menu_options();;
}

//Add Item to Order
//Adds given item to order with quantity and comments
//Khoi Trinh
//04/27/2022
int CreateOrder::add_item_to_order(int item_id, int quantity, string comment) {
	return order.add_item_to_order(item_id, quantity, comment);
}

//Get Item by Id
//Searches for item by id and returns item information
//Khoi Trinh
//04/27/2022
Restaurant::MenuItem CreateOrder::get_item_by_id(int item_id) {
	return order.get_item_by_id(item_id);
}

//Remove Item from Order
//Removes existing item from the order
//Khoi Trinh
//04/27/2022
int CreateOrder::remove_item_from_order(Order::OrderItem item) {
	return order.remove_item_from_order(item);
}

//Get Order Items List
//Gets list of all items currently in the order
//Khoi Trinh
//04/27/2022
vector<Order::OrderItem> CreateOrder::get_order_items_list() {
	return order.get_order_items_list();
}

//Get Saved Payments
//Searches database for all saved payments based on user_id, returns list of payment options
//Khoi Trinh
//04/27/2022
vector<pair<string,string>> CreateOrder::get_saved_payments(int user_id) {
	string record;
	string value;
	vector<pair<string, string>> saved_cc;

	//Read database and store matches in vector
	ifstream file;
	file.open(UserInformation::cc_info_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, value, ',');
		if (stoi(value) == user_id) {
			//Formats cc number to hide full number
			getline(line, value, ',');
			string last_four_cc = "************";
			last_four_cc += value.substr(value.length() - 4, 4);
			saved_cc.push_back(pair<string, string>(last_four_cc, record));
		}
	}
	file.close();

	return saved_cc;
}

//Submit Payment
//Submits payment and generates the order if payment successful
//Khoi Trinh
//04/27/2022
int CreateOrder::submit_payment(string payment_info, double tax_rate, string address, bool save_payment) {
	//If user selected to save payment information, save the new info to database
	if (save_payment) {
		ofstream file;
		file.open(UserInformation::cc_info_file_name, ios::app);
		file << payment_info << endl;
		file.close();
	}
	
	//Try to submit payment
	int result =  SubmitPayment::submit_payment(order.get_order_id(), get_total_price(tax_rate), payment_info);

	//If successful, generates an order
	if (result == 1)
		result = order.generate_order(address);

	return result;
}

//Get Total Price
//Returns total price of order with given tax_rate
//Khoi Trinh
//04/27/2022
double CreateOrder::get_total_price(double tax_rate) {
	double total = 0.00;
	//Get list of all items in order
	auto order_list = order.get_order_items_list();
	//For each item, multiply price and quantity, sum in total
	for (auto item : order_list) {
		total += order.get_item_by_id(item.item_id).item_price * item.quantity;
	}
	//Apply tax rate
	total *= (1 + tax_rate);
	return total;
}