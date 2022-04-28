#pragma once
#include <iostream>
#include "Order.h"
#include <string>

using namespace std;

class AcceptRejectDelivery {
private:
public:
	static int accept_delivery(int driver_id, int order_id);
	static int reject_delivery(int order_id);
};