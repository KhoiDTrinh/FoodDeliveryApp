#include "SignIn_Up.h"

using namespace std; 


int SignIn_Up::sign_in() {
	return 0;
}

int SignIn_Up::sign_up(string username, string password, string name) {
	ofstream file;

	try
	{
		file.open("loginInfo.txt", ios::app);
		file << name << "," << username << "," << password << "\n";
	}
	catch (const exception&)
	{
		return 0;
	}

	cout << " Hello";

	file.close();
	return 1;
}