#include "SearchResult.h"

using namespace std; 


int Search_Result::display_Search_Results(vector<int> restaurantID)
{
	try
	{
		if (display_Restaurant_Summary(restaurantID) == false) {
			throw 0;
		}
		for (int x = 0; x < restaurantID.size(); x++) {
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
	/* cout resturatn data. */
	return 1;
}
