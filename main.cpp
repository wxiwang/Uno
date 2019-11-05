#include <iostream>
#include "Uno.h"
#include "UnoGame.h"
int main(int argc,char** argv) {
    Uno::UnoGame game(argc,argv);
    game.play();
    return 0;
}