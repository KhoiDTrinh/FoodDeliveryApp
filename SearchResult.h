#pragma once
#include <iostream>
#include "Search.h"
#include "UserInformation.h"
#include <vector>
#include <string>

using namespace std;

class Search_Result {
private:

public:
	static int display_Search_Results(vector<int> restaurantID);
	static int display_Restaurant_Summary(int iD);

};