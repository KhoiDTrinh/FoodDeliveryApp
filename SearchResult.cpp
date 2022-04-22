#include "SearchResult.h"

using namespace std; 


int Search_Result::display_Search_Results(vector<int> restaurantID)
{
	try
	{
		if (display_Restaurant_Summary(restaurantID) == false) {
			throw 0;
		}
		for (int size = 0; size < restaurantID.size(); size++) {
			display_Restaurant_Summary(restaurantID);
		}
		return 1;
	}
	catch (int value)
	{
		return value; 
		cout << "Error" << endl;
	}
	
	

}

int Search_Result::display_Restaurant_Summary(vector<int> restaurantID)
{
	try
	{
		if (restaurantID.size() == 0) {
			throw 0;
		}
		for (int size = 0; size < restaurantID.size(); size++) {
			cout << restaurantID[size] << endl;
		}

	}
	catch (int value)
	{
		return value;
		cout << "No Search Result\n";
	}
	return 1;
}
