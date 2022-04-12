#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "UserInformation.h"

class UpdateInfo {
private:
public:
	static int update_customer_info(vector<string>& input, UserInformation*& user_record);
	static bool validate_login(string username, string password, UserInformation*& user_record);
};