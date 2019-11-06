//
// Created by 73696 on 2019/11/2.
//
#include <string>
#include <utility>
#include <vector>
#ifndef UNO_UNO_H
#define UNO_UNO_H
namespace Uno{
    class Card;
    class Move;
    class Player;
    class Deck;
    class Rule;
    class UnoGame;
}
class Uno::Card{
public:
    Card(std:: string  color,int val):color(std::move(color)),val(val){}
    void display();
private:
    std::string color;
    int val;
};
class Uno::Deck{
    friend class Uno::Card;
    friend class Uno::UnoGame;
public:
    explicit Deck(std::vector<Uno::Card> vec):deck_vec(std::move(vec)){}
    Deck()= default;
    void insert(Uno::Card);
private:
    std::vector<Uno::Card> deck_vec;

};
class Uno::Player{
    friend class Uno::UnoGame;
public:
    explicit Player(std::string name):name(std::move(name)),hand_card(){}
private:
    std::string name;
    std::vector<Uno::Card> hand_card;
};
class Uno::Rule{
public:
    Rule()=default;
    Rule(char* file_path){set_rules(file_path);}
    int StartingHandSize;
    int UnoCalloutPenalty;
    int BadUnoCalloutPenalty;
    int DrawLimit;
    bool MustPlayCardEachTurn;
    bool Reneging;//true stands for Any and false stands for LastDrawn
    void set_rules(char* file_path);
};
std::vector<std::string> read(char* file_path);
Uno::Card string_to_card(std::string card_info);
Uno::Deck deck_generator(char* file_path);
#endif //UNO_UNO_H
