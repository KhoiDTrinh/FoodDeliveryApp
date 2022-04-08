#pragma once
#include <iostream>
#include<fstream>
#include <vector>
#include <string>

using namespace std;

class SignIn_Up {
private:

public:
	static int sign_up(string username, string password, string name);
	static int sign_in();

};