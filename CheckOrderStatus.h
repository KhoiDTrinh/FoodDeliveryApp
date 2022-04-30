#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Order.h"

using namespace std;

class CheckOrderStatus {
private:

public:
	static int check_order_status_customer(int user_id);
	static int check_order_status_driver(int user_id);
};