#include "Automata.h"
std::pair<std::vector<std::string>, std::vector<int>> ReadFromFile(std::string filename)
{
	setlocale(LC_ALL, "Russian");
	std::string line;
	std::vector<std::string> lines;
	std::ifstream file(filename);
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
	std::vector<std::string> menu;
	std::vector<int> prices;
	for (int i = 0; i < lines.size(); i++)
	{
		auto pos = lines[i].find(" ");
		menu.push_back(lines[i].substr(0, pos));
		prices.push_back(stoi(lines[i].substr(pos + 1)));
	}
	std::pair< std::vector<std::string>, std::vector<int>> data = std::make_pair(menu, prices);
	return data;
}
Automata::Automata(std::vector<std::string> menu, std::vector<int> prices)
{
	Cash = 0;
	Menu = menu;
	Prices = prices;
	State = OFF;
	ChosenPosition = -1;
}
void Automata::On()
{
	if (State == OFF)
	{
		State = WAIT;
		std::cout << "Автомат включён!" << std::endl;
	}
}
void Automata::Off()
{
	if (State == WAIT)
	{
		State = OFF;
		std::cout << "Автомат выключен!" << std::endl;
	}
}
void Automata::Coin(unsigned int value)
{
	if (State == WAIT || State == ACCEPT)
	{
		State = ACCEPT;
		Cash += value;
		std::cout << "Внесено: " << value << std::endl << "Баланс: " << Cash << std::endl;
	}
}
void Automata::GetMenu()
{
	for (int i = 0; i < Menu.size(); i++)
	{
		std::cout << i + 1 << ". " << Menu[i] << " " << Prices[i] << std::endl;
	}
}
STATES Automata::GetState()const
{
	std::string stateToText;
	switch (State)
	{
	case 0:
		stateToText = "Off";
		break;
	case 1:
		stateToText = "Wait";
		break;
	case 2:
		stateToText = "Accept";
		break;
	case 3:
		stateToText = "Check";
		break;
	case 4:
		stateToText = "Cook";
		break;
	default:
		stateToText = "";
		break;
	}
	std::cout << "Текущее состояние: " << stateToText << std::endl;
	return State;
}
void Automata::Choice(int index)
{
	if (State == ACCEPT)
	{
		if (index < Menu.size() && index >= 0)
		{
			State = CHECK;
			std::cout << "Вы выбрали: " << Menu[index] << std::endl;
			ChosenPosition = index;
			Check();
		}
		else std::cout << "Товар не найден!" << std::endl;
	}
}
void Automata::Check()
{
	if (State == CHECK)
	{
		if (Cash < Prices[ChosenPosition])
		{
			std::cout << "Недостаточно средств!";
			State = ACCEPT;
		}
		else std::cout << "Подтвердите выбор " << Menu[ChosenPosition] << std::endl;
	}
}
void Automata::Cancel()
{
	if (State == ACCEPT || State == CHECK)
	{
		State = WAIT;
		std::cout << "Заказ отменён, деньги возвращены." << std::endl;
		Cash = 0;
		ChosenPosition = -1;
	}
}
void Automata::Cook(bool printState)
{
	if (State == CHECK)
	{
		State = COOK;
		std::cout << "Ваш " << Menu[ChosenPosition] << " готовится..." << std::endl;
		if (printState) GetState();
		Cash -= Prices[ChosenPosition];
		std::cout << "..." << std::endl << "Ваш " << Menu[ChosenPosition] << " готов!" << std::endl;
		Finish();
	}
}
void Automata::Finish()
{
	if (State == COOK)
	{
		State = WAIT;
		std::cout << "Сдача: " << Cash << std::endl << "Хорошего дня!" << std::endl;
		Cash = 0;
		ChosenPosition = -1;
	}
}