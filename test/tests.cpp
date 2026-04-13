#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Automata.h"
#include "../src/Automata.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(tests)
	{
		std::string filepath = ""; //вставьте полный путь до файла
	public:
		TEST_METHOD(TestMethod1)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.Coin(5);
			automata.Choice(1);
			automata.Cancel();
			Assert::IsTrue(automata.GetState() == OFF);
		}
		TEST_METHOD(TestMethod2)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(80);
			automata.Choice(0);
			Assert::IsTrue(automata.GetState() == CHECK);
		}
		TEST_METHOD(TestMethod3)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Off();
			automata.On();
			automata.Coin(100);
			automata.Choice(1);
			automata.Cook(false);
			Assert::IsTrue(automata.GetState() == WAIT);
		}
		TEST_METHOD(TestMethod4)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(1);
			automata.Coin(1);
			automata.Coin(1);
			automata.Coin(1);
			automata.Coin(1);
			Assert::IsTrue(automata.GetState() == ACCEPT);
		}
		TEST_METHOD(TestMethod5)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(79);
			automata.Choice(0);
			Assert::IsTrue(automata.GetState() == ACCEPT);
		}
		TEST_METHOD(TestMethod6)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(25);
			automata.Coin(90);
			automata.Choice(2);
			automata.Choice(3);
			automata.Check();
			automata.Off();
			automata.On();
			automata.Check();
			automata.Finish();
			Assert::IsTrue(automata.GetState() == CHECK);
		}
		TEST_METHOD(TestMethod7)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(100);
			automata.Choice(3);
			automata.Coin(50);
			automata.Choice(3);
			automata.Cook(false);
			automata.Coin(75);
			automata.Choice(0);
			automata.Coin(25);
			automata.Choice(0);
			automata.Choice(1);
			automata.Cook(false);
			automata.Off();
			Assert::IsTrue(automata.GetState() == OFF);
		}
		TEST_METHOD(TestMethod8)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(100);
			automata.Choice(3);
			automata.Coin(50);
			automata.Choice(3);
			automata.Cancel();
			Assert::IsTrue(automata.GetState() == WAIT);
		}
		TEST_METHOD(TestMethod9)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.On();
			automata.Coin(1);
			automata.Coin(15);
			automata.Cancel();
			automata.Coin(115);
			automata.Choice(2);
			automata.Cancel();
			automata.Coin(1155);
			automata.Choice(3);
			Assert::IsTrue(automata.GetState() == CHECK);
		}
		TEST_METHOD(TestMethod10)
		{
			std::pair< std::vector<std::string>, std::vector<int>> data = ReadFromFile(filepath);
			Automata automata = Automata(data.first, data.second);
			automata.Check();
			automata.Cook(false);
			automata.Finish();
			automata.Off();
			automata.On();
			automata.On();
			automata.Coin(555);
			automata.Off();
			automata.Cancel();
			automata.Coin(55);
			automata.Choice(2);
			automata.Off();
			automata.Coin(55);
			automata.Choice(2);
			automata.Off();
			automata.Coin(55);
			automata.Choice(2);
			automata.Off();
			automata.Finish();
			automata.Cancel();
			automata.Cook(false);
			automata.Check();
			automata.Choice(-3);
			automata.Coin(130);
			automata.Choice(-3);
			automata.Choice(-3);
			automata.Choice(3);
			automata.Cook(false);
			automata.Cook(false);
			Assert::IsTrue(automata.GetState() == WAIT);
		}
	};
}
