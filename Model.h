#include <iostream>
#include <string>

using namespace std;

//Header for Model class, define constructor, destructor, and necessary methods
class Model {
  public:
    Model();
    ~Model();
    string translateSingleCharacter(char c);
    string translateDoubleCharacter(char c);
    char nonVowelTut(string s);
};
