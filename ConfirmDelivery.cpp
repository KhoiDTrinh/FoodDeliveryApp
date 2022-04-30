#include "ConfirmDelivery.h"

using namespace std;

int ConfirmDelivery::confirm_delivery(int order_id) {
	return UpdateOrderStatus::update_order_status(order_id, OrderStatus::delivered);
}