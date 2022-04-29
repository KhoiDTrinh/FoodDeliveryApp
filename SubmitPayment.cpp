#include "SubmitPayment.h"

using namespace std;

string SubmitPayment::submitted_payments_file = "SubmittedPayments.txt";

int SubmitPayment::submit_payment(int order_id, double total, string payment_info) {
	string output = to_string(order_id) + "," + to_string(total) + "," + payment_info;

	ofstream file;
	file.open(submitted_payments_file, ios::app);
	file << output << endl;
	file.close();

	return 1;
}