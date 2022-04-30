#include "ShowPendingOrders.h"

int ShowPendingOrders::show_pending_orders(int retaurant_id) {
	vector<int> order_ids = Order::get_active_orders_restaurants(retaurant_id);
	return PendingOrderReport::generate_pending_orders_report(order_ids);
}