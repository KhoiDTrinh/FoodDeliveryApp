#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "Restaurant.h"

using namespace std; 

class Search {
private:
	bool check_match(string record, string search_term);
	void tolowercase(string& input);
public:
	vector<pair<int,string>> search(string user_input);
};