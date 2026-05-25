// Copyright 2020 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(Tests, TestMethod1) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
    Automata automata = Automata(data.first, data.second);
    automata.Coin(5);
    automata.Choice(1);
    automata.Cancel();
    EXPECT_EQ(automata.GetState(), OFF);
}
TEST(Tests, TestMethod2) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
    Automata automata = Automata(data.first, data.second);
    automata.On();
    automata.Coin(80);
    automata.Choice(0);
    EXPECT_EQ(automata.GetState(), CHECK);
}
TEST(Tests, TestMethod3) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
    Automata automata = Automata(data.first, data.second);
    automata.On();
    automata.Off();
    automata.On();
    automata.Coin(100);
    automata.Choice(1);
    automata.Cook(false);
    EXPECT_EQ(automata.GetState(), WAIT);
}
TEST(Tests, TestMethod4) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
    Automata automata = Automata(data.first, data.second);
    automata.On();
    automata.Coin(1);
    automata.Coin(1);
    automata.Coin(1);
    automata.Coin(1);
    automata.Coin(1);
    EXPECT_EQ(automata.GetState(), ACCEPT);
}
TEST(Tests, TestMethod5) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
    Automata automata = Automata(data.first, data.second);
    automata.On();
    automata.Coin(79);
    automata.Choice(0);
    EXPECT_EQ(automata.GetState(), ACCEPT);
}
TEST(Tests, TestMethod6) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
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
    EXPECT_EQ(automata.GetState(), CHECK);
}
TEST(Tests, TestMethod7) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
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
    EXPECT_EQ(automata.GetState(), OFF);
}
TEST(Tests, TestMethod8) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
    Automata automata = Automata(data.first, data.second);
    automata.On();
    automata.Coin(100);
    automata.Choice(3);
    automata.Coin(50);
    automata.Choice(3);
    automata.Cancel();
    EXPECT_EQ(automata.GetState(), WAIT);
}
TEST(Tests, TestMethod9) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
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
    EXPECT_EQ(automata.GetState(), CHECK);
}
TEST(Tests, TestMethod10) {
    std::pair<std::vector<std::string>, std::vector<int>> data =
    { {"Американо", "Эспрессо", "Капучино", "Латте"}, {80, 100, 115, 130} };
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
    EXPECT_EQ(automata.GetState(), WAIT);
}
