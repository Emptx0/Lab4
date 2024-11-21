#include "ui.h"
#include "exceptions.h"

void UI::getMushroomFromUser(Forest& forest, ForestRepository& repo) {
	system("cls");
	std::string name;
	bool eatable;
	int treatment;

	try
	{
		std::cout << "Enter mushroom name: ";
		std::cin >> name;
		if (std::cin.fail())
		{
			throw std::invalid_argument("Invalid input!");
		}
		std::cout << "Is mushroom eatable? (1/0): ";
		std::cin >> eatable;
		if (std::cin.fail())
		{
			throw std::invalid_argument("Invalid input!");
		}
		std::cout << "Enter heat treatment time for mushroom in minutes: ";
		std::cin >> treatment;
		std::cout << "\n";
		if (std::cin.fail())
		{
			throw std::invalid_argument("Invalid input!");
		}
	}
	catch (const std::invalid_argument& e)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Caught exception: " << e.what() << std::endl;
		system("pause");
		return;
	}

	repo.addMushroomToForest(name, eatable, treatment, forest);
}

void UI::getBasketFromUser(Basket& basket, Forest& forest) {
	system("cls");
	std::vector<Mushroom*> mushroomList = forest.getMushrooms();
	std::cout << "Enter 'd' if done" << std::endl << "Enter mushroom: ";

	while (true) {
		std::string name;
		std::cin >> name;
		try
		{
			if (name == "d") {
				break;
			}
			else {
				int counter = 0;
				for (auto mushroom : mushroomList) {
					if (name == mushroom->getName()) {
						basket.addItem(mushroom);
						counter++;
						break;
					}
				}
				if (counter == 0) {
					throw std::invalid_argument("Unknown mushroom: " + name);
				}
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	basket.calculateResult();
}

void UI::showMushrooms(Forest& forest) {
	system("cls");
	if (!forest.getMushrooms().empty()) 
	{
		std::cout << "NAME  |  EATABLE  |  TREATMENT" << std::endl;
		for (auto mushroom : forest.getMushrooms()) {
			std::cout << *mushroom << std::endl;
		}
	}
	else
	{
		throw ListException();
	}
	
	system("pause");
}

void UI::showMenu() {
	system("cls");
	std::cout << "1. Add mushroom" << std::endl;
	std::cout << "2. Show mushrooms in forest" << std::endl;
	std::cout << "3. Calculate eatable percent and treatment time" << std::endl;
	std::cout << "4. Exit" << std::endl;
}