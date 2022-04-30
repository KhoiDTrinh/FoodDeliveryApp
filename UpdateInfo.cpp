#include "UpdateInfo.h"

//-------------------- Public Functions --------------------

//Update User Info
//Takes user input from UserInterface and updates the user record in the database
//Return values:
//	1 = update successful;
//	0 = unidentified error;
//	-1 = user not found in database;
//Khoi Trinh
//04/14/22
int UpdateInfo::update_user_info(vector<string>& input, UserInformation*& user_record) {
	int result = user_record->update_user_record(input);
	return result;
}

//Validate Login
//Hashes provided password and checks to see if it matches database
//Khoi Trinh
//04/14/22
bool UpdateInfo::validate_login(string username, string password, UserInformation*& user_record) {
	return (!username.compare(user_record->get_username()) && !UserInformation::hash_password(password).compare(user_record->get_hashed_password()) );
}