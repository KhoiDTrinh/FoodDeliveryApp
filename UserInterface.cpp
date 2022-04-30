#include "UserInterface.h"

using namespace std;

//-------------------- Public Functions --------------------

//Default Constructor
UserInterface::UserInterface() {
}

//Destructor
UserInterface::~UserInterface() {
	delete user_record;
	delete restaurant_record;
}

//Main driver
//Driver to start the user interface, public function accessible to other classes
//Khoi Trinh
//04/03/2022
void UserInterface::run() {
	display_start_up_screen();
}


//-------------------- Main Menus --------------------

//Display Start Up Screen
//Displays the initial screen when the app is loaded
//Khoi Trinh
//04/03/22
void UserInterface::display_start_up_screen() {
	//Create array of options, displays them, and get's user menu selection.
	vector<string> menu_options = { "Sign In","Create an Account","Exit" };
	display_menu(menu_options, "Menu");
	int menu_selection = get_user_menu_selection(menu_options.size());

	//Switch statement to run based on user selection
	switch (menu_selection) {
	case 1:		//Sign in
		sign_in();
		break;
	case 2:		//Create an Account
		sign_up();
		break;
	case 3:		//Exit
		cout << "Closing the application.\n\n";
		return;
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

//Display Home Screen
//Displays the home screen, the first screen shown after login or successful signup
//Khoi Trinh
//04/03/22
void UserInterface::display_home_screen() {
	//Displays a different screen based on account type (customer, driver, or restaurant)
	switch (user_record->get_account_type()) {
	case UserInformation::account_type::customer:
		display_customer_home_screen();
		break;
	case UserInformation::account_type::driver:
		display_driver_home_screen();
		break;
	case UserInformation::account_type::restaurant:
		display_restaurant_home_screen();
		break;
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

//Display Customer Home Screen
//Shows the main menu options for the customer
//Khoi Trinh
//04/03/22
void UserInterface::display_customer_home_screen() {
	//Sets the main menu options
	vector<string> menu_options = { "Create a New Order", "Check Order Status", "Update Personal Information", "Exit" };
	
	//Main loop for program, runs until Exit is chosen
	while (true)
	{
		display_menu(menu_options, "Main Menu");

		cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

		int user_input = get_user_menu_selection(menu_options.size());

		//Switch statement to redirect based on user input
		switch (user_input) {
		case 1:		//Create an Order
			create_new_order();
			break;
		case 2:		//Check Order Status
			check_order_status_customer();
			break;
		case 3:		//Update Personal Information
			update_personal_info();
			break;
		case 4:		//Exit
			cout << "Closing the application.\n\n";
			return;
		default:
			cout << "Error encountered\nProgram terminating\n\n";
			exit(1);
		}
	}
}

//Display Driver Home Screen
//Shows the main menu options for the driver
//Khoi Trinh
//04/03/22
void UserInterface::display_driver_home_screen() {
	//Sets the main menu options
	vector<string> menu_options = { "Accept/Reject Delivery", "Check Order Status", "Confirm Delivery", "Update Personal Information", "Exit" };
	
	//Main loop for program, runs until Exit is chosen
	while (true) {
		display_menu(menu_options, "Main Menu");

		cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

		int user_input = get_user_menu_selection(menu_options.size());

		//Switch statement to redirect based on user input
		switch (user_input) {
		case 1:		//Accept/Reject Delivery
			accept_reject_delivery();
			break;
		case 2:		//Check Order Status
			check_order_status_driver();
			break;
		case 3:		//Confirm Delivery
			confirm_delivery();
			break;
		case 4:		//Update Personal Information
			update_personal_info();
			break;
		case 5:		//Exit
			cout << "Closing the application.\n\n";
			return;
		default:
			cout << "Error encountered\nProgram terminating\n\n";
			exit(1);
		}
	}
}

//Display Restaurant Home Screen
//Shows the main menu options for the restaurant
//Khoi Trinh
//04/03/22
void UserInterface::display_restaurant_home_screen() {
	//Sets the main menu options
	vector<string> menu_options = { "Accept/Decline Order", "Update Order Status", "Show Pending Orders", "Update Menu", "Update Personal Information", "Exit"};

	//Main loop for program, runs until Exit is chosen
	while (true) {
		display_menu(menu_options, "Main Menu");

		cout << "Welcome " << user_record->get_first_name() << " " << user_record->get_last_name() << endl << endl;

		int user_input = get_user_menu_selection(menu_options.size());

		switch (user_input) {
		case 1:		//Accept/Decline Order
			accept_decline_order();
			break;
		case 2:		//Update Order Status
			update_order_status();
			break;
		case 3:		//Show Pending Orders
			show_pending_orders();
			break;
		case 4:		//Update Menu
			display_update_menu_screen();
			break;
		case 5:		//Update Personal Information
			update_personal_info();
			break;
		case 6:		//Exit
			cout << "Closing the application.\n\n";
			return;
		default:
			cout << "Error encountered\nProgram terminating\n\n";
			exit(1);
		}
	}
}




//-------------------- All Users Functions --------------------

//Sign In
//Gets user credentials for sign in, validates username and password, 
//Khoi Trinh
//04/11/22
void UserInterface::sign_in() {
	clear_screen();
	string username;
	string password;
	string temp;

	cout << "Sign In\n--------------------\n";
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	int result = SignIn_Up::sign_in(username, password, user_record);

	switch (result) {
	case 1:		//successful log in
		if (user_record->get_account_type() == 2) {
			get_restaurant_record();
		}
		display_home_screen();
		break;
	case -1:	//invalid password
		cout << "Password was incorrect\nPress ENTER to return to Log In menu\n";
		getline(cin, temp);
		display_start_up_screen();
		break;
	case -2:	//invalid username
		cout << "Username was not found\nPress ENTER to return to Log In menu\n";
		getline(cin, temp);
		display_start_up_screen();
		break;
	case 0:
	default:	//error
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}

//Sign Up
//Creation of a new user account
//Khoi Trinh
//04/11/22
void UserInterface::sign_up() {
	clear_screen();

	//Select account type
	vector<string> menu_options = { "Customer", "Driver", "Restaurant", "Exit"};
	display_menu(menu_options, "Which account type do you wish to create?");
	cout << "Which account type do you wish to create?\n";
	int user_menu_selection = get_user_menu_selection(menu_options.size());


	//Exit on selection of option 4
	if (user_menu_selection == 4) {
		cout << "Closing the application.\n\n";
		exit(0);
	}

	clear_screen();



	string input;
	vector<string> user_input;

	//Get username and password
	cout << "Sign Up\n--------------------\n";
	cout << "Username: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Password: ";
	getline(cin, input);
	user_input.push_back(input);

	//Get user input for account type selection
	switch (user_menu_selection) {
	case 1:
		user_input.push_back(to_string(UserInformation::account_type::customer));
		break;
	case 2:
		user_input.push_back(to_string(UserInformation::account_type::driver));
		break;
	case 3:
		user_input.push_back(to_string(UserInformation::account_type::restaurant));
		break;
	default:
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}

	//Gets remaining user info
	get_user_info(user_input);

	//Calls external class to process the sign up, save the result message
	int result = SignIn_Up::sign_up(user_input, user_record);
	
	//If user type is restaurant, get restaurant specific info
	if (user_menu_selection == 3) {
		user_input.clear();
		get_restaurant_info(user_input);
		Restaurant::add_new_restaurant(user_input, restaurant_record);
	}

	//Redirect based on result of account signup attempt
	switch (result) {
	case 1:		//successful account creation
		display_home_screen();
		break;
	case -1:	//user input invalid
		cout << "User input was invalid\nPress ENTER to return to Log In menu\n";
		getline(cin, input);
		display_start_up_screen();
		break;
	case -2:	//username already taken
		cout << "Username is already taken\nPress ENTER to return to Log In menu\n";
		getline(cin, input);
		display_start_up_screen();
		break;
	case 0:
	default:	//error
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}


//Update Personal Info
//Allows user to update their stored personal info
//Khoi Trinh
//04/11/22
void UserInterface::update_personal_info() {
	string input;
	clear_screen();
	vector<string> user_input;		//Array to pass information to UpdateInfo class to process

	cout << "Update Personal Info\n--------------------\n";
	user_input.push_back(user_record->get_username());		//Username pulled from records, cannot be changed
	
	//Get user password
	cout << "Verify Your Password: ";
	getline(cin, input);
	user_input.push_back(input);

	//Verifies password
	if (!UpdateInfo::validate_login(user_input[0], user_input[1], user_record)) {
		cout << "Password was invalid\nPress ENTER to return to Main Menu\n";
		getline(cin, input);
		return;
	}

	user_input.push_back(to_string(user_record->get_account_type()));		//Store password in results array
	
	//Get remaining user information
	get_user_info(user_input);

	//Calls UpdateInfo class to process updated user information
	int result = UpdateInfo::update_user_info(user_input, user_record);

	//Displays result based on message from UpdateInfo
	switch (result) {
	case 1:		//successful update
		cout << "User Information successfully updated\nPress ENTER to return to Main Menu\n";
		getline(cin, input);
		break;
	case -1:	//user not found in database
		cout << "User was not found in database\n";
	case 0:
	default:	//error
		cout << "Error encountered\nProgram terminating\n\n";
		exit(1);
	}
}




//-------------------- Customer Functions --------------------

//Check Order Status
//Allows customer to check the status of their order
//Khoi Trinh
//04/23/22
void UserInterface::check_order_status_customer() {
	clear_screen();
	//Calls CheckOrderStatus to check for orders based on user_id
	CheckOrderStatus::check_order_status_customer(user_record->get_user_id());
	pause();
}

//-------------------- Create Order and Related Helper Functions --------------------
//Create New Order
//Initialization of a new order
//Khoi Trinh
//04/23/22
void UserInterface::create_new_order() {
	//Calls search function to find a restaurant to select for the order
	int restaurant_id = search_for_restaurant();
	if (restaurant_id == -1)
		return;

	//Declare and initialize a CreateOrder object to handle processing for this process
	CreateOrder create_order;
	create_order.start_new_order(user_record->get_user_id(), restaurant_id, user_record->get_address());

	//Main loop for creating an order, repeat until order is submitted or user exits
	int result;
	while (true) {
		result = add_remove_items_to_order(create_order);
		if (result == -1)
			break;
	}
}

//Search for Restaurant
//Allows customer to search for and select a restaurant for their order
//Khoi Trinh
//04/23/22
int UserInterface::search_for_restaurant() {
	clear_screen();
	cout << "Searching for Restaurant\n\n";

	cout << "Please enter a search term: ";
	string search_term;
	getline(cin, search_term);

	//Creates Search object to process search results
	Search search;
	//Pair is <int restaurant_id, restaurant_name>
	vector<pair<int, string>> search_results = search.search(search_term);

	//Display a menu using the search results
	vector<string> menu_options;
	for (auto entry : search_results) {
		menu_options.push_back(entry.second);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Select a Restaurant to Begin Order");

	//Get restaurant selection
	int restaurant_selection = get_user_menu_selection(menu_options.size());

	if (restaurant_selection == menu_options.size())
		return -1;				//-1 indicates user exit

	restaurant_selection = search_results[restaurant_selection - 1].first;

	//Return restaurant_id
	return restaurant_selection;
}

//Add or Remove Items to Order
//Displays menu for user to choose to add, remove, or checkout order
//Khoi Trinh
//04/23/22
int UserInterface::add_remove_items_to_order(CreateOrder& create_order) {
	vector<string> menu_options = {"Add Item to Order", "Remove Item from Order", "Checkout", "Exit"};
	display_menu(menu_options, "Cart");

	int menu_selection = get_user_menu_selection(menu_options.size());

	int result = 0;
	switch (menu_selection) {
	case 1:
		add_item_to_order(create_order);
		break;
	case 2:
		remove_item_from_order(create_order);
		break;
	case 3:
		result = checkout_order(create_order);
		if (result == 1)
			return -1;
		break;
	case 4:
		return -1;
		break;
	default:
		cout << "Error encountered in add_remove_items_to_order\n\nTerminating application\n\n";
		exit(1);
	}
}

//Add Item to Order
//Allows customer to choose items to add to their order
//Khoi Trinh
//04/23/22
int  UserInterface::add_item_to_order(CreateOrder& create_order) {
	//Get all items from the restaurants menu
	vector<pair<int,string>> menu  = create_order.get_menu_options();

	//Gets the items in the menu and adds it to a vector to display
	vector<string> menu_options;
	for (auto item : menu)
		menu_options.push_back(item.second);
	menu_options.push_back("Exit");
	display_menu(menu_options, "Add Item to Order");
	
	int menu_selection = get_user_menu_selection(menu_options.size());
	if (menu_selection == menu_options.size())
		return -1;

	//Display more details of item that user selected
	clear_screen();
	auto item = create_order.get_item_by_id(menu[menu_selection - 1].first);
	cout << item.item_name << endl;
	cout << item.item_description << endl;
	cout.precision(2);
	cout << "$" << fixed << item.item_price << endl << endl;

	int quantity = -1;
	string user_input;
	string comment;

	//Get item quantity and comments
	cout << "How many would you like to order? ";

	//Input validation
	do {
		getline(cin, user_input);
		try {
			quantity = stoi(user_input);

			if (quantity < 0 || quantity > 99)
				cout << "Input was out of range. Please enter a value between 0 and 99: ";
		}
		catch (const exception&) {
			cout << "Input was invalid. Please enter a value between 0 and 99: ";
		}
	} while (quantity < 0 || quantity > 99);

	//If quantity 0, do not continue, return to previous screen
	if (quantity == 0)
		return 0;

	cout << "Enter any order comments or requests: ";
	getline(cin, comment);

	return create_order.add_item_to_order(item.menu_item_id, quantity, comment);
}

//Remove Item from Order
//Allows customer to delete a previously added item from their order
//Khoi Trinh
//04/23/22
int UserInterface::remove_item_from_order(CreateOrder& create_order) {
	//Gets array of items currently in the order
	auto order = create_order.get_order_items_list();

	//Displays menu screen with current items in order
	vector<string> menu_options;
	for (auto item : order) {
		string line = to_string(item.quantity) + "x ";
		line += create_order.get_item_by_id(item.item_id).item_name;
		menu_options.push_back(line);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Remove Item from Order");
	
	//Get user selection, return if user chooses exit
	int menu_selection = get_user_menu_selection(menu_options.size());
	if (menu_selection == menu_options.size())
		return -1;

	//Removes item from the order and returns result of that function call from the CreateOrder class
	return create_order.remove_item_from_order(order[menu_selection - 1]);
}

//Checkout Order
//Allows customer to review order and choose payment options for it
//Khoi Trinh
//04/23/22
int UserInterface::checkout_order(CreateOrder& create_order) {
	clear_screen();
	cout << "Reviewing Order...\n\n";
	//Gets list of all items in order
	auto order = create_order.get_order_items_list();

	//Return to previous menu if no items are in order
	if (order.size() == 0) {
		cout << "No items in order\n\nReturning to Order Menu\n\n";
		pause();
		return -1;
	}

	//Format and display information from order
	for (auto order_item : order) {
		auto menu_item = create_order.get_item_by_id(order_item.item_id);
		cout << menu_item.item_name << endl;
		if(!order_item.comments.empty())
			cout << "\t" << order_item.comments << endl;
		cout.precision(2);
		cout << "\t$" << fixed << menu_item.item_price << "   x" << order_item.quantity << endl;
	}
	cout << "\n----------------------------\n\n";

	//Gets subtotal and displays totals
	cout.precision(2);
	double subtotal = create_order.get_total_price();
	cout << fixed << setw(20) << left << "Subtotal: " << right << setw(10) << subtotal << endl;
	cout << setw(20) << left << "Tax: " << right << setw(10) << (subtotal * TAX_RATE) << endl << endl;
	cout << setw(20) << left << "Total: " << right << setw(10) << subtotal * (1 + TAX_RATE) << endl << endl;

	//Ask user to confirm order, with input validation
	string user_input;
	bool valid = false;
	cout << "Confirm Order? (y/n): ";
	do {
		getline(cin, user_input);
		if (user_input.compare("y") == 0 || user_input.compare("n") == 0)
			valid = true;
		else
			cout << "Please enter 'y' for yes or 'n' for no: ";
	} while (!valid);

	if (user_input.compare("n") == 0) {
		return -1;
	}

	//Go to payment selection screen
	return select_payment_option(create_order);
}

//Select Payment Option
//Allows customer to choose to use saved payment or enter new payment info
//Khoi Trinh
//04/23/22
int UserInterface::select_payment_option(CreateOrder& create_order) {
	vector<string> menu_options = { "Use Saved Payment", "Enter new Credit Card Info", "Exit"};
	display_menu(menu_options, "Cart");

	int menu_selection = get_user_menu_selection(menu_options.size());

	switch (menu_selection) {
	case 1:
		return use_saved_payment(create_order);
		break;
	case 2:
		return enter_new_payment(create_order);
		break;
	case 3:
		return -1;
		break;
	default:
		cout << "Error encountered in add_remove_items_to_order\n\nTerminating application\n\n";
		exit(1);
	}
}

//Use Saved Payment
//Allows customer to choose which saved payment to use, then submits order
//Khoi Trinh
//04/23/22
int UserInterface::use_saved_payment(CreateOrder& create_order) {
	//Gets list of saved payments
	auto saved_payments = create_order.get_saved_payments(user_record->get_user_id());
	vector<string> menu_options;
	
	//Displays menu with all saved payments
	for (auto payment : saved_payments) {
		menu_options.push_back(payment.first);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Choose a Credit Card");

	int menu_selection = get_user_menu_selection(menu_options.size());
	if (menu_selection == menu_options.size())
		return -1;
	
	//Submit payment with the selected credit card
	return create_order.submit_payment(saved_payments[menu_selection - 1].second, TAX_RATE, user_record->get_address());
}

//Enter New Payment
//Gets new payment information from customer, gives option to save that payment, then submits order
//Khoi Trinh
//04/23/22
int UserInterface::enter_new_payment(CreateOrder& create_order) {
	//Payment stores the payment record to write to database and send to SubmitPayment class
	string payment = to_string(user_record->get_user_id()) + ",";
	
	clear_screen();
	cout << "New Payment Information\n";
	cout << "-----------------------\n\n";
	cout << "Credit card number: ";

	//Get credit card number and validate that it is a number using uint_64_t since it is larger than an int
	bool valid = false;
	uint64_t cc_value_test;
	string user_input;
	do {
		getline(cin, user_input);
		istringstream cc(user_input);
		if (cc >> cc_value_test)
			valid = true;
		else
			cout << "Please enter a valid credit card number: ";
	} while (!valid);
	payment += user_input + ",";

	//Get expiration date and validate that it is a valid MMYY format
	cout << "Expiration date (mmyy): ";
	valid = false;
	int exp_date;
	do {
		getline(cin, user_input);
		istringstream exp(user_input);
		if (exp >> exp_date && exp_date < 1300 && exp_date > 100)
			valid = true;
		else
			cout << "Please enter a valid expiration date in mmyy format: ";
	} while (!valid);
	payment += user_input + ",";

	//Get CVV and check that it is 3 digits
	cout << "CVV: ";
	valid = false;
	int cvv_test;
	do {
		getline(cin, user_input);
		istringstream cvv(user_input);
		if (cvv >> cvv_test && cvv_test < 1000 && cvv_test >= 0)
			valid = true;
		else
			cout << "Please enter a valid three digit CVV: ";
	} while (!valid);
	payment += user_input + ",";

	//Get name on credit card
	cout << "Name on credit card: ";
	getline(cin, user_input);
	payment += user_input;

	//Ask user to save credit card, and validate user input
	cout << "Would you like to save this credit card for future use (y/n)? ";
	valid = false;
	do {
		getline(cin, user_input);
		if (user_input.compare("y") == 0 || user_input.compare("n") == 0)
			valid = true;
		else
			cout << "Please enter y or n: ";
	} while (!valid);

	//Submit the payment, save it if user selected 'y'
	return create_order.submit_payment(payment, TAX_RATE, user_record->get_address(), user_input.compare("y") == 0);
}


//-------------------- Driver Functions --------------------

//Accept or Reject Delivery
//Gets list of new delivery notifications and gives driver option to accept or reject those deliveries
//Khoi Trinh
//04/25/22
void UserInterface::accept_reject_delivery() {
	//Get list of notifications from AcceptRejectDelivery class
	vector<int> order_ids = AcceptRejectDelivery::get_new_delivery_requests(user_record->get_user_id());

	//Format and display those options to the menu
	vector<string> menu_options;
	for (int order_id : order_ids) {
		Order order(order_id);
		menu_options.push_back("Order #" + to_string(order_id) + ". Address: " + order.get_delivery_address());
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Select a New Delivery Request");
	int menu_selection = get_user_menu_selection(menu_options.size());

	if (menu_selection == menu_options.size())
		return;

	//After selection, displays more information about the order to the driver
	clear_screen();
	Order order(order_ids[menu_selection - 1]);
	cout << "Order #" << order.get_order_id() << endl;
	cout << "Customer Address: " << order.get_delivery_address() << endl;
	cout << "Restaurant Address: " << order.get_restaurant_address() << endl;
	cout << "------------------------------------------------------\n\n";

	//Get driver decision to accept or decline, with input validation
	string user_input;
	bool valid = false;
	cout << "Would you like to accept or decline the delivery (a/d)? ";
	do {
		getline(cin, user_input);
		if (user_input.compare("a") == 0 || user_input.compare("d") == 0)
			valid = true;
		else
			cout << "Please enter either a or d: ";
	} while (!valid);

	//Run different accept or reject functions based on result of input
	if (user_input.compare("a") == 0) {
		AcceptRejectDelivery::accept_delivery(order.get_order_id(), user_record->get_user_id());
	}
	else {
		AcceptRejectDelivery::reject_delivery(order.get_order_id(), user_record->get_user_id());
	}
}

//Check Order Status Driver
//Gets status of all active orders for the driver and displays them
//Khoi Trinh
//04/25/22
void UserInterface::check_order_status_driver() {
	clear_screen();
	CheckOrderStatus::check_order_status_driver(user_record->get_user_id());
	pause();
}

//Confirm Delivery
//Gets list of active orders and allows driver to update the status to delivered
//Khoi Trinh
//04/25/22
void UserInterface::confirm_delivery() {
	//Get list of active orders from the Order class
	vector<int> order_ids = Order::get_active_orders_drivers(user_record->get_user_id());

	//Format and display it in a menu for user selection
	vector<string> menu_options;
	for (auto itr = order_ids.begin(); itr != order_ids.end();) {
		Order order((*itr));
		if (order.get_order_status() < OrderStatus::delivered) {
			menu_options.push_back("Order #" + to_string((*itr)) + ". Address: " + order.get_delivery_address());
			++itr;
		}
		else{
			itr = order_ids.erase(itr);
		}
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Choose Delivery to Confirm");

	int menu_selection = get_user_menu_selection(menu_options.size());
	if (menu_selection == menu_options.size())
		return;
	
	//Confirms delivery based on driver input selection
	ConfirmDelivery::confirm_delivery(order_ids[menu_selection - 1]);
}




//-------------------- Restaurant Functions --------------------

//Accept or Decline Order
//Gets list of new orders, allows restaurant to accept or decline the order
//Khoi Trinh
//04/25/22
void UserInterface::accept_decline_order() {
	//Get list of new order notifications
	vector<int> order_ids = AcceptDeclineOrder::get_new_order_requests(user_record->get_user_id());

	//Format and display list of orders in a menu
	vector<string> menu_options;
	for (int order_id : order_ids) {
		Order order(order_id);
		menu_options.push_back("Order #" + to_string(order_id));
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Select an Order to View");
	int menu_selection = get_user_menu_selection(menu_options.size());

	if (menu_selection == menu_options.size())
		return;

	//get the order object and display information about the order and items in the order
	clear_screen();
	Order order(order_ids[menu_selection - 1]);
	vector<Order::OrderItem> order_items = order.get_order_items_list();

	cout << "Order #" << order.get_order_id() << endl;
	for (auto item : order_items) {
		cout << order.get_item_by_id(item.item_id).item_name << endl;
		cout << "\t" << item.comments << endl;
		cout << "\tx" << item.quantity << endl << endl;
	}
	cout << "------------------------------------------------------\n\n";

	//Ask user to accept or decline order, with input validation
	string user_input;
	bool valid = false;
	cout << "Would you like to accept or decline the order (a/d)? ";
	do {
		getline(cin, user_input);
		if (user_input.compare("a") == 0 || user_input.compare("d") == 0)
			valid = true;
		else
			cout << "Please enter either a or d: ";
	} while (!valid);

	//Run accept or decline functions based on input
	if (user_input.compare("a") == 0) {
		AcceptDeclineOrder::accept_order(order.get_order_id(), user_record->get_user_id());
	}
	else {
		AcceptDeclineOrder::decline_order(order.get_order_id(), user_record->get_user_id());
	}
}

//Update Order Status
//Restaurant user can update status of an active order
//Khoi Trinh
//04/25/22
void UserInterface::update_order_status() {
	//Get list of active orders
	vector<int> order_ids = Order::get_active_orders_restaurants(user_record->get_user_id());

	//Formats and displays list of orders
	vector<string> menu_options;
	for (int order_id : order_ids) {
		menu_options.push_back(to_string(order_id));
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Choose Order to Update Status");

	//Get user selection on which order to change
	int index_order = get_user_menu_selection(menu_options.size());
	if (index_order == menu_options.size())
		return;

	//Display new status options and gets user input
	menu_options = { "Under Review", "Confirmed", "Preparing", "Completed","Exit" };
	display_menu(menu_options, "Order #" + to_string(order_ids[index_order - 1]));
	int menu_selection = get_user_menu_selection(menu_options.size());
	
	//Gets status code based on user selection
	int status = 0;
	switch (menu_selection) {
	case 1:
		status = OrderStatus::review;
		break;
	case 2:
		status = OrderStatus::confirmed;
		break;
	case 3:
		status = OrderStatus::prepared;
		break;
	case 4:
		status = OrderStatus::completed;
		break;
	case 5:
		return;
	default:
		cout << "Invalid menu selection\n\nTerminating application\n\n";
		exit(1);
	}

	//Updates order status based on status
	UpdateOrderStatus::update_order_status(order_ids[index_order - 1], status);
}

//Show Pending Orders
//Gets list of pending orders for the restaurant and displays it in a report
//Khoi Trinh
//04/25/22
void UserInterface::show_pending_orders() {
	clear_screen();
	ShowPendingOrders::show_pending_orders(user_record->get_user_id());
	pause();
}

//-------------------- Restaurant Update Menu Functions --------------------
//Update Menu Screen
//Main loop to display options for updating menu.
//Khoi Trinh
//04/25/22
void UserInterface::display_update_menu_screen() {
	vector<string> menu_options = { "Add Item", "Update Item", "Delete Item", "Exit"};
	while (true) {
		display_menu(menu_options, "Update Menu");

		int user_input = get_user_menu_selection(menu_options.size());

		switch (user_input) {
		case 1:
			add_menu_item();
			break;
		case 2:
			update_menu_item();
			break;
		case 3:
			delete_menu_item();
			break;
		case 4:
			return;
		default:
			cout << "Error encountered\nProgram terminating\n\n";
			exit(1);
		}
	}
}

//Add Menu Item
//Gets new menu item into and passes to UpdateMenu class to generate a new menu item
//Khoi Trinh
//04/25/22
void UserInterface::add_menu_item() {
	clear_screen();
	vector<string> user_input;

	cout << "Add Menu Item\n--------------------\n";
	//Gets new item info
	get_menu_item_info(user_input);

	UpdateMenu::add_menu_item(user_input, restaurant_record);
}

//Update Menu Item
//Gets user selection for item to change, then gets new info for that item and updates it
//Khoi Trinh
//04/25/22
void UserInterface::update_menu_item() {
	//Get list of all current menu items and displays it on a menu screen
	vector<pair<int,string>> menu_item_list = restaurant_record->get_list_menu_item_names();
	vector<string> menu_options;
	for (auto item : menu_item_list) {
		menu_options.push_back(item.second);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Update Menu Item");

	int user_selection = get_user_menu_selection(menu_options.size());

	//If exit chosen, return
	if (user_selection == menu_options.size()) {
		return;
	}

	vector<string> user_input;

	cout << "Update Menu Item\n--------------------\n";
	//Get new item info
	get_menu_item_info(user_input);

	//Send item info to UpdateMenu to update
	UpdateMenu::update_menu_item(user_input, restaurant_record, menu_item_list[user_selection - 1].first);
}

//Delete Menu Item
//Gets list of menu items and lets user delete one
//Khoi Trinh
//04/25/22
void UserInterface::delete_menu_item() {
	//Get list of current menu items, displays in menu screen
	vector<pair<int, string>> menu_item_list = restaurant_record->get_list_menu_item_names();
	vector<string> menu_options;
	for (auto item : menu_item_list) {
		menu_options.push_back(item.second);
	}
	menu_options.push_back("Exit");
	display_menu(menu_options, "Delete Menu Item");

	int user_selection = get_user_menu_selection(menu_options.size());

	if (user_selection == menu_options.size()) {
		return;
	}

	//Deletes the item that user selected
	UpdateMenu::delete_menu_item(restaurant_record, menu_item_list[user_selection - 1].first);
}



//-------------------- Helper Functions --------------------

//Display Menu
//Gets vector of options and formats and displays it in a menu
//Khoi Trinh
//04/12/22
void UserInterface::display_menu(vector<string>& menu_options, string menu_title) {
	clear_screen();
	
	//Display top border
	cout << setfill('-') << setw(UI_MENU_WIDTH) << "-" << endl << setfill(' ');

	//Display title, centered
	int spacing = (UI_MENU_WIDTH - menu_title.length()) / 2;
	cout << setw(spacing) << left << "|";
	cout << menu_title;
	if ((menu_title.length() + UI_MENU_WIDTH) % 2)				//If number of spaces needed is odd, add an extra space to the right side
		spacing++;
	cout << setw(spacing) << right << "|" << endl << left;

	//Display middle border
	cout << setfill('-') << setw(UI_MENU_WIDTH) << "-" << endl << setfill(' ');

	//Display menu options
	for (int i = 0; i < menu_options.size(); i++) {
		string line = "| ";
		line += to_string(i + 1);
		line += ". ";
		if (i + 1 < 10) line += " ";							//If displayed menu option number is less than 10, add extra space to line up text
		line += menu_options[i];
		cout << setw(UI_MENU_WIDTH - 1) << line << "|" << endl;
	}

	//Display bottom border
	cout << setfill('-') << setw(UI_MENU_WIDTH) << "-" << endl << endl << setfill(' ');
}

//Get User Menu Selection
//Gets user input and validates it is an int less than the max option
//Khoi Trinh
//04/12/22
int UserInterface::get_user_menu_selection(int max_valid_input) {
	string user_input;
	int option = -1;

	cout << "Please select a menu option." << endl;

	do {
		getline(cin, user_input);

		try {
			option = stoi(user_input);
		}
		catch (const invalid_argument) {
			cout << "Invalid input. Please enter a number between 1 and " << max_valid_input << endl;
		}

		if (option > max_valid_input) {
			cout << "Number out of range. Please enter a number between 1 and " << max_valid_input << endl;
			option = -1;
		}
	} while (option < 0 || option > max_valid_input);

	return option;
}

//Clear Screen
//Clears the screen to prepare for further output
//Khoi Trinh
//04/12/22
void UserInterface::clear_screen() {
	cout << flush;
	system("CLS");
}

//Get User Info
//Gets user info to add or update a user
//Khoi Trinh
//04/12/22
void UserInterface::get_user_info(vector<string>& user_input) {
	string input;
	cout << "First Name: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Last Name: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Address: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Phone Number: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Email: ";
	getline(cin, input);
	user_input.push_back(input);
}

//Get Restaurant Info
//Gets info to add or update a restaurant
//Khoi Trinh
//04/12/22
void UserInterface::get_restaurant_info(vector<string>& user_input) {
	string input;

	user_input.push_back(to_string(user_record->get_user_id()));

	cout << "Restaurant Name: ";
	getline(cin, input);
	user_input.push_back(input);

	user_input.push_back(user_record->get_address());

	cout << "Restaurant Type: ";
	getline(cin, input);
	user_input.push_back(input);
}

//Get Menu Item Info
//Gets Gets information to add or update a menu item, with data validation for prices
//Khoi Trinh
//04/12/22
void UserInterface::get_menu_item_info(vector<string>& user_input) {
	string input;
	double price = -1.0;

	cout << "Item Name: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Item Description: ";
	getline(cin, input);
	user_input.push_back(input);

	cout << "Item Price: ";

	do {
		getline(cin, input);

		try {
			price = stoi(input);
		}
		catch (const invalid_argument) {
			cout << "Invalid input. Please enter a number " << endl;
		}

		if (price <= 0) {
			cout << "Number out of range. Please enter a number greater than 0" << endl;
			price = -1;
		}
	} while (price < 0);

	user_input.push_back(input);
}

//Get Restaurant Record
//Fetches restaurant record from database
//Khoi Trinh
//04/12/22
void UserInterface::get_restaurant_record() {
	int result = Restaurant::get_restaurant_record(user_record->get_user_id(), restaurant_record);
	if (result == 0) {
		cout << "Error encountered\nRestaurant not found in database.\nProgram terminating\n\n";
		exit(1);
	}
}

//Pause Screen
//Pauses screen to let user read, continues after user input
//Khoi Trinh
//04/12/22
void UserInterface::pause() {
	string temp;
	cout << "Press Enter to Continue\n\n";
	getline(cin, temp);
}