#include "Search.h"
/*
Date: April 24, 2022
Name: William Cao(Phuoc)
Artifact Name: Search Class

Description:
	The class take user input as a string to find restaurant that macthes with user input and return search result.
	Uses restaurant database to find the restaurant ID.
*/


using namespace std;


/*
Date: April 24, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact name: Search Function

Description:
	Search user input by opening restaurant file name then read in the line and push it to vector. Return the search result.
*/
vector<pair<int, string>> Search::search(string user_input) {
	vector<pair<int, string>> search_results;

	string record, r_id, name;
	ifstream file;
	file.open(Restaurant::restaurant_file_name);
	getline(file, record);
	while (getline(file, record)) {
		if (check_match(record, user_input)) {		//Check if input match with data base
			stringstream line(record);
			getline(line, r_id, ',');				//The 2nd value in the database
			getline(line, name, ',');				//The 3rd value in the database
			search_results.push_back(pair<int, string>(stoi(r_id), name));
		}
	}
	file.close();

	return search_results;
}


/*
Date: April 24, 2022
Name: William Cao(Phuoc), Khoi Trinh 
Artifact name: Check Match Function

Description:
	Check for search term with the database. using tolowercase function.
*/
bool Search::check_match(string record, string search_term) {
	tolowercase(record);			//Lowercase record
	tolowercase(search_term);		//Lowercase seqarch term from user input
	return !(record.find(search_term) == string::npos);
}


/*
Date: April 24, 2022
Name: William Cao(Phuoc), Khoi Trinh
Artifact name: tolowercase

Description:
	Turn input into Lowercase
*/
void Search::tolowercase(string& input) {
	transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {return tolower(c); });
}