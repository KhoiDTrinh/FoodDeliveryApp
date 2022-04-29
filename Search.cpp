#include "Search.h"


using namespace std;

vector<pair<int, string>> Search::search(string user_input) {
	vector<pair<int, string>> search_results;

	string record, r_id, name;
	ifstream file;
	file.open(Restaurant::restaurant_file_name);
	getline(file, record);
	while (getline(file, record)) {
		if (check_match(record, user_input)) {
			stringstream line(record);
			getline(line, r_id, ',');
			getline(line, name, ',');
			search_results.push_back(pair<int, string>(stoi(r_id), name));
		}
	}
	file.close();

	return search_results;
}

bool Search::check_match(string record, string search_term) {
	tolowercase(record);
	tolowercase(search_term);
	return !(record.find(search_term) == string::npos);
}

void Search::tolowercase(string& input) {
	transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {return tolower(c); });
}