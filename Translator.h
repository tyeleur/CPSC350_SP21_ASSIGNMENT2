#include <iostream>
#include <string>
#include "Model.h"

using namespace std;

//Header for Translator class, define constructor, destructor, and necessary methods
class Translator {
  public:
    Translator();
    ~Translator();
    string translateEnglishWord(string s);
    string translateEnglishSentence(string s);
    string translateTutWord(string s);
    string translateTutSentence(string s);
};
