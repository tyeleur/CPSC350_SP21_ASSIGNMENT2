#include <iostream>
#include "FileProcessor.h"

using namespace std;

/*main method, takes two command line arguments as file names.
Argument 1 is file name to translate from
Argument 2 is file name of which to write translation to*/
int main(int argc,char** argv){

  //create instance of FileProcessor to handle opening of files, and writing of translation
  FileProcessor* fp = new FileProcessor();
  fp->processFile(argv[1],argv[2],argv[3]);

  //Garbage control, delete instance of FileProcessor
  delete fp;


  //Exit
  return 0;
}
