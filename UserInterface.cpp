#include "UserInterface.h"

using namespace std;

//-------------------- Public Functions --------------------

UserInterface::UserInterface() {

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
	case 1:
		sign_in();
		break;
	case 2:
		sign_up();
		break;
	case 3:
		cout << "Closing the application.\n\n";
		exit(1);
	default:
		cout << "Error. Invalid case.\n\n";
		exit(1);
	}
}

void UserInterface::display_home_screen() {
	vector<string> menu_options = { "Search for a Restaurant", "Create an Order", "Submit Order", "Check Order Status", "Update Personal Information", "Exit" };
	display_menu(menu_options, "Main Menu");
}

void UserInterface::sign_in() {
	clear_screen();
	string username;
	string password;

	cout << "Sign In\n--------------------\n";
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	//Check Validity of Log In Credentials Here




	display_home_screen();
}

void UserInterface::sign_up() {
	clear_screen();

}














//-------------------- Helper Functions --------------------

//Formats and displays a menu_title and a vector of menu_options
void UserInterface::display_menu(vector<string> menu_options, string menu_title) {
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
			cout << "Invalid input. Please enter a number between 1 and " << max_valid_input << endl;
			option = -1;
		}
	} while (option < 0 || option > max_valid_input);

	return option;
}

void UserInterface::clear_screen() {
	cout << flush;
	system("CLS");
}