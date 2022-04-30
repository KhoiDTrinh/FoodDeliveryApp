#include "OrderStatus.h"
/*Boundary class: Order Status 
* receives a vector pair of order_id and status
* and a switch case is used to print out order status
* Mitzi Lezama
* Khoi Trinh 
* 4/14/2022
*/
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
		case review:
			cout << "Order is being Reviewed\n";
			break;
		case confirmed:
			cout << "Order has been Confirmed\n";
			break;
		case prepared:
			cout << "Order is being Prepared\n";
			break;
		case completed:
			cout << "Order has been Completed\n";
			break;
		case delivered:
			cout << "Order has been Delivered\n";
			break;
		case declined:
			cout << "Order has been declined by the restaurant\n";
			break;
		case no_driver:
			cout << "No driver available. Order canceled\n";
		case inactive:
			cout << "Order is inactive\n";
			break;
		default:
			cout << "Invalid argument in OrderStatus::display_order_status()\n\n";
		}
		cout << endl;

	}

	return 1;
}