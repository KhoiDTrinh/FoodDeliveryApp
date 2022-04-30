#include "PendingOrderReport.h"

using namespace std;

//Receives all information from 1 order
int PendingOrderReport::generate_pending_orders_report(vector<int> order_ids) {
	cout << "Pending Orders Report\n";
	cout << "---------------------\n\n";

	for (int order_id : order_ids)
		display_order(order_id);
	return 1;
}

void PendingOrderReport::display_order(int order_id) {
	cout << "Order ID: " << order_id << endl;
	Order order(order_id);
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