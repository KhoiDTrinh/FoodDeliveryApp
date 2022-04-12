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
		cout << "Error. Invalid case.\n\n";
		exit(1);
	}
}

void UserInterface::display_home_screen() {
	vector<string> menu_options = { "Search for a Restaurant", "Create an Order", "Submit Order", "Check Order Status", "Update Personal Information", "Exit" };
	display_menu(menu_options, "Main Menu");

	cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

	int user_input = get_user_menu_selection(menu_options.size());

	switch (user_input) {
	case 1:		//Search for a Restaurant
		break;
	case 2:		//Create an Order
		break;
	case 3:		//Submit Order
		break;
	case 4:		//Check Order Status
		break;
	case 5:		//Update Personal Information
		update_personal_info();
		break;
	case 6:		//Exit
		cout << "Closing the application.\n\n";
		exit(0);
	default:
		cout << "Error. Invalid case.\n\n";
		exit(1);
	}
}







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
	string input;
	vector<string> user_input;


	cout << "Sign Up\n--------------------\n";
	cout << "Username: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Password: ";
	getline(cin, input);
	user_input.push_back(input);

	get_user_info(user_input);

	int result = SignIn_Up::sign_up(user_input, user_record);

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

	get_user_info(user_input);

	int result = UpdateInfo::update_customer_info(user_input, user_record);

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
}