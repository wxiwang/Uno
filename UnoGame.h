//
// Created by 73696 on 2019/11/3.
//

#ifndef UNO_UNOGAME_H
#define UNO_UNOGAME_H

#include "Uno.h"
#include <vector>
class Uno::UnoGame{
    friend class Uno::Deck;
public:
    UnoGame(int argc,char**argv);
    ~UnoGame()=default;
    void play();
    int NumberofPlayers;
    void deal();//发牌
private:
    std::vector<Uno::Player> players;//members in UnoGame are all in lower case
    Deck deck;
    Deck discard_pile;
    Rule rule;
    double seed;
    Uno::Move getCurrentPlayersMove() const;
    bool isGameOver() const;
    void getCurrentPlayer() ;

};
#endif //UNO_UNOGAME_H
