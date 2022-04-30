#include "UpdateOrderStatus.h"

/*
Date: April 29, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact Name: Update Order Status Function

Description:
	Mark the order status, and send that to Order class with Order ID.
*/
int UpdateOrderStatus::update_order_status(int order_id, int status) {
	Order order(order_id);
	return order.update_order_status(status);
}