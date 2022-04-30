#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "SignIn_Up.h"
#include "UserInformation.h"
#include "UpdateInfo.h"
#include "Restaurant.h"
#include "UpdateMenu.h"
#include "Search.h"
#include "Order.h"
#include "CreateOrder.h"
#include "CheckOrderStatus.h"
#include "OrderStatus.h"
#include "AcceptRejectDelivery.h"
#include "AcceptDeclineOrder.h"
#include "ConfirmDelivery.h"
#include "ShowPendingOrders.h"


using namespace std;

class UserInterface {
private:
	UserInformation* user_record = nullptr;
	Restaurant* restaurant_record = nullptr;

	const int UI_MENU_WIDTH = 50;		//Width of the user interface in number of characters
	const int UI_MENU_HEIGHT = 15;		//Max number of items displayed in the user interface menu

	const double TAX_RATE = 0.0825;

	void display_start_up_screen();
	void display_home_screen();

	void display_customer_home_screen();
	void display_driver_home_screen();
	void display_restaurant_home_screen();

	void display_update_menu_screen();


	//-------------------- All Users Functions --------------------
	void sign_in();
	void sign_up();
	void update_personal_info();

	//-------------------- Customer Functions --------------------
	void check_order_status_customer();
	void create_new_order();
	int search_for_restaurant();
	int add_remove_items_to_order(CreateOrder& create_order);
	int add_item_to_order(CreateOrder& create_order);
	int remove_item_from_order(CreateOrder& create_order);
	int checkout_order(CreateOrder& create_order);
	int select_payment_option(CreateOrder& create_order);
	int use_saved_payment(CreateOrder& create_order);
	int enter_new_payment(CreateOrder& create_order);

	
	//-------------------- Driver Functions --------------------
	void accept_reject_delivery();
	void check_order_status_driver();
	void confirm_delivery();
	

	//-------------------- Restaurant Functions --------------------
	void accept_decline_order();
	void update_order_status();
	void show_pending_orders();
	void add_menu_item();
	void update_menu_item();
	void delete_menu_item();



	//-------------------- Helper Functions --------------------
	void display_menu(vector<string>& menu_options, string menu_title);
	int get_user_menu_selection(int max_valid_input);
	void clear_screen();
	void pause();
	void get_user_info(vector<string>& user_input);
	void get_restaurant_info(vector<string>& user_input);
	void get_menu_item_info(vector<string>& user_input);
	void get_restaurant_record();
public:
	UserInterface();
	~UserInterface();

	void run();
};