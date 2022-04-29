#pragma once
#include "Order.h"
#include "SubmitPayment.h"

class CreateOrder {
private:
	Order order;
public:
	int start_new_order(int user_id, int restaurant_id, string address);
	vector<pair<int, string>>  get_menu_options();

	Restaurant::MenuItem get_item_by_id(int item_id);
	int add_item_to_order(int item_id, int quantity, string comment);

	vector<Order::OrderItem> get_order_items_list();
	int remove_item_from_order(Order::OrderItem item);

	vector<pair<string, string>> get_saved_payments(int user_id);
	int submit_payment(string payment_info, double tax_rate, string address, bool save_payment = false);

	double get_total_price(double tax_rate = 0);
};