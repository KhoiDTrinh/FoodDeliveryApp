#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class UserInformation {
private:
	string first_name, last_name, username, password;
	string address, phone, email;
	int _user_id, _account_type;

	static int get_next_user_id();

public:
	enum account_type { customer, driver, restaurant };

	UserInformation(string record);

	static string file_name;
	static string cc_info_file_name;

	int get_user_id() { return _user_id; }
	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
	string get_username() { return username; }
	string get_hashed_password() { return password; }
	string get_address() { return address; }
	string get_phone() { return phone; }
	string get_email() { return email; }
	int get_account_type() { return _account_type; }

	void set_account_Type(int type) { _account_type = type; }

	static bool search_username(string username);
	static int get_user_record(string username, UserInformation*& user_record);
	static int add_user_record(vector<string>& user_info, UserInformation*& user_record);
	static string hash_password(string password);


	int update_user_record(vector<string>& user_info);
};