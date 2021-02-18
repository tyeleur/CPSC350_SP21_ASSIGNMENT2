#include <iostream>
#include "Translator.h"
#include <fstream>

using namespace std;

//Header for FileProcessor class, define constructor, destructor, and necessary method
class FileProcessor {
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string input, string output, string tranTo);
};
