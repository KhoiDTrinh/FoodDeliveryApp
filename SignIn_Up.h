#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class SignIn_Up {
private:
	static string hash_password(string password);
	static bool check_validity(string input);
public:
	static int sign_up(string username, string password, string name);
	static int sign_in(string username, string password);
};