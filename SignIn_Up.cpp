#include "SignIn_Up.h"

using namespace std; 

//-------------------- Public Functions --------------------


//Takes username and password as input, compares them to the database, returns result of comparison
//Return values:
//	1 = correct username and password;
//	0 = error;
//	-1 = password did not match;
//	-2 = username not found;
int SignIn_Up::sign_in(string username, string password) {

	string input;
	string temp_user, temp_pass;

	ifstream file;
	try {
		file.open("loginInfo.txt");
		while (getline(file, input)) {
			stringstream record(input);
			getline(record, temp_user, ',');
			if (username.compare(temp_user) == 0) {	//str.compare(str) == 0 when the two string are identical
				getline(record, temp_pass, ',');
				file.close();
				if (hash_password(password).compare(temp_pass) == 0)
					return 1;
				else
					return -1;
			}
		}
	}
	catch (const exception&) {
		return 0;
	}
	
	file.close();
	return -2;
}

//Takes user input from UserInterface, checks if input is valid, checks if username is taken, returns result of account creation
//Return values:
//	1 = account creation successful;
//	0 = error;
//	-1 = input invalid;
//	-2 = username already taken;
int SignIn_Up::sign_up(string name, string username, string password) {
	ifstream iFile;
	ofstream oFile;
	string input;
	string temp_user;

	if (!check_validity(name)) return -1;
	if (!check_validity(username)) return -1;
	if (!check_validity(password)) return -1;


	try
	{
		iFile.open("loginInfo.txt");
		while (getline(iFile, input)) {
			stringstream record(input);
			getline(record, temp_user, ',');
			if (username.compare(temp_user) == 0) {
				iFile.close();
				return -2;
			}
		}
		iFile.close();

		oFile.open("loginInfo.txt", ios::app);
		oFile << username << "," << hash_password(password) << "," << name << endl;
		oFile.close();
		return 1;
	}
	catch (const exception&)
	{
		return 0;
	}
	return 0;
}


//-------------------- Private Functions --------------------

string SignIn_Up::hash_password(string password) {
	hash<string> str_hash;
	return to_string(str_hash(password));
}

bool SignIn_Up::check_validity(string input) {
	if (input.length() == 0)
		return false;
	return true;
}