#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "UpdateOrderStatus.h"

using namespace std;

class ConfirmDelivery {

private:

public:
	static int confirm_delivery(int order_id);
	static vector<int> get_active_orders(int driver_id);
};