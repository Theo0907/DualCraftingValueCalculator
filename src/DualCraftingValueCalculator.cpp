// DualCraftingValueCalculator.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "ItemsHandler.h"
#include <unordered_map>

int main()
{
	ItemsHandler h;
	if (!h.LoadJson())
	{
		std::cout << "Failed to load" << std::endl;
		return -1;
	}
	bool quit = false;

	while (!quit)
	{
		std::string message;
		std::getline(std::cin, message);

		if (message.compare(0, 7, "compute") == 0)
		{
			CraftSkills s;
			ProductionData d;
			auto p = h.GetPrice(message.substr(8), s, d);
			if (p.first == -1)
			{
				if (p.second == -1)
					std::cout << "The item you are searching for doesn't exist." << std::endl;
				else
					std::cout << "There whas an error while computing value." << std::endl;
			}
			else
			{
				std::cout << "Crafting cost:\t" << p.first << std::endl;
				if (p.second != -1)
				{
					std::cout << "Shop cost:\t" << p.second << std::endl;
					std::cout << "Benefits:\t" << (p.second - p.first) << std::endl;
				}
				std::cout << "Total used items: " << std::endl;
				for (auto& it : d.CraftedItems)
					std::cout << "\t-" << it.first->GetName() << " : " << it.second << std::endl;
			}
		}
		else if (message.compare(0, 4, "list") == 0)
		{
			if (message.size() < 5)
				h.List();
			else
				h.List(message.substr(5));
		}
		else if (message.compare(0, 4, "help") == 0)
		{
			std::cout << "Command list: \nlist: lists all crafts. You can give it a search term.\ncompute: Computes price of given item. Case sensitive.\nquit: exits the program" << std::endl;
		}
		else if (message.compare(0, 4, "quit") == 0)
		{
			quit = true;
		}
	}
	//auto p = h.GetPrice("BasicSpaceEngineL", s);
	//auto p = h.GetPrice("XLAmmoContainerL", s);

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
