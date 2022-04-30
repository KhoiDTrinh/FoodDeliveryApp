#include "PendingOrderReport.h"
/*Artifact Name: Pending Order Report
* Receives a vector of Order IDs which will be iterarated through to display 
* each individual order
* Mitzi Lezama
* Khoi Trinh
* 4/14/2022
*/
using namespace std;

/*Artifact Name: generate_orders_report
* Receives a vector of all order_ids
* Mitzi Lezama
* 4/14/2022
*/
int PendingOrderReport::generate_pending_orders_report(vector<int> order_ids) {
	cout << "Pending Orders Report\n";
	cout << "---------------------\n\n";
	//for loop iterates through each order ID
	for (int order_id : order_ids)
		//send one order ID to display_order so it can be displayed individually
		display_order(order_id);
	return 1;
}
/*Artifact Name: generate_orders_report
* received an individual order ID
* Mitzi Lezama
* Khoi Trinh
* 4/14/2022
*/
void PendingOrderReport::display_order(int order_id) {
	cout << "Order ID: " << order_id << endl;
	Order order(order_id);
	//get vector of Items from Order class
	vector<Order::OrderItem> items_list = order.get_order_items_list();

	//for loop prints items
	for (auto item : items_list) {
		cout << order.get_item_by_id(item.item_id).item_name << endl;
		
		//function call to print quantity of items
		if(!item.comments.empty())
			cout << "\t" << item.comments << endl;
		//function call to print comments of items
		cout << "\tx" << item.quantity << endl << endl << endl;
	}
}