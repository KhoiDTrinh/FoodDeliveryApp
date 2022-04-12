#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class UserInformation {
private:
	static string file_name;
	string first_name, last_name, username, password;
	int _account_type;
public:
	enum account_type { customer, driver, restaurant };

	UserInformation(string record);

	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
	string get_username() { return username; }
	string get_hashed_password() { return password; }
	int get_account_type() { return _account_type; }

	void set_account_Type(int type) { _account_type = type; }

	static bool search_username(string username);
	static int get_user_record(string username, UserInformation*& user_record);
	static int add_user_record(vector<string>& user_info, UserInformation*& user_record);
	static string hash_password(string password);


	int update_user_record(vector<string>& user_info);
};