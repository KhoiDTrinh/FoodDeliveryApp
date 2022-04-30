#pragma once
#include <iostream>
#include <string>
#include "UpdateOrderStatus.h"
#include "Alert.h"
#include "OrderStatus.h"
#include "Restaurant.h"

using namespace std;

class Order {
public:
	static string orders_file_name;
	static string order_items_file_name;

	struct OrderItem {
		int item_id;
		int quantity;
		string comments;

		OrderItem(int i, int q, string c) : item_id(i), quantity(q), comments(c) {}

		bool operator ==(const OrderItem& rhs) const {
			return (item_id == rhs.item_id) && (quantity == rhs.quantity) && (comments.compare(rhs.comments) == 0);
		}
	};


	//-------------------- Public Functions --------------------
	vector<pair<int,string>> get_menu_options();
	int add_item_to_order(int item_id, int quantity, string comment);
	int remove_item_from_order(Order::OrderItem item);
	int generate_order(string address);

	int update_order_status(int status);

	int update_driver(int driver_id);
	int find_driver();


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
	Restaurant::MenuItem get_item_by_id(int item_id);
	vector<Order::OrderItem> get_order_items_list();
	string get_restaurant_address();

	//-------------------- Constructor/Destructors --------------------
	Order();
	Order(string record);
	Order(int id);
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