#include "UserInformation.h"

string UserInformation::file_name = "UserDatabase.txt";
string UserInformation::cc_info_file_name = "SavedCC.txt";

//UserInformation Constructor from a Record
//Creates a UserInformation object based on a record from database
//Khoi Trinh
//04/14/2022
UserInformation::UserInformation(string record) {
	stringstream stream(record);

	string id;
	getline(stream, id, ',');
	try {
		_user_id = stoi(id);
	}
	catch (const exception&) {
		cout << "Error reading database\nTerminating application\n\n";
		exit(1);
	}

	getline(stream, username, ',');
	getline(stream, password, ',');

	string a_type;
	getline(stream, a_type, ',');
	try {
		_account_type = stoi(a_type);
	}
	catch (const exception&) {
		cout << "Error reading database\nTerminating application\n\n";
		exit(1);
	}
	
	getline(stream, first_name, ',');
	getline(stream, last_name, ',');
	getline(stream, address, ',');
	getline(stream, phone, ',');
	getline(stream, email, ',');
}

//Search for Username
//Searches database of users to see if the username is already taken
//Khoi Trinh
//04/14/2022
bool UserInformation::search_username(string username) {
	string input;
	string temp_user;

	ifstream file;
	file.open(file_name);
	while (getline(file, input)) {
		stringstream record(input);
		getline(record, temp_user, ',');
		getline(record, temp_user, ',');
		if (username.compare(temp_user) == 0) {	//str.compare(str) == 0 when the two string are identical
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}

//Get User Record
//Searches the database for user based on username, stores the data in the UserInformation object passed by reference
//Khoi Trinh
//04/14/2022
int UserInformation::get_user_record(string username, UserInformation*& user_record) {
	string input;
	string temp_user;

	ifstream file;
	file.open(file_name);
	while (getline(file, input)) {
		stringstream record(input);
		getline(record, temp_user, ',');
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

//Add User Record
//Creates a database record based on given array of strings, writes the value to database
// and creates new UserInformation object stored in the user_record passed by reference
//Khoi Trinh
//04/14/2022
int UserInformation::add_user_record(vector<string>& user_info, UserInformation*& user_record) {
	user_info[1] = hash_password(user_info[1]);

	try {
		int id = get_next_user_id();
		ofstream file;
		string output = to_string(id) + ",";

		file.open(file_name, ios::app);
		for (int i = 0; i < user_info.size(); i++) {
			output += user_info[i];
			if (i != user_info.size() - 1)
				output += ",";
		}
		file << output << endl;
		file.close();

		//Creates UserInformation object and stores it in the user_record passed by reference
		user_record = new UserInformation(output);
		return 1;
	}
	catch (const exception&) {
		return 0;
	}
}

//Update User Record
//Updates user record in database based on new information passed in an array of strings
//Khoi Trinh
//04/14/2022
int UserInformation::update_user_record(vector<string>& user_info) {
	user_info[1] = hash_password(user_info[1]);

	//C++ cannot rewrite a specific line in a file
	//Copies all unchanged lines in file to a vector
	vector<string> database;
	try {
		ifstream file;
		string line;
		file.open(file_name);
		bool found = false;

		while (!found && getline(file, line)) {
			string username, user_id;
			stringstream sstream(line);
			getline(sstream, user_id, ',');
			getline(sstream, username, ',');

			//If username of that record matches the passed user_name
			//Create a new record and push that to databse instead of the original record
			if(username.compare(user_info[0]))
				database.push_back(line);
			else {
				string output = user_id + ",";
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

	first_name = user_info[3];
	last_name = user_info[4];

	//Rewrite entire database back to the file
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

//Hash password
//Simple hash function to hash passwords
//Khoi Trinh
//04/14/2022
string UserInformation::hash_password(string password) {
	hash<string> str_hash;
	return to_string(str_hash(password));
}

//Get Next User Id
//Checks database for highest user id and returns the next value
//Khoi Trinh
//04/14/2022
int UserInformation::get_next_user_id() {
	string record;
	string temp_id;
	int last_id = 0;
	ifstream file;
	file.open(file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, temp_id, ',');
		try {
			last_id = stoi(temp_id);
		}
		catch (const exception&) {
			cout << "Error reading file\nProgram terminating\n\n";
			exit(1);
		}
	}

	last_id++;

	return last_id;
}
