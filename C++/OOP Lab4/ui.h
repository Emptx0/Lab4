#pragma once
#ifndef UI_H
#define UI_H

#include "forest.h"
#include "basket.h"

class UI {
public:
	void getMushroomFromUser(Forest&, ForestRepository&);
	void getBasketFromUser(Basket&, Forest&);
	void showMushrooms(Forest&);
	void showMenu();
};

#endif