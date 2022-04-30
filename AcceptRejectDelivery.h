#pragma once
#include <iostream>
#include "Order.h"
#include <string>

using namespace std;

class AcceptRejectDelivery {
private:
public:
	static int accept_delivery(int order_id, int driver_id);
	static int reject_delivery(int order_id, int driver_id);
	static vector<int> get_new_delivery_requests(int driver_id);
};