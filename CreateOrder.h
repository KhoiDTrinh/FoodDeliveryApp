#pragma once
#include "Order.h"

class CreateOrder {
private:
	Order order;
public:
	int start_new_order(int user_id, int restaurant_id, string address);
	int get_menu_options();
};