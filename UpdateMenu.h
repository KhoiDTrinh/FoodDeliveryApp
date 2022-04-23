#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Restaurant.h"

using namespace std;

class UpdateMenu {
private:
	static string generate_database_entry(vector<string>& user_input);
public:
	static int add_menu_item(vector<string>& user_input, Restaurant*& restaurant);
	static int update_menu_item(vector<string>& user_input, Restaurant*& restaurant, int item_id);
	static int delete_menu_item(Restaurant*& restaurant, int item_id);
};