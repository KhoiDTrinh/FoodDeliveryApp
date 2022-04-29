#include "UserInterface.h"

using namespace std;

//-------------------- Public Functions --------------------

UserInterface::UserInterface() {
	user_record = nullptr;
}

UserInterface::~UserInterface() {
	delete user_record;
}

void UserInterface::run() {
	display_start_up_screen();
}


//-------------------- Private Functions --------------------

void UserInterface::display_start_up_screen() {
	vector<string> menu_options = { "Sign In","Create an Account","Exit" };
	display_menu(menu_options, "Menu");
	int user_input = get_user_menu_selection(menu_options.size());

	switch (user_input) {
	case 1:		//Sign in
		sign_in();
		break;
	case 2:		//Create an Account
		sign_up();
		break;
	case 3:		//Exit
		cout << "Closing the application.\n\n";
		exit(0);
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::display_home_screen() {
	switch (user_record->get_account_type()) {
	case UserInformation::account_type::customer:
		display_customer_home_screen();
		break;
	case UserInformation::account_type::driver:
		display_driver_home_screen();
		break;
	case UserInformation::account_type::restaurant:
		display_restaurant_home_screen();
		break;
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::display_customer_home_screen() {
	vector<string> menu_options = { "Create a New Order", "Check Order Status", "Update Personal Information", "Exit" };
	while (true)
	{
		display_menu(menu_options, "Main Menu");

		cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

		int user_input = get_user_menu_selection(menu_options.size());

		switch (user_input) {
		case 1:		//Create an Order
			create_new_order();
			break;
		case 2:		//Check Order Status
			break;
		case 3:		//Update Personal Information
			update_personal_info();
			break;
		case 4:		//Exit
			cout << "Closing the application.\n\n";
			exit(0);
		default:
			cout << "Error encountered\nProgram terminating\n\n";
			exit(1);
		}
	}
}

void UserInterface::display_driver_home_screen() {
	vector<string> menu_options = { "Accept/Reject Delivery", "Check Order Status", "Confirm Delivery", "Update Personal Information", "Exit" };
	display_menu(menu_options, "Main Menu");

	cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

	int user_input = get_user_menu_selection(menu_options.size());

	switch (user_input) {
	case 1:		//Accept/Reject Delivery
		break;
	case 2:		//Check Order Status
		break;
	case 3:		//Confirm Delivery
		break;
	case 4:		//Update Personal Information
		update_personal_info();
		break;
	case 5:		//Exit
		cout << "Closing the application.\n\n";
		exit(0);
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::display_restaurant_home_screen() {
	vector<string> menu_options = { "Accept/Decline Order", "Update Order Status", "Show Pending Orders", "Update Menu", "Update Personal Information", "Exit"};
	display_menu(menu_options, "Main Menu");

	cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

	int user_input = get_user_menu_selection(menu_options.size());

	switch (user_input) {
	case 1:		//Accept/Decline Order
		break;
	case 2:		//Update Order Status
		break;
	case 3:		//Show Pending Orders
		break;
	case 4:		//Update Menu
		display_update_menu_screen();
		break;
	case 5:		//Update Personal Information
		update_personal_info();
		break;
	case 6:		//Exit
		cout << "Closing the application.\n\n";
		exit(0);
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::display_update_menu_screen() {
	vector<string> menu_options = { "Add Item", "Update Item", "Delete Item", "Exit"};
	display_menu(menu_options, "Update Menu");

	int user_input = get_user_menu_selection(menu_options.size());

	switch (user_input) {
	case 1:
		add_menu_item();
		display_update_menu_screen();
		break;
	case 2:
		update_menu_item();
		display_update_menu_screen();
		break;
	case 3:
		delete_menu_item();
		display_update_menu_screen();
		break;
	case 4:
		display_restaurant_home_screen();
		break;
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}



//-------------------- All Users Functions --------------------

void UserInterface::sign_in() {
	clear_screen();
	string username;
	string password;
	string temp;

	cout << "Sign In\n--------------------\n";
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	int result = SignIn_Up::sign_in(username, password, user_record);

	switch (result) {
	case 1:		//successful log in
		if (user_record->get_account_type() == 2) {
			get_restaurant_record();
		}
		display_home_screen();
		break;
	case -1:	//invalid password
		cout << "Password was incorrect\nPress ENTER to return to Log In menu\n";
		getline(cin, temp);
		display_start_up_screen();
		break;
	case -2:	//invalid username
		cout << "Username was not found\nPress ENTER to return to Log In menu\n";
		getline(cin, temp);
		display_start_up_screen();
		break;
	case 0:
	default:	//error
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::sign_up() {
	clear_screen();

	vector<string> menu_options = { "Customer", "Driver", "Restaurant", "Exit"};
	display_menu(menu_options, "Which account type do you wish to create?");
	cout << "Which account type do you wish to create?\n";
	int user_menu_selection = get_user_menu_selection(menu_options.size());

	if (user_menu_selection == 4) {
		cout << "Closing the application.\n\n";
		exit(0);
	}

	clear_screen();

	string input;
	vector<string> user_input;


	cout << "Sign Up\n--------------------\n";
	cout << "Username: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Password: ";
	getline(cin, input);
	user_input.push_back(input);

	switch (user_menu_selection) {
	case 1:
		user_input.push_back(to_string(UserInformation::account_type::customer));
		break;
	case 2:
		user_input.push_back(to_string(UserInformation::account_type::driver));
		break;
	case 3:
		user_input.push_back(to_string(UserInformation::account_type::restaurant));
		break;
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}

	get_user_info(user_input);

	int result = SignIn_Up::sign_up(user_input, user_record);
	
	if (user_menu_selection == 3) {
		user_input.clear();
		get_restaurant_info(user_input);
		Restaurant::add_new_restaurant(user_input, restaurant_record);
	}

	switch (result) {
	case 1:		//successful account creation
		display_home_screen();
		break;
	case -1:	//user input invalid
		cout << "User input was invalid\nPress ENTER to return to Log In menu\n";
		getline(cin, input);
		display_start_up_screen();
		break;
	case -2:	//username already taken
		cout << "Username is already taken\nPress ENTER to return to Log In menu\n";
		getline(cin, input);
		display_start_up_screen();
		break;
	case 0:
	default:	//error
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::update_personal_info() {
	string input;
	clear_screen();
	vector<string> user_input;

	cout << "Update Personal Info\n--------------------\n";
	
	user_input.push_back(user_record->get_username());
	
	cout << "Verify Your Password: ";
	getline(cin, input);
	user_input.push_back(input);

	if (!UpdateInfo::validate_login(user_input[0], user_input[1], user_record)) {
		cout << "Password was invalid\nPress ENTER to return to Main Menu\n";
		getline(cin, input);
		display_home_screen();
		return;
	}

	user_input.push_back(to_string(user_record->get_account_type()));
	get_user_info(user_input);

	int result = UpdateInfo::update_user_info(user_input, user_record);

	switch (result) {
	case 1:		//successful update
		cout << "User Information successfully updated\nPress ENTER to return to Main Menu\n";
		getline(cin, input);
		display_home_screen();
		break;
	case -1:	//user not found in database
		cout << "User was not found in database\n";
	case 0:
	default:	//error
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}




//-------------------- Customer Functions --------------------
void UserInterface::create_new_order() {
	int restaurant_id = search_for_restaurant();
	if (restaurant_id == -1)
		return;

	CreateOrder create_order;
	create_order.start_new_order(user_record->get_user_id(), restaurant_id, user_record->get_address());

	int result = add_remove_items_to_order(create_order);
	if (result == -1)
		return;
}

int UserInterface::search_for_restaurant() {
	clear_screen();
	cout << "Searching for Restaurant\n\n";
	cout << "Please enter a search term: ";
	string search_term;
	getline(cin, search_term);

	Search search;
	vector<pair<int, string>> search_results = search.search(search_term);

	vector<string> menu_options;
	for (auto entry : search_results) {
		menu_options.push_back(entry.second);
	}
	menu_options.push_back("Exit");

	display_menu(menu_options, "Select a Restaurant to Begin Order");
	int restaurant_selection = get_user_menu_selection(menu_options.size());

	if (restaurant_selection == menu_options.size())
		return -1;				//-1 indicates user exit

	restaurant_selection = search_results[restaurant_selection - 1].first;

	return restaurant_selection;
}

int UserInterface::add_remove_items_to_order(CreateOrder& create_order) {
	vector<string> menu_options = {"Add Item to Order", "Remove Item from Order", "Checkout", "Exit"};
	display_menu(menu_options, "Cart");

	int menu_selection = get_user_menu_selection(menu_options.size());

	switch (menu_selection) {
	case 1:
		add_item_to_order(create_order);
		break;
	case 2:
		remove_item_from_order(create_order);
		break;

	case 3:

		break;
	case 4:
		return -1;
		break;
	default:
		cout << "Error encountered in add_remove_items_to_order\n\nTerminating application\n\n";
		exit(1);
	}
}

int UserInterface::add_item_to_order(CreateOrder& create_order) {
	create_order.get_menu_options();
}

int UserInterface::remove_item_from_order(CreateOrder& create_order) {

}

//-------------------- Driver Functions --------------------






//-------------------- Restaurant Functions --------------------
void UserInterface::add_menu_item() {
	clear_screen();
	vector<string> user_input;

	cout << "Add Menu Item\n--------------------\n";
	get_menu_item_info(user_input);

	UpdateMenu::add_menu_item(user_input, restaurant_record);
}

void UserInterface::update_menu_item() {
	vector<pair<int,string>> menu_item_list = restaurant_record->get_list_menu_item_names();
	vector<string> menu_options;
	for (auto item : menu_item_list) {
		menu_options.push_back(item.second);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Update Menu Item");

	int user_selection = get_user_menu_selection(menu_options.size());

	if (user_selection == menu_options.size()) {
		display_update_menu_screen();
		return;
	}

	vector<string> user_input;

	cout << "Update Menu Item\n--------------------\n";
	get_menu_item_info(user_input);

	UpdateMenu::update_menu_item(user_input, restaurant_record, menu_item_list[user_selection - 1].first);
}

void UserInterface::delete_menu_item() {
	vector<pair<int, string>> menu_item_list = restaurant_record->get_list_menu_item_names();
	vector<string> menu_options;
	for (auto item : menu_item_list) {
		menu_options.push_back(item.second);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Delete Menu Item");

	int user_selection = get_user_menu_selection(menu_options.size());

	if (user_selection == menu_options.size()) {
		display_update_menu_screen();
		return;
	}

	UpdateMenu::delete_menu_item(restaurant_record, menu_item_list[user_selection - 1].first);
}









//-------------------- Helper Functions --------------------

//Formats and displays a menu_title and a vector of menu_options
void UserInterface::display_menu(vector<string>& menu_options, string menu_title) {
	clear_screen();
	
	//Display top border
	cout << setfill('-') << setw(UI_MENU_WIDTH) << "-" << endl << setfill(' ');

	//Display title, centered
	int spacing = (UI_MENU_WIDTH - menu_title.length()) / 2;
	cout << setw(spacing) << left << "|";
	cout << menu_title;
	if ((menu_title.length() + UI_MENU_WIDTH) % 2)				//If number of spaces needed is odd, add an extra space to the right side
		spacing++;
	cout << setw(spacing) << right << "|" << endl << left;

	//Display middle border
	cout << setfill('-') << setw(UI_MENU_WIDTH) << "-" << endl << setfill(' ');

	//Display menu options
	for (int i = 0; i < menu_options.size(); i++) {
		string line = "| ";
		line += to_string(i + 1);
		line += ". ";
		if (i + 1 < 10) line += " ";							//If displayed menu option number is less than 10, add extra space to line up text
		line += menu_options[i];
		cout << setw(UI_MENU_WIDTH - 1) << line << "|" << endl;
	}

	//Display bottom border
	cout << setfill('-') << setw(UI_MENU_WIDTH) << "-" << endl << endl << setfill(' ');
}

//Get user menu selection and validate the input
int UserInterface::get_user_menu_selection(int max_valid_input) {
	string user_input;
	int option = -1;

	cout << "Please select a menu option." << endl;

	do {
		getline(cin, user_input);

		try {
			option = stoi(user_input);
		}
		catch (const invalid_argument) {
			cout << "Invalid input. Please enter a number between 1 and " << max_valid_input << endl;
		}

		if (option > max_valid_input) {
			cout << "Number out of range. Please enter a number between 1 and " << max_valid_input << endl;
			option = -1;
		}
	} while (option < 0 || option > max_valid_input);

	return option;
}

void UserInterface::clear_screen() {
	cout << flush;
	system("CLS");
}

void UserInterface::get_user_info(vector<string>& user_input) {
	string input;
	cout << "First Name: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Last Name: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Address: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Phone Number: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Email: ";
	getline(cin, input);
	user_input.push_back(input);
}

void UserInterface::get_restaurant_info(vector<string>& user_input) {
	string input;

	user_input.push_back(to_string(user_record->get_user_id()));

	cout << "Restaurant Name: ";
	getline(cin, input);
	user_input.push_back(input);

	user_input.push_back(user_record->get_address());

	cout << "Restaurant Type: ";
	getline(cin, input);
	user_input.push_back(input);
}

void UserInterface::get_menu_item_info(vector<string>& user_input) {
	string input;
	double price = -1.0;

	cout << "Item Name: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Item Description: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Item Price: ";

	do {
		getline(cin, input);

		try {
			price = stoi(input);
		}
		catch (const invalid_argument) {
			cout << "Invalid input. Please enter a number " << endl;
		}

		if (price <= 0) {
			cout << "Number out of range. Please enter a number greater than 0" << endl;
			price = -1;
		}
	} while (price < 0);

	user_input.push_back(input);
}

void UserInterface::get_restaurant_record() {
	int result = Restaurant::get_restaurant_record(user_record->get_user_id(), restaurant_record);
	if (result == 0) {
		cout << "Error encountered\nRestaurant not found in database.\nProgram terminating\n\n";
		exit(1);
	}
}

void UserInterface::pause() {
	string temp;
	cout << "Press Enter to Continue\n\n";
	getline(cin, temp);
}