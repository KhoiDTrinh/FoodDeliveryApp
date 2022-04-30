#pragma once
#include <iostream>
#include<fstream>
#include "Alert.h"
#include <string>

using namespace std;

class Notification {
private:
	static int send_notification(int order_id, int user_id, string message);
public:
	static string notifications_file_name;
	static int send_new_delivery_alert_driver(int order_id, int driver_id);
	static int send_delivered_alert_customer(int order_id, int customer_id);
	static int send_order_notification_restaurant(int order_id, int restaurant_id);
	static int send_restaurant_decline_customer(int order_id, int customer_id);
};