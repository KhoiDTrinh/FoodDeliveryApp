#pragma once
#include <string>
#include <iostream>
#include <vector>


class Cart
{
private:

public:

	static void addItemToCart(int new_ItemID, int new_ItemQuantity, string new_ItemComment, float new_ItemPrice);
	static void removeItemFromCart(int itemID);
	static float getTotalAmount();
	static void setRestaurantID(int restaurantID);
	static const vector<int> getItemID();
	static const vector<float> getItemQuantity();
	static const vector<float> getItemPrice();
	static const vector<string> getItemComments();
	static const int getRestaurantID();
};