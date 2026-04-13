#include "Automata.h"
int main()
{
	std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile("input.txt");
	Automata automata = Automata(data.first, data.second);
	automata.GetState();
	automata.On();
	automata.GetState();
	automata.GetMenu();
	automata.Coin(80);
	automata.GetState();
	automata.Coin(20);
	automata.GetState();
	automata.Choice(1);
	automata.GetState();
	automata.Cook(true);
	if (automata.GetState() != WAIT)
	{
		automata.Cancel();
		automata.GetState();
	}
	automata.Off();
	automata.GetState();
}