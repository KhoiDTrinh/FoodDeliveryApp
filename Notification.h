#pragma once
#include <iostream>
#include<fstream>
#include "Alert.h"
#include <string>

using namespace std;

class Notification {
private:

	

public:
	static void send_Delivery_Alert_Driver(int order_ID);
	static void send_Delivery_Alert_Customer();
	static void send_Order_Alert_Restaurant();
	static void send_Restaurant_Decline_Customer(string reason);

};