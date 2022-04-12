#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "UserInformation.h"

using namespace std;

class SignIn_Up {
private:
	static string hash_password(string password);
	static bool check_validity(const string& input);
public:
	static int sign_up(vector<string> user_info, UserInformation*& user_record);
	static int sign_in(string username, string password, UserInformation*& user_record);
};