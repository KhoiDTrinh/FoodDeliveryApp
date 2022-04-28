#include "AcceptRejectDelivery.h"

using namespace std;

int AcceptRejectDelivery::accept_delivery(int driver_id, int order_id)
{
	Order order(order_id);
	return order.update_driver(driver_id);
}

int AcceptRejectDelivery::reject_delivery(int order_id) {
	Order order(order_id);
	return order.find_driver();
}
