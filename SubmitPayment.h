#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SubmitPayment {
private:
	static string submitted_payments_file;
public:
	static int submit_payment(int order_id, double total, string payment_info);
};