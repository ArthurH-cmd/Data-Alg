#include <iostream>
#include "Array.h"
#include "Vector.h"
#include <chrono>
#include "PriorityQueue.h"

enum ItemType 
{
	sHealthPack,
	mHealthPack,
	pyroGrenade,
	frostGrenade,
	bigAssStick
};

class Item 
{
public:

	std::string mName;
	ItemType mType;
	
	int mValue;
	int mCount;

	Item(ItemType itemType, int value) 
	{
		mType = itemType;
		mValue = value;
		switch (itemType)
		{
		case sHealthPack:
			mName = "Small Health Pack";
			break;
		case mHealthPack:
			mName = "Medium Health Pack";
			break;
		case pyroGrenade:
			mName = "Pyro Grenade";
			break;
		case frostGrenade:
			mName = "Frost Grenade";
			break;
		case bigAssStick:
			mName = "BIG AH STICK";
		}
	}

	Item()
		: mName("Unknown Item"), mType(sHealthPack), mValue(0), mCount(0)
	{
	}

	void AddItem() 
	{
		mCount += 1;
	}

	void UseItem() 
	{
		if (mCount >= 0)
			mCount -= 1;
		else
			std::cout << "NO ITEMS LEFT ";
	}
};

class Inventory
{
	Vector<Item> mInventory;



	void initializeInventory(int numItemsToAdd) 
	{

		mInventory.Resize(numItemsToAdd);

		for (int i = 0; i < numItemsToAdd; ++i)
		{
			mInventory.Pushback(Item(sHealthPack, 5));
			mInventory.
		}
	}


};