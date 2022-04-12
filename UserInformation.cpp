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

int UserInformation::add_user_record(vector<string>& user_info, UserInformation*& user_record) {
	user_info[1] = hash_password(user_info[1]);

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

int UserInformation::update_user_record(vector<string>& user_info) {
	user_info[1] = hash_password(user_info[1]);

	vector<string> database;
	try {
		ifstream file;
		string line;
		file.open(file_name);
		bool found = false;

		while (!found && getline(file, line)) {
			string value;
			stringstream sstream(line);
			getline(sstream, value, ',');
			if(value.compare(user_info[0]))
				database.push_back(line);
			else {
				string output = "";
				for (int i = 0; i < user_info.size(); i++) {
					output += user_info[i];
					if (i != user_info.size() - 1)
						output += ",";
				}
				database.push_back(output);
				found = true;
			}
		}

		while (getline(file, line)) {
			database.push_back(line);
		}
		file.close();

		if (!found)
			return -1;
	}
	catch(const exception&) {
		return 0;
	}

	first_name = user_info[2];
	last_name = user_info[3];

	try {
		ofstream file;
		file.open(file_name);
		for (string record : database) {
			file << record << endl;
		}
		file.close();
		return 1;
	}
	catch (const exception&) {
		return 0;
	}
}

string UserInformation::hash_password(string password) {
	hash<string> str_hash;
	return to_string(str_hash(password));
}