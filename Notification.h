#pragma once
#include <iostream>
#include<fstream>
#include "Alert.h"
#include <string>

using namespace std;

class Notification {
private:
	

public:
	static int send_Delivery_Alert_Driver(int order_ID);
	static int send_Delivery_Alert_Customer(ifstream &picture);
	static int send_Order_Alert_Restaurant(string name);
	static int send_Restaurant_Decline_Customer(string reason);

};