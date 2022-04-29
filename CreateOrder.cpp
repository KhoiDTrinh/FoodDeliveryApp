#include "CreateOrder.h"

int CreateOrder::start_new_order(int user_id, int restaurant_id, string address) {
	order.set_user_id(user_id);
	order.set_restaurant_id(restaurant_id);
	order.set_delivery_address(address);


	return 1;
}

int CreateOrder::get_menu_options() {
	order.get_menu_options();
}