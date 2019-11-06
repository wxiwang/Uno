//
// Created by Maggie Huang on 11/6/19.
//

#include "InputValidation.h"
int getPositiveInt(const std::string &prompt) {
  int val;
  do {
    val = getValidInt(prompt);
  } while (val < 2);
  return val;
}

int getValidInt(const std::string &prompt) {
  std::string lineRead;
  int val;
  bool readSuccessful = false;
  do {
    std::cout << prompt;
    std::getline(std::cin, lineRead); // grab the line
    std::stringstream lineParser(lineRead); //put it into a string stream so we can parse it
    lineParser >> val; //read what we want
    readSuccessful = StreamOnlyContainsWhiteSpace(lineParser); //check that there isn't anything left
  } while (!readSuccessful); //keep asking until they give me what I want
  return val;
}
std::string getValidString(int playerNum) {
  std::string validString;
  std::string lineRead;
  bool readSuccessful = false;
  do {
    std::cout << "Player " << playerNum << " enter your name: ";
    std::getline(std::cin, lineRead);
    std::stringstream lineParser(lineRead);
    lineParser >> validString;
    readSuccessful = StreamOnlyContainsWhiteSpace(lineParser) && SingleWord(validString);

  } while (!readSuccessful);
  return validString;
}
bool StreamOnlyContainsWhiteSpace(std::istream &stream) {
  char c = '!';
  if (!stream) { //if you can't read from the stream
    return false; //something is wrong with the stream
  } else {
    stream >> c; // attempt to read a nonwhitespace character
    //if the stream is bad it means we failed to read
    //and we should since there shouldn't be anything left
    return !stream;
  }
}

bool SingleWord(const std::string& word) {
  bool singleWord = true;
  char check;
  int i = 0;
  while (word[i]) {
    check = word[i];
    if (isspace(check)) {return !singleWord;}
    ++i;
  }
  return singleWord;
}
std::string toLowerString(std::string name) {
  std::string lowerCaseName;
  int size = name.size();
  for (int i = 0; i < size; ++i) {
    lowerCaseName[i] = std::tolower(name.at(i));
  }
  std::cout << lowerCaseName;
  return lowerCaseName;
}
