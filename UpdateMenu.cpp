#include "UpdateMenu.h"
/*Artifact name: generate_database_entry
* Gets the user input from a string vector and will 
* store it in a string with commas in between each entry
* Khoi Trinh
* 4/23/2022
*/
string UpdateMenu::generate_database_entry(vector<string>& user_input)
{
	//string holder
	string output = "";
	//loop iterating through vector
	for (int i = 0; i < user_input.size(); i++) {
		//add current vector to string 
		output += user_input[i];
		//if current indes is not vector size -1 (needed to add a comma at the end)
		if (i != user_input.size() - 1)
			//add comma to seperate each entry
			output += ",";
	}
	//return string
	return output;
}

/*Artifact name: add_menu_item
* Receives a vector of user input & a Restaurant class object, the Resturant class' add_menu_item function
* will add the user's input to the file and return 1 if its all done successfully
* Khoi Trinh
* 4/23/2022
*/
int UpdateMenu::add_menu_item(vector<string>& user_input, Restaurant*& restaurant)
{
	//int result from Restaurannt class function add_menu_item, send user_input vector and and a string version of the user input
	int result = restaurant->add_menu_item(user_input, generate_database_entry(user_input));
	return result;
}

/*Artifact name: update_menu_item
* Receives a vector of user input & a Restaurant class object, the Resturant class' update_menu_item function
* will update the user's input in the file and return 1 if its all done successfully
* Khoi Trinh
* 4/23/2022
*/

int UpdateMenu::update_menu_item(vector<string>& user_input, Restaurant*& restaurant, int item_id)
{
	//int result from Restaurannt class function update_menu_item, send user_input vector and and a string version of the user input
	int result = restaurant->update_menu_item(user_input,item_id,generate_database_entry(user_input));
	return result;
}

/*Artifact name: delete_menu_item
* Receives a Restaurant class object and item_id, sends that to the Restaurant class delete_menu_item function to
* delete it from file. int result receiced will be 1 if all done succesfully
* Khoi Trinh
* 4/23/2022
*/
int UpdateMenu::delete_menu_item(Restaurant*& restaurant, int item_id)
{
	//int result from Restaurannt class function delete_menu_item, sends item_id
	int result = restaurant->delete_menu_item(item_id);
	return result;
}
