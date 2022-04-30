#pragma once
#include <iostream>
#include "Order.h"
#include <string>
#include "UpdateOrderStatus.h"
#include "Alert.h"

class AcceptDeclineOrder {
private:

public:
	static int accept_order(int order_id);
	static int decline_order(int order_id);
	static vector<int> get_new_order_requests(int restaurant_id);
};