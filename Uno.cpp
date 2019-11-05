//
// Created by 73696 on 2019/11/2.
//
#include "Uno.h"
#include <fstream>
#include <iterator>
std::vector<std::string> read(char* file_path){
    std::ifstream in_file(file_path);
    //std::istream_iterator<std::string> is(in_file);
    //std::istream_iterator<std::string>eof;
    std::vector<std::string> text ;
    std::string str;
    //copy(is, eof, back_inserter(text));
    if(in_file.is_open()) {
        while (getline(in_file, str)) {
            if (str.size() > 0)text.push_back(str);
        }
    }
    return text;
}
void Uno::Deck::insert(Uno::Card card) {
    deck_vec.push_back(card);
}

Uno::Card string_to_card(std::string card_info){
    std::string col;
    int val;

    for(char c : card_info){
        if(c==' ')break;
        else col+=c;
    }
    val=card_info.at(card_info.size()-1)-'0';
    Uno::Card ret(col,val);
    return ret;
}
Uno::Deck deck_generator(char* file_path){
    std::vector<Uno::Card> card_vec;
    Uno::Card card_1("Red",0);
    std::vector<std::string> vec_read = read(file_path);
    for(auto itr = vec_read.begin();itr!=vec_read.end();itr++){
        for(int i = 0;i< itr->at(0)-'0';i++){
            card_1=string_to_card(itr->substr(2));
            card_vec.push_back(card_1);
        }
    }
    Uno::Deck ret(card_vec);
    return ret;
}
void Uno::Rule:: set_rules(char* file_path){
    std::vector<std::string> rules_vec=read(file_path);
    StartingHandSize=*(rules_vec.at(0).end()-1)-'0';
    UnoCalloutPenalty=*(rules_vec.at(1).end()-1)-'0';
    BadUnoCalloutPenalty=*(rules_vec.at(2).end()-1)-'0';
    DrawLimit=*(rules_vec.at(3).end()-1)-'0';
    MustPlayCardEachTurn = (rules_vec.at(4).at(23) == 't');
    Reneging = (rules_vec.at(5).at(11) == 'A');

}