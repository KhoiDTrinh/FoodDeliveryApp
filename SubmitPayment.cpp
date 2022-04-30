#include "SubmitPayment.h"
/*Artifact Name: Submit Payment
* It will obtain all the data to complete the payment such as 
the order ID, the total cost of the products, and all the payment information.
* Vanessa Corral
* Khoi Trinh
* 4/14/2022
*/

using namespace std;


/*Artifact Name: submitted_payment_files
* the data stored in the "SubmittedPayments.txt" are pushed 
* in the submitted_payment_files artifact.
* Vanessa Corral
* 4/15/2022
*/
string SubmitPayment::submitted_payments_file = "SubmittedPayments.txt";

/*Artifact Name: submit_payment
* Recieves data from order_id, total, and payment_info
* and pushes it into a file.
* Vanessa Corral
* 4/15/2022
*/
int SubmitPayment::submit_payment(int order_id, double total, string payment_info) {
	string output = to_string(order_id) + "," + to_string(total) + "," + payment_info;		//Conversts data into string for all 3: order_id, total, payment_info then puts it under the name output

	ofstream file;										// Creates a file to be able to write data into.
	file.open(submitted_payments_file, ios::app);		// Opens the file named submitted_payment_info (contains "SubmittedPayment.txt")
	file << output << endl;								// Writes data in the string output into the file.
	file.close();										// Closes the file

	return 1;
}