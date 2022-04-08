#include "SignIn_Up.h"

using namespace std; 


void SignIn_Up::sign_in() {

}

void SignIn_Up::sign_up(string username, string password, string name) {
	ofstream file;
	file.open("loginInfo.txt");
	file << name << "," << username << "," << password <<"\n";
	cout << name << "," << username << "," << password <<"\n";
	file.close();

}