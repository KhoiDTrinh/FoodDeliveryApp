#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "Notification.h"
#include "UserInformation.h"

using namespace std; 

class Alert {
private:

public:
	static int find_driver(int order_id);
	static int customer_delivery(int order_id, int customer_id);
	static int restaurant_decline(int order_id, int customer_id);
	static int restaurant_new_order(int order_id, int restaurant_id);
};