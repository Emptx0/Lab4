#include <iostream>
#include <string>
#include <vector>
#include "mushrooms.h"
#include "forest.h"
#include "ui.h"
#include "exceptions.h"

int main() {
	ForestRepository repository("MushroomsList.txt");
	UI ui;
	Forest forest;
	repository.loadMushroomsList(forest);
	Basket basket;

	while (true) {
		ui.showMenu();
		int choice;
		std::cin >> choice;
		try 
		{
			if (choice == 1) {
				ui.getMushroomFromUser(forest, repository);
			}
			else if (choice == 2) {
				ui.showMushrooms(forest);
			}
			else if (choice == 3) {
				ui.getBasketFromUser(basket, forest);
			}
			else if (choice == 4) {
				break;
			}
			else {
				throw ChoiceError();
			}
		}
		catch (const MyBaseException& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
			system("pause");
		}
		
	}
}