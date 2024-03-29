
#include "Restaurant.h"

string Restaurant::restaurant_file_name = "Restaurants.txt";
string Restaurant::menu_file_name = "MenuItems.txt";

//-------------------- Public --------------------
//-------------------- Constructor --------------------
//Constructor from Record
//Constucts a Restaurant object based on a database record
//Khoi Trinh
//04/23/22
Restaurant::Restaurant(string record) {
	stringstream stream(record);

	string id;
	getline(stream, id, ',');
	try {
		restaurant_id = stoi(id);
	}
	catch (const exception&) {
		cout << "Error reading database\nTerminating application\n\n";
		exit(1);
	}

	getline(stream, name, ',');
	getline(stream, address, ',');
	getline(stream, category, ',');

	update_menu_item_list();
}

//-------------------- Getter/Setter --------------------
//Get List of Menu Item Names
//Returns a vector of pair of item id and item name
//Khoi Trinh
//04/23/22
vector<pair<int,string>> Restaurant::get_list_menu_item_names()
{
	vector<pair<int,string>> m_list;
	for (auto item : menu_items) {
		m_list.push_back(pair<int, string>(item.menu_item_id, item.item_name));
	}

	return m_list;
}

//-------------------- Static Functions --------------------
//Add New Restaurant
//Adds a new restaurant to the database and creates a new Restaurant object and stores in the record passed by reference
//Khoi Trinh
//04/23/22
int Restaurant::add_new_restaurant(vector<string>& user_input, Restaurant*& record) {
	try {
		ofstream file;
		string output = "";

		file.open(restaurant_file_name, ios::app);
		for (int i = 0; i < user_input.size(); i++) {
			output += user_input[i];
			if (i != user_input.size() - 1)
				output += ",";
		}
		file << output << endl;
		file.close();

		//Record is passed by reference, so pass the data by storing into the record
		record = new Restaurant(output);

		return 1;
	}
	catch (const exception&) {
		return 0;
	}
}

//Get Restaurant Record
//Searches for restaurant in database by restaurant_id, then stores in the record pointer passed by reference
//Khoi Trinh
//04/23/22
int Restaurant::get_restaurant_record(int id, Restaurant*& record) {
	string input;
	string temp_id;

	ifstream file;
	file.open(restaurant_file_name);
	while (getline(file, input)) {
		stringstream line(input);
		getline(line, temp_id, ',');
		if (temp_id.compare(to_string(id)) == 0) {
			file.close();

			//record is passed by reference, so create new object and pass back by storing into record
			record = new Restaurant(input);

			record->load_menu_items_to_array();

			return 1;
		}
	}

	file.close();
	return 0;
}

//-------------------- Public Functions --------------------
//Add Menu Item
//Adds item to menu database, and to active restaurant object's menu array
//Khoi Trinh
//04/23/22
int Restaurant::add_menu_item(vector<string>& user_input, string database_entry) {
	database_entry = to_string(get_next_menu_id()) + "," + to_string(restaurant_id) + "," + database_entry;

	ofstream file;
	file.open(menu_file_name, ios::app);
	file << database_entry << endl;
	file.close();

	add_menu_item_to_array(database_entry);

	return 1;
}

//Update Menu Item
//Updates a menu item in the database, and updates it in the active Restaurant object's array
//Khoi Trinh
//04/23/22
int Restaurant::update_menu_item(vector<string>& user_input, int item_id, string database_entry) {
	database_entry = to_string(get_next_menu_id()) + "," + to_string(restaurant_id) + "," + database_entry;

	string record, value;
	vector<string> database;

	ifstream infile;
	infile.open(menu_file_name);
	
	getline(infile, record);
	database.push_back(record);		//Header of file

	while (getline(infile, record)) {
		stringstream line(record);
		getline(line, value, ',');
		try {
			if (item_id == stoi(value)) {
				database.push_back(database_entry);
			}
			else {
				database.push_back(record);
			}
		}
		catch (const exception&) {
			cout << "Error reading database\nTerminating application\n\n";
			exit(1);
		}
	}
	infile.close();

	ofstream outfile;
	outfile.open(menu_file_name);
	for (string str : database)
		outfile << str << endl;
	outfile.close();

	//Search for menu item in array and update it
	for (auto i : menu_items) {
		if (i.menu_item_id == item_id) {
			i.item_name = user_input[0];
			i.item_description = user_input[1];
			i.item_price = stod(user_input[2]);
			break;
		}
	}

	return 1;
}

//Delete Menu Item
//Deletes a menu item from database and from active object's array
//Khoi Trinh
//04/23/22
int Restaurant::delete_menu_item(int item_id) {
	string record, value;
	vector<string> database;

	ifstream infile;
	infile.open(menu_file_name);

	getline(infile, record);
	database.push_back(record);		//Header of file

	while (getline(infile, record)) {
		stringstream line(record);
		getline(line, value, ',');
		try {
			if (item_id != stoi(value)) {
				database.push_back(record);
			}
		}
		catch (const exception&) {
			cout << "Error reading database\nTerminating application\n\n";
			exit(1);
		}
	}
	infile.close();

	ofstream outfile;
	outfile.open(menu_file_name);
	for (string str : database)
		outfile << str << endl;
	outfile.close();


	for (auto itr = menu_items.begin(); itr != menu_items.end(); ++itr) {
		if ((*itr).menu_item_id == item_id) {
			menu_items.erase(itr);
			break;
		}
	}

	return 1;
}

//Update Menu Item List
//Clears the menu array and reloads from database
//Khoi Trinh
//04/23/22
void Restaurant::update_menu_item_list() {
	menu_items.clear();
	string record;
	string i_id, r_id, name, desc, price;
	
	ifstream file;
	file.open(menu_file_name);
	getline(file, record); //Skipped header row in file
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, i_id, ',');
		getline(line, r_id, ',');
		getline(line, name, ',');
		getline(line, desc, ',');
		getline(line, price, ',');

		if (stoi(r_id) == restaurant_id) {
			menu_items.push_back(MenuItem(stoi(i_id),name,desc,stod(price)));
		}
	}
	file.close();
}

//Get Item by ID
//Returns MenuItem based on item_id
//Khoi Trinh
//04/23/22
Restaurant::MenuItem Restaurant::get_item_by_id(int item_id){
	for (MenuItem item : menu_items) {
		if (item_id == item.menu_item_id)
			return item;
	}
}



//-------------------- Private --------------------
//-------------------- Helper Functions --------------------
//Load Menu Items to Array
//Clears menu items array, reloads data from database
//Khoi Trinh
//04/23/22
void Restaurant::load_menu_items_to_array() {
	menu_items.clear();
	ifstream file;
	file.open(menu_file_name);
	
	string record;
	string r_id;

	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, r_id, ','); //skipping over item id
		getline(line, r_id, ',');
		try {
			if (restaurant_id == stoi(r_id)) {
				add_menu_item_to_array(record);
			}
		}
		catch (const exception&) {
			cout << "Error reading database asdfasdf\nTerminating application\n\n";
			exit(1);
		}
	}
}

//Add Menu Item to Array
//Adds menu item to array by database record
//Khoi Trinh
//04/23/22
void Restaurant::add_menu_item_to_array(string record) {
	string id_string, item_name, item_description, price_string;
	int item_id;
	double item_price;
	
	stringstream line(record);
	
	getline(line, id_string, ',');
	try {
		item_id = stoi(id_string);
	}
	catch (const exception&) {
		cout << "Error reading database\nProgram terminating\n\n";
		exit(1);
	}

	getline(line, item_name, ','); //skipping over restaurant_id
	getline(line, item_name, ',');
	getline(line, item_description, ',');

	getline(line, price_string, ',');
	try {
		item_price = stod(price_string);
	}
	catch (const exception&) {
		cout << "Error reading database\nProgram terminating\n\n";
		exit(1);
	}

	menu_items.push_back(MenuItem(item_id,item_name,item_description,item_price));

}

//Get Next Menu ID
//Reads database for last menu id and returns next value
//Khoi Trinh
//04/23/22
int Restaurant::get_next_menu_id() {
	string record;
	string temp_id;
	int last_id = 0;
	ifstream file;
	file.open(menu_file_name);
	getline(file, record);
	while (getline(file, record)) {
		stringstream line(record);
		getline(line, temp_id, ',');
		try {
			last_id = stoi(temp_id);
		}
		catch (const exception&) {
			cout << "Error reading file\nProgram terminating\n\n";
			exit(1);
		}
	}

	last_id++;

	return last_id;
}
