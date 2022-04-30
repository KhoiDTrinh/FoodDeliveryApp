#include "ConfirmDelivery.h"

/*
Date: April 24, 2022
Name: William Cao(Phuoc)
Artifact Name: Confirm Delivery Class

Description:
	The class send Order ID to UpdateOrderStatus with enum as delivered. 
*/

using namespace std;

/*
Date: April 24, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact name: Confirm Delivery Function

Description:
	return to UpdateOrderStatus Class with the order ID and mark it as delivered
*/
int ConfirmDelivery::confirm_delivery(int order_id) {
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::delivered);
}