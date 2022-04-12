#include "SignIn_Up.h"

using namespace std; 

//-------------------- Public Functions --------------------

//Takes username and password as input, compares them to the database, returns result of comparison
//Return values:
//	1 = correct username and password;
//	0 = error;
//	-1 = password did not match;
//	-2 = username not found;
int SignIn_Up::sign_in(string username, string password, UserInformation*& user_record) {
	int result = UserInformation::get_user_record(username, user_record);
	if (result == -2)
		return -2;
	if (UserInformation::hash_password(password).compare(user_record->get_hashed_password()) != 0)
		return -1;

	return 1;
}

//Takes user input from UserInterface, checks if input is valid, checks if username is taken, returns result of account creation
//Return values:
//	1 = account creation successful;
//	0 = error;
//	-1 = input invalid;
//	-2 = username already taken;
int SignIn_Up::sign_up(vector<string> user_info, UserInformation*& user_record) {
	for (int i = 0; i < user_info.size(); i++) {
		if (!check_length(user_info[i]))
			return -1;
		if (i < 2 && check_spaces(user_info[i]))
			return -1;
	}

	if (UserInformation::search_username(user_info[0]) == true)
		return -2;

	int result = UserInformation::add_user_record(user_info, user_record);
	if (result == 0)
		return 0;
	return 1;
}


//-------------------- Private Functions --------------------

//Validates the length of the input string. Returns true if length is greater than 0 and less than 64.
bool SignIn_Up::check_length(const string& input) {
	return (input.length() > 0 && input.length() < 64);
}


//Checks for spaces in input string. Returns true if at least 1 space is found, and false otherwise
bool SignIn_Up::check_spaces(const string& input) {
	return (input.find(' ') != string::npos);
}