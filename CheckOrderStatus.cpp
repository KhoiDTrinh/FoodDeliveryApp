#include "CheckOrderStatus.h"
/* Artifact Name: Check Order Status
* Searches the database for all active orders with matching customer_id
* Send the order_id and status to boundary class OrderStatus to display results
* Mitzi Lezama
* 4/30/2022
*/
using namespace std;

/* Artifact Name: check_order_status_customer
* receives user_id from a customer, matches it to an 
* order and sends order_id, and status to Order Status class
* Mitzi Lezama
* 4/30/2022
*/

int CheckOrderStatus::check_order_status_customer(int user_id) {
	//create vector pair for order_id, status
	vector<pair<int, int>> order_statuses;
	
	string record;
	string o_id, u_id;
	int status;

	ifstream file;
	//open the file that conatins orders info
	file.open(Order::orders_file_name);
	getline(file, record);
	//while there's a line in the file
	while (getline(file, record)) {
		stringstream line(record);
		//first string before comma is order_id
		getline(line, o_id, ',');
		//second string after comma is user_id
		getline(line, u_id, ',');
		//validating user_id
		if (stoi(u_id) == user_id) {
			status = stoi(record.substr(record.length() - 1, 1));
			if(status <= OrderStatus::inactive)
				//add order_id and status to the order status vector 
				order_statuses.push_back(pair<int, int>(stoi(o_id), status));
		}
	}
	file.close();

	//return vector to Order Status class in display_order_status function to print out
	//to screen for user to see
	return OrderStatus::display_order_status(order_statuses);
}


/* Artifact Name: check_order_status_customer
* receives user_id from a driver
* receives user_id from a customer, matches it to an
* order and sends order_id, and status to Order Status class
* Khoi Trinh
* 4/30/2022
*/

int CheckOrderStatus::check_order_status_driver(int driver_id) {
	//create vector pair for order_id, status
	vector<pair<int, int>> order_statuses;

	string record;
	string o_id, d_id;
	int status;

	ifstream file;
	file.open(Order::orders_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		//first string before comma is order_id
		getline(line, o_id, ',');
		//second string after comma is user_id
		getline(line, d_id, ',');
		//third string after comma is driver_id
		getline(line, d_id, ',');
		//validating driver_id
		if (stoi(d_id) == driver_id) {
			status = stoi(record.substr(record.length() - 1, 1));
			if (status <= OrderStatus::delivered)
				//add order_id and status to the order status vector 
				order_statuses.push_back(pair<int, int>(stoi(o_id), status));
		}
	}
	file.close();
	//return vector to Order Status class in display_order_status function to print out
	//to screen for user to see
	return OrderStatus::display_order_status(order_statuses);
}