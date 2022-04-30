#include "UpdateOrderStatus.h"

int UpdateOrderStatus::update_order_status(int order_id, int status) {
	Order order(order_id);
	return order.update_order_status(status);
}