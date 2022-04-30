#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "UpdateOrderStatus.h"

using namespace std;

class ConfirmDelivery {

private:

public:
	static int confirm_delivery(int order_id);
};