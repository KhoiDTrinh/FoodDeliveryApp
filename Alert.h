#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Notification.h"

using namespace std; 

class Alert {
private:

public:
	static int find_Driver(int order_ID);
	static int customer_Delivery(ifstream &picture);
	static int restaurant_Decline(string reason);
	static int restaurant_New_Order(string name);
};