#include "PendingOrderReport.h"

using namespace std;

//Receives all information from 1 order
void PendingOrderReport::Orders(int OrderID, vector<string>& ItemList, 
	vector<int>& quantity, vector<string>& comments, string orderStatus) {
	
	cout << "-------------------------"<<endl;
	cout << "Order ID: " << OrderID << endl;
	//for loop prints items
	for (int i = 0; i < ItemList.size(); i++){
		cout << ItemList[i] << " ";
		//function call to print quantity of items
		displayQuantity(quantity, i);
		//function call to print comments of items
		displayComments(comments, i);
		cout << endl;
	}
	
	cout << "Order Status: " << orderStatus << endl;;
	cout << "-------------------------";
}
//function with for loop to print quantity of items
void PendingOrderReport::displayQuantity(vector<int>& quantity, int index) {
	for (int i = index; i < quantity.size(); i++) {
		cout << "qty(" << quantity[i] << ")" << endl;
		break;//stops for loop to only print quantity for index
	}

}
//function with for loop to print comments, if any, of items
void PendingOrderReport::displayComments(vector<string>& comments, int index) {
		for (int i = index; i < comments.size(); i++) {
			if (comments[i] == " ") {
				cout << "Comments: None"<<endl;
				break;
			}
			else {
				cout << "Comments: " << comments[i] << endl;
				break;
			}
	}

}
