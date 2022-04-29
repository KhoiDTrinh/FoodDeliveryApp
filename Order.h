#pragma once
#include <iostream>
#include <string>
#include "UpdateOrderStatus.h"
#include "Cart.h"
#include "Alert.h"
#include "OrderStatus.h"
#include "Restaurant.h"

using namespace std;

class Order {
public:
	static string orders_file_name;

	struct OrderItem {
		int item_id;
		int quantity;
		string comments;
	};


	//-------------------- Public Functions --------------------
	vector<pair<int,string>> get_menu_options();



	//-------------------- Getter/Setter --------------------
	int get_order_id() { return order_id; }
	int get_user_id() { return user_id; }
	int get_driver_id() { return driver_id; }
	int get_restaurant_id() { return restaurant_id; }
	string get_delivery_address() { return delivery_address; }
	void set_user_id(int id) { user_id = id; }
	void set_driver_id(int id) { driver_id = id; }
	void set_restaurant_id(int id) { restaurant_id = id; }
	void set_delivery_address(string address) { delivery_address = address; }

	//-------------------- Constructor/Destructors --------------------
	Order(int u_id = 0, int r_id = 0, string address = "");
	Order(string record);
	~Order();
private:
	//-------------------- Private Attributes --------------------
	int order_id, user_id, driver_id, restaurant_id;
	string delivery_address;
	int order_status;

	Restaurant* restaurant = nullptr;
	vector<OrderItem> order_items;

	//-------------------- Private Helper Functions --------------------
	int get_next_order_id();
	void load_restaurant_record();
};