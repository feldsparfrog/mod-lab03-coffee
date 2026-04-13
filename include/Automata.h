#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <vector>
#include <string>
#include <iostream>
#include <locale>
#include <fstream>
std::pair<std::vector<std::string>, std::vector<int>> ReadFromFile(std::string filename);
enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
class Automata
{
	unsigned int Cash;
	std::vector<std::string> Menu;
	std::vector<int> Prices;
	STATES State;
	int ChosenPosition;
	public:
		Automata(std::vector<std::string> menu, std::vector<int> prices);
		void On();
		void Off();
		void Coin(unsigned int value);
		void GetMenu();
		STATES GetState()const;
		void Choice(int index);
		void Check();
		void Cancel();
		void Cook(bool printState);
		void Finish();
};
#endif