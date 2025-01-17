//
// Created by 73696 on 2019/11/3.
//
#include "Uno.h"
#include "UnoGame.h"
#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>
#include "InputValidation.h"
Uno::UnoGame::UnoGame(int argc, char **argv)
    : rule(argv[2]), deck(deck_generator(argv[1])), discard_pile(), NumberofPlayers(2), seed(0) {
  if (argc == 4)seed = std::stoi(argv[3]);
  else seed = std::chrono::system_clock::now().time_since_epoch().count();
  getCurrentPlayer();
}

void Uno::UnoGame::getCurrentPlayer() {
//    std::cout << "Enter the number of players in the game: ";
//    std::cin >> NumberofPlayers;//may need input validation


  NumberofPlayers = getPositiveInt("Enter the number of players in the game: ");
  // getPositiveInt also checks if number of players is greater or equal to 2
  for (int i = 0; i < NumberofPlayers; i++) {
    std::string name = getValidString(i + 1);
    Player p1(name);
    players.push_back(p1);
    for (int j = 0; j < i; ++j) {    // check for unique names
      if (players.at(j).name == name) {  // right now it does not validate dog VS DOG, but checks for the same name
        --i;
        break;
      }
    }
  }
}

void Uno::UnoGame::deal() {
  for (int j = 0; j < rule.StartingHandSize; j++) {
    for (int i = 0; i < NumberofPlayers; i++) {
      if (deck.deck_vec.size() >= 2) {
        players.at(i).hand_card.push_back(*(deck.deck_vec.end() - 1));
        deck.deck_vec.pop_back();
      }
    }
  }

}
void Uno::UnoGame::play() {
  std::minstd_rand generator(seed);//random number generator
  std::shuffle(deck.deck_vec.begin(), deck.deck_vec.end(), generator);//洗牌
  deal();//发牌

}
