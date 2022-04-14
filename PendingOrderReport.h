#pragma once
#include <iostream>
#include<fstream>
#include <vector>
#include <string>

using namespace std;

class PendingOrderReport {
private:

public:
	static void Orders(int OrderID, vector<string>& ItemList, 
		vector<int>& quantity, vector<string>& comments, string orderSattus);
	static void displayQuantity(vector<int>& quantity, int index);
	static void displayComments(vector<string>& comments, int index);

};