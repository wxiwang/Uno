//
// Created by 73696 on 2019/11/3.
//

#ifndef UNO_MOVE_H
#define UNO_MOVE_H

#include "string"
namespace Uno{
    class Player;
    class Card;
    class UnoGame;
}
class Move{
    friend class Uno::UnoGame;
public:
    Move(std::string& cmd);
    bool isValid(const Uno::Card& discard_card);
};
#endif //UNO_MOVE_H
