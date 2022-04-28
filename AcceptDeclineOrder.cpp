#include "AcceptDeclineOrder.h"

int AcceptDeclineOrder::accept_order(int order_id) {
	UpdateOrderStatus::update_order_status(order_id, 1);
	return 1;
}

int AcceptDeclineOrder::decline_order(int order_id) {
	UpdateOrderStatus::update_order_status(order_id, 9);
	Alert::restaurant_decline(order_id);
	return 1;
}