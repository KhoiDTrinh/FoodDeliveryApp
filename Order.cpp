#include "Order.h"

using namespace std;

string Order::orders_file_name = "Orders.txt";
string Order::order_items_file_name = "OrderItems.txt";

//-------------------- Constructor/Destructors --------------------
//Default Constructor
//Default constructor with base values, order_id is still generated and unique
//Khoi Trinh
//04/29/22
Order::Order() {
	order_id = get_next_order_id();
	user_id = 0;
	driver_id = 0;
	restaurant_id = 0;
	delivery_address = "";
	order_status = -1;
}

//Constructor from Record string
//Constructor using record from database
//Khoi Trinh
//04/29/22
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
	
	//Loads restaurant info from database
	load_restaurant_record();
}

//Constructor from Order ID
//Constructor using order_id, searches database for order by order_id,
// then generates Order Object based on that database record
//Khoi Trinh
//04/29/22
Order::Order(int id) {
	string record;
	string value;

	ifstream file;
	file.open(orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, value, ',');
		if (id == stoi(value)) {
			order_id = id;
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
			break;
		}
	}
	file.close();
	load_restaurant_record();
}

//Destructor
//Basic destructor for dynamic variables
//Khoi Trinh
//04/29/22
Order::~Order() {
	delete restaurant;
}


//-------------------- Public Functions --------------------

//Get Menu Options
//Loads the restaurant record and gets list of menu options from it
//Khoi Trinh
//04/29/22
vector<pair<int, string>> Order::get_menu_options() {
	load_restaurant_record();
	return restaurant->get_list_menu_item_names();
}

//Add Item to Order
//Creates an OrderItem object and pushes to list of order_items
//Khoi Trinh
//04/29/22
int Order::add_item_to_order(int item_id, int quantity, string comment) {
	order_items.push_back(OrderItem(item_id, quantity, comment));
	return 1;
}

//Get Item by ID
//Searches restaurant menu list for MenuItem object based on item_id
//Khoi Trinh
//04/29/22
Restaurant::MenuItem Order::get_item_by_id(int item_id) {
	load_restaurant_record();
	return restaurant->get_item_by_id(item_id);
}

//Remove Item from Order
//Searches for item in order items list and removes it
//Khoi Trinh
//04/29/22
int Order::remove_item_from_order(Order::OrderItem item) {
	for (auto itr = order_items.begin(); itr != order_items.end(); ++itr) {
		if ((*itr) == item) {
			order_items.erase(itr);
			return 1;
		}
	}

	return 0;
}

//Get Order Items List
//Reloads items in order from database and returns list
//Khoi Trinh
//04/29/22
vector<Order::OrderItem> Order::get_order_items_list() {
	load_order_items_list();
	return order_items;
}

//Generate Orrder
//Fully creates a new order record in database, sends appropriate notifications
//Khoi Trinh
//04/29/22
int Order::generate_order(string address) {
	//Generate record to add to orders database
	string output = to_string(order_id) + ",";
	output += to_string(user_id) + ",";
	output += to_string(driver_id) + ",";
	output += to_string(restaurant_id) + ",";
	output += address + ",";
	output += "0";

	//Write to database
	ofstream file;
	file.open(orders_file_name, ios::app);
	file << output << endl;
	file.close();

	//Write order items to order items database
	file.open(order_items_file_name, ios::app);
	for (auto item : order_items) {
		output = to_string(order_id) + ",";
		output += to_string(item.item_id) + ",";
		output += to_string(item.quantity) + ",";
		output += item.comments;
		file << output << endl;
	}
	file.close();

	//Send alert to driver and restaurant
	find_driver();
	Alert::restaurant_new_order(order_id, restaurant_id);

	return 1;
}

//Update Order Status
//Updates order status in database
//Khoi Trinh
//04/29/22
int Order::update_order_status(int status) {
	vector<string> database;

	string record;
	string o_id;

	//Read database, edit required line, store rest back in database array
	ifstream infile;
	infile.open(orders_file_name);
	getline(infile, record);
	database.push_back(record);
	while (getline(infile, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		if (stoi(o_id) == order_id)
			record = record.substr(0, record.length() - 1) + to_string(status);
		database.push_back(record);
	}
	infile.close();

	//Rewrite array to database
	ofstream outfile;
	outfile.open(orders_file_name);
	for (string str : database)
		outfile << str << endl;
	outfile.close();
	return 1;
}

//Find a Driver
//Finds a random driver and sends alert to that driver
//Khoi Trinh
//04/29/22
int Order::find_driver() {
	if (Alert::find_driver(order_id) == -1)
		return UpdateOrderStatus::update_order_status(order_id, OrderStatus::no_driver);
	return 1;
}

//Update Driver in Database
//Updates the driver in the database
//Khoi Trinh
//04/29/22
int Order::update_driver(int new_driver_id) {
	vector<string> database;

	string record;
	string o_id, u_id, d_id, r_id, address, status;

	//Reads database, edits appropriate record, store all into array
	ifstream infile;
	infile.open(orders_file_name);
	getline(infile, record);
	database.push_back(record);
	while (getline(infile, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		getline(line, u_id, ',');
		getline(line, d_id, ',');
		getline(line, r_id, ',');
		getline(line, address, ',');
		getline(line, status, ',');

		if (stoi(o_id) == order_id) {
			record = o_id + ",";
			record += u_id + ",";
			record += to_string(new_driver_id) + ",";
			record += r_id + ",";
			record += address + ",";
			record += status;
		}
		database.push_back(record);
	}
	infile.close();

	//Rewrite array to database
	ofstream outfile;
	outfile.open(orders_file_name);
	for (string str : database)
		outfile << str << endl;
	outfile.close();
	return 1;
}

//Get Restaurant Address
//Getter function to get the address of a restaurant
//Khoi Trinh
//04/29/22
string Order::get_restaurant_address() {
	//Reload restaurant record from database
	load_restaurant_record();
	//Return restaurant address
	return restaurant->get_restaurant_address();
}

//Get Active Orders for Restaurant
//Searches database for all active orders based on restaurant_id and returns array of those order ids
//Khoi Trinh
//04/29/22
vector<int> Order::get_active_orders_restaurants(int restaurant_id) {
	vector<int> order_ids;

	string record;
	string o_id, r_id;
	ifstream file;
	file.open(orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		getline(line, r_id, ',');
		getline(line, r_id, ',');
		getline(line, r_id, ',');
		if (stoi(r_id) == restaurant_id) {
			order_ids.push_back(stoi(o_id));
		}
	}
	file.close();

	return order_ids;
}

//Get Active Orders for Drivers
//Searches database for all active orders based on driver_id and returns array of those order ids
//Khoi Trinh
//04/29/22
vector<int> Order::get_active_orders_drivers(int driver_id) {
	vector<int> order_ids;

	string record;
	string o_id, d_id;
	ifstream file;
	file.open(orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, o_id, ',');
		getline(line, d_id, ',');
		getline(line, d_id, ',');
		if (stoi(d_id) == driver_id) {
			order_ids.push_back(stoi(o_id));
		}
	}
	file.close();

	return order_ids;
}

//-------------------- Private Helper Functions --------------------
//Get Next Order ID
//Searches Database for last order id and generates next value
//Khoi Trinh
//04/29/22
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


//Load Restaurant Record
//Loads restaurant record if it is unloaded and there is a valid restaurant id
//Khoi Trinh
//04/29/22
void Order::load_restaurant_record() {
	if (!restaurant && restaurant_id > 0) {
		int result = Restaurant::get_restaurant_record(restaurant_id, restaurant);
		if (result == 0) {
			cout << "Fatal error in Order::load_restaurant_record\n\nTerminating application\n\n";
			exit(1);
		}
	}
}

//Load Order Items List
//Loads list of items in order from database
//Khoi Trinh
//04/29/22
void Order::load_order_items_list() {
	if (order_items.size() == 0) {
		string record;
		string o_id, i_id, qty, comm;

		ifstream file;
		file.open(order_items_file_name);
		getline(file, record);
		while (getline(file, record)) {
			stringstream line(record);
			getline(line, o_id, ',');
			getline(line, i_id, ',');
			getline(line, qty, ',');
			getline(line, comm, ',');

			if(stoi(o_id) == order_id)
				order_items.push_back(OrderItem(stoi(i_id), stoi(qty), comm));
		}
		file.close();
	}
}