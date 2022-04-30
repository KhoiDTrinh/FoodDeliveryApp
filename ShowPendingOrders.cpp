#include"ShowPendingOrders.h"

/*Artifact name: show_pending_orders
* Receives the restaurant_id to print out their pending orders
* Mitzi Lezama
* 4/29/2022
*/ 

int ShowPendingOrders::show_pending_orders(int retaurant_id) {
	//vector int order_ids of all current active orders
	vector<int> order_ids = Order::get_active_orders_restaurants(retaurant_id);
	//Pending Order Report class will print out all detail from orders
	return PendingOrderReport::generate_pending_orders_report(order_ids);
}