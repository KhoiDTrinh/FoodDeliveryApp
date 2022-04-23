#include "UpdateMenu.h"

string UpdateMenu::generate_database_entry(vector<string>& user_input)
{
	string output = "";
	for (int i = 0; i < user_input.size(); i++) {
		output += user_input[i];
		if (i != user_input.size() - 1)
			output += ",";
	}
	return output;
}

int UpdateMenu::add_menu_item(vector<string>& user_input, Restaurant*& restaurant)
{
	int result = restaurant->add_menu_item(user_input, generate_database_entry(user_input));
	return result;
}

int UpdateMenu::update_menu_item(vector<string>& user_input, Restaurant*& restaurant, int item_id)
{
	int result = restaurant->update_menu_item(user_input,item_id,generate_database_entry(user_input));
	return result;
}

int UpdateMenu::delete_menu_item(Restaurant*& restaurant, int item_id)
{
	int result = restaurant->delete_menu_item(item_id);
	return result;
}
