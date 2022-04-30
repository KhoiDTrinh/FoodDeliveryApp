#include "OrderStatus.h"

using namespace std;

//function receives vector of pair<int,int> of order_id, status
int OrderStatus::display_order_status(vector<pair<int, int>> order_statuses) {
	cout << "Displaying order status\n";
	cout << "-----------------------\n\n";

	for (auto order : order_statuses) {
		int status = order.second;					//second stores the status of the order
		cout << "Order #" << order.first << endl;	//first stores the order id

		//switch between the different types of status and prints time
		switch (status) {
		case 0:
			cout << "Order is being Reviewed\n";
			break;
		case 1:
			cout << "Order has been Confirmed\n";
			break;
		case 2:
			cout << "Order is being Prepared\n";
			break;
		case 3:
			cout << "Order has been Completed\n";
			break;
		case 4:
			cout << "Order has been Delivered\n";
			break;
		case 5:
			cout << "Order has been declined by the restaurant\n";
			break;
		case 6:
			cout << "No driver available. Order canceled\n";
		case 9:
			cout << "Order is inactive\n";
			break;
		default:
			cout << "Invalid argument in OrderStatus::display_order_status()\n\n";
		}

	}

	return 1;
}