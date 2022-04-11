#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "SignIn_Up.h"

using namespace std;

class UserInterface {
private:
	const int UI_MENU_WIDTH = 50;		//Width of the user interface in number of characters
	const int UI_MENU_HEIGHT = 15;		//Max number of items displayed in the user interface menu

	void display_start_up_screen();
	void display_home_screen();

	void sign_in();
	void sign_up();


	//-------------------- Helper Functions --------------------
	void display_menu(vector<string> menu_options, string menu_title);
	int get_user_menu_selection(int max_valid_input);
	void clear_screen();

public:
	UserInterface();
	//~UserInterface();

	void run();

};