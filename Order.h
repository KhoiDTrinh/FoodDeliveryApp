#pragma once
#include <iostream>
#include <string>
#include "UpdateOrderStatus.h"
#include "Cart.h"
#include "Alert.h"
#include "OrderStatus.h"

using namespace std;

class Order{
private:

public:
	static int updateOrderStatus(int status);
	static void createOrderFromClass(Cart cart);
	static void displayOrderStatus()
	{
		int orderstatus;
		OrderStatus::displayOrderStatus(orderstatus);
	}

	static int getOrderStatus();
	static int getOrderID();
	static int getItemQuantity();
	static int getUserID();
	static int getItemList();
	static void sendDeliveryAlert();
	static void restaurantAccept();
	static void restaurantDecline(string reason);
	static void driverDecline();
};