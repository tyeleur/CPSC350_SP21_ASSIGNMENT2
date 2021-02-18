#include "FileProcessor.h"

using namespace std;

//default constructor
FileProcessor::FileProcessor(){}

//default destructor
FileProcessor::~FileProcessor(){}

//public method, takes file named to read/write and calls necessary classes to translate one to another
void FileProcessor::processFile(string input, string output, string tranTo){

  //open file streams to read/write
  ifstream inFS;
  ofstream outFS;

  //Open files and check whether they successfully opened
  cout << "\nOpening files: " << input << ", " << output << endl;
  inFS.open(input);
  outFS.open(output);

  if (!inFS.is_open()){
    cout << "Error: could not open read file: " << input << endl;
    return;
  }if (!outFS.is_open()){
    cout << "Error: could not open write file: " << output << endl;
    return;
  }else{

  //Notify user that the program is running properly
  cout << "Translating and writing to file: " << output << endl;

  /*Create instance of translator and use to translate file line by line
  ReadString place holder variable for current line being translated
  End while loop when no more lines in file */
  Translator* tranny = new Translator();
  string readString = "";
  while(1){
    getline(inFS, readString);
    if(inFS.eof()){
      break;
    }
    if(tranTo=="E2T"){
      outFS << tranny->translateEnglishSentence(readString) << endl;
    }else if(tranTo=="T2E"){
      outFS << tranny->translateTutSentence(readString) << endl;
    }else{
      cout << "Error: please specify what direction to translate (E2T/T2E)" << endl;
      break;
    }
  }
  //close instance of Translator, new line for easier to understand console
  tranny->~Translator();
  cout << endl;
  }

  //Close input/output filestreams
  outFS.close();
  inFS.close();

  //Exit
  return;
}
