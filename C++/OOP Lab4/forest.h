#pragma once
#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include "mushrooms.h"

class Forest {
private:
	std::vector<Mushroom*> mushrooms;
public:
	~Forest();
	std::vector<Mushroom*> getMushrooms();
	void addMushroom(Mushroom*&);
	void clearMushrooms();
};

class ForestRepository {
private:
	std::string filename;
public:
	ForestRepository(std::string);

	void addMushroomToForest(std::string, bool, int, Forest&);
	void loadMushroomsList(Forest&);
};

#endif

