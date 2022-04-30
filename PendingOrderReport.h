#pragma once
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include "Order.h"

using namespace std;

class PendingOrderReport {
private:

public:
	static int generate_pending_orders_report(vector<int> order_ids);
	static void display_order(int order_id);
};