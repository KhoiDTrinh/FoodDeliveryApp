#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Order.h"

using namespace std;

class UpdateOrderStatus{
public:
	static int update_order_status(int order_id, int status);
};