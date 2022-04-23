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

using namespace std;

class UserInterface {
private:
	UserInformation* user_record = nullptr;
	Restaurant* restaurant_record = nullptr;

	const int UI_MENU_WIDTH = 50;		//Width of the user interface in number of characters
	const int UI_MENU_HEIGHT = 15;		//Max number of items displayed in the user interface menu

	void display_start_up_screen();
	void display_home_screen();

	void display_customer_home_screen();
	void display_driver_home_screen();
	void display_restaurant_home_screen();

	void display_update_menu_screen();


	void sign_in();
	void sign_up();

	void add_menu_item();
	void update_menu_item();
	void delete_menu_item();

	void update_personal_info();


	//-------------------- Helper Functions --------------------
	void display_menu(vector<string>& menu_options, string menu_title);
	int get_user_menu_selection(int max_valid_input);
	void clear_screen();
	void get_user_info(vector<string>& user_input);
	void get_restaurant_info(vector<string>& user_input);
	void get_menu_item_info(vector<string>& user_input);
	void get_restaurant_record();
public:
	UserInterface();
	~UserInterface();

	void run();
};