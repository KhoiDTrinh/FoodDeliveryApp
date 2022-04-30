#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class OrderStatus {
public:
	static enum { review, confirmed, prepared, completed, delivered, declined, no_driver, inactive = 9};
	static int display_order_status(vector<pair<int, int>> order_statuses);
};