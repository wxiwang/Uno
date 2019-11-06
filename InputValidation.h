//
// Created by Maggie Huang on 11/6/19.
//

#ifndef UNO_INPUTVALIDATION_H
#define UNO_INPUTVALIDATION_H
#include <iostream>
#include <sstream>
#include <string>

int getPositiveInt(const std::string& prompt);
int getValidInt(const std::string& prompt);
std::string getValidString(int playerNum);
bool StreamOnlyContainsWhiteSpace(std::istream& stream);
bool SingleWord(const std::string& word);
std::string toLowerString(std::string name);
#endif //UNO_INPUTVALIDATION_H
