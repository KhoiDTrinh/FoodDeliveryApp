#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class OrderStatus {
public:
	static int display_order_status(vector<pair<int, int>> order_statuses);
};