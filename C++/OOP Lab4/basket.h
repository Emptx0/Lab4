#pragma once
#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <vector>
#include "mushrooms.h"

class Basket {
private:
	std::vector<Mushroom*> items;
public:
	~Basket();
	void addItem(Mushroom*);
	void calculateResult();
};

#endif