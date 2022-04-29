#define _CRT_SECURE_NO_WARNINGS
#include "OrderStatus.h"
#include <string>
#include<iostream>
#include<ctime>

using namespace std;

//fuction receives int status
void OrderStatus::displayOrderStatus(int status) {
	string now;

	//switch between the different types of status and prints time
	switch (status) {
		case 0:
		cout << "Order is being Reviewed\n";
		cout << now << endl;
		break;
		case 1:
		cout << "Order has been Confirmed\n";
		cout << now << endl;
		break;
		case 2:
		cout << "Order is being Prepared\n"; 
		cout << now << endl;
		break;
		case 3:
		cout << "Order has been Completed\n"; 
		cout << now << endl;
		break;
		case 4:
		cout << "Order has been Delivered\n"; 
		break;
		default:
		cout << "Error";
	}
}