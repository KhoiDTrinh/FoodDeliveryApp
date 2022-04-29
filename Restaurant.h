#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Restaurant {
public:
	struct MenuItem {
		int menu_item_id;
		string item_name;
		string item_description;
		double item_price;

		MenuItem(int i, string n, string d, double p) : menu_item_id(i), item_name(n), item_description(d), item_price(p) {}
	};

	//-------------------- Static File Names --------------------
	static string restaurant_file_name;
	static string menu_file_name;

	//-------------------- Constructor --------------------
	Restaurant(string record);

	//-------------------- Getter/Setter --------------------
	string get_restaurant_name() { return name; }
	string get_restaurant_address() { return address; }
	string get_restaurant_category() { return category; }
	vector<pair<int,string>> get_list_menu_item_names();
	MenuItem get_item_by_id(int item_id);

	//-------------------- Static Functions --------------------
	static int add_new_restaurant(vector<string>& user_input, Restaurant*& record);
	static int get_restaurant_record(int id, Restaurant*& record);

	//-------------------- Public Functions --------------------
	int add_menu_item(vector<string>& user_input, string database_entry);
	int update_menu_item(vector<string>& user_input, int item_id, string database_entry);
	int delete_menu_item(int item_id);
	void update_menu_item_list();

private:
	//-------------------- Private Attributes --------------------
	int restaurant_id;
	string name, address, category;
	vector<MenuItem> menu_items;

	//-------------------- Helper Functions --------------------
	int get_next_menu_id();
	void load_menu_items_to_array();
	void add_menu_item_to_array(string record);
};