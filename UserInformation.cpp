#include "UserInformation.h"

string UserInformation::file_name = "UserDatabase.txt";

UserInformation::UserInformation(string record) {
	stringstream stream(record);
	getline(stream, username, ',');
	getline(stream, password, ',');
	getline(stream, first_name, ',');
	getline(stream, last_name, ',');
}

bool UserInformation::search_username(string username) {
	string input;
	string temp_user;

	ifstream file;
	file.open(file_name);
	while (getline(file, input)) {
		stringstream record(input);
		getline(record, temp_user, ',');
		if (username.compare(temp_user) == 0) {	//str.compare(str) == 0 when the two string are identical
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}

int UserInformation::get_user_record(string username, UserInformation*& user_record) {
	string input;
	string temp_user;

	ifstream file;
	file.open(file_name);
	while (getline(file, input)) {
		stringstream record(input);
		getline(record, temp_user, ',');
		if (username.compare(temp_user) == 0) {	//str.compare(str) == 0 when the two string are identical
			file.close();
			user_record = new UserInformation(input);
			return 1;
		}
	}

	file.close();
	return -2;
}

int UserInformation::add_user_record(vector<string> user_info, UserInformation*& user_record) {
	try {
		ofstream file;
		string output = "";

		file.open(file_name, ios::app);
		for (int i = 0; i < user_info.size(); i++) {
			output += user_info[i];
			if (i != user_info.size() - 1)
				output += ",";
		}
		file << output << endl;
		file.close();

		user_record = new UserInformation(output);
		return 1;
	}
	catch (const exception&) {
		return 0;
	}
}