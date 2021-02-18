#include "Model.h"

using namespace std;

//default constructor
Model::Model(){}

//default destructor
Model::~Model(){}

//public method, sets language translation rules per single character
string Model::translateSingleCharacter(char c) {

  switch(c) {
    //Vowels
    case 'A' :
      return "A";
      break;

    case 'E' :
      return "E";
      break;

    case 'I' :
      return "I";
      break;

    case 'O' :
      return "O";
      break;

    case 'U' :
      return "U";
      break;

    case 'a' :
      return "a";
      break;

    case 'e' :
      return "e";
      break;

    case 'i' :
      return "i";
      break;

    case 'o' :
      return "o";
      break;

    case 'u' :
      return "u";
      break;

    //Capital consonants
    case 'B' :
      return "Bub";
      break;

    case 'C' :
      return "Cash";
      break;

    case 'D' :
      return "Dud";
      break;

    case 'F' :
      return "Fuf";
      break;

    case 'G' :
      return "Gug";
      break;

    case 'H' :
      return "Hash";
      break;

    case 'J' :
      return "Jay";
      break;

    case 'K' :
      return "Kuck";
      break;

    case 'L' :
      return "Lul";
      break;

    case 'M' :
      return "Mum";
      break;

    case 'N' :
      return "Nun";
      break;

    case 'P' :
      return "Pub";
      break;

    case 'Q' :
      return "Quack";
      break;

    case 'R' :
      return "Rug";
      break;

    case 'S' :
      return "Sus";
      break;

    case 'T' :
      return "Tut";

    case 'V' :
      return "Vuv";
      break;

    case 'W' :
      return "Wack";
      break;

    case 'X' :
      return "Ex";
      break;

    case 'Y' :
      return "Yub";
      break;

    case 'Z' :
      return "Zub";
      break;

    //Lowercase consonants
    case 'b' :
      return "bub";
      break;

    case 'c' :
      return "cash";
      break;

    case 'd' :
      return "dud";
      break;

    case 'f' :
      return "fuf";
      break;

    case 'g' :
      return "gug";
      break;

    case 'h' :
      return "hash";
      break;

    case 'j' :
      return "jay";
      break;

    case 'k' :
      return "kuck";
      break;

    case 'l' :
      return "lul";
      break;

    case 'm' :
      return "mum";
      break;

    case 'n' :
      return "nun";
      break;

    case 'p' :
      return "pub";
      break;

    case 'q' :
      return "quack";
      break;

    case 'r' :
      return "rug";
      break;

    case 's' :
      return "sus";
      break;

    case 't' :
      return "tut";
      break;

    case 'v' :
      return "vuv";
      break;

    case 'w' :
      return "wack";
      break;

    case 'x' :
      return "ex";
      break;

    case 'y' :
      return "yub";
      break;

    case 'z' :
      return "zub";
      break;
  }
  return "";
}

//public method, sets language translation rules per double character
string Model::translateDoubleCharacter(char c) {
  //Determine if translating a double vowel or consonant
  //Also check whether capital or lowercase
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
    return "squat";
  }else if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
    return "Squat";
  }else if(int(c)>=65&&int(c)<=90){
    return "Squa";
  }else{
    return "squa";
  }
}
//public method; handles non-vowel translation from Tutnese to English
char Model::nonVowelTut(string s){
  if(s=="Bub"){
    return 'B';
  }else if(s=="Cash"){
    return 'C';
  }else if(s=="Dud"){
    return 'D';
  }else if(s=="Fuf"){
    return 'F';
  }else if(s=="Gug"){
    return 'G';
  }else if(s=="Hash"){
    return 'H';
  }else if(s=="Jay"){
    return 'J';
  }else if(s=="Kuck"){
    return 'K';
  }else if(s=="Lul"){
    return 'L';
  }else if(s=="Mum"){
    return 'M';
  }else if(s=="Nun"){
    return 'N';
  }else if(s=="Pub"){
    return 'P';
  }else if(s=="Quack"){
    return 'Q';
  }else if(s=="Rug"){
    return 'R';
  }else if(s=="Sus"){
    return 'S';
  }else if(s=="Tut"){
    return 'T';
  }else if(s=="Vuv"){
    return 'V';
  }else if(s=="Wack"){
    return 'W';
  }else if(s=="Yub"){
    return 'Y';
  }else if(s=="Zub"){
    return 'Z';
  }else if(s=="bub"){
    return 'b';
  }else if(s=="cash"){
    return 'c';
  }else if(s=="dud"){
    return 'd';
  }else if(s=="fuf"){
    return 'f';
  }else if(s=="gug"){
    return 'g';
  }else if(s=="hash"){
    return 'h';
  }else if(s=="jay"){
    return 'j';
  }else if(s=="kuck"){
    return 'k';
  }else if(s=="lul"){
    return 'l';
  }else if(s=="mum"){
    return 'm';
  }else if(s=="nun"){
    return 'n';
  }else if(s=="pub"){
    return 'p';
  }else if(s=="quack"){
    return 'q';
  }else if(s=="rug"){
    return 'r';
  }else if(s=="sus"){
    return 's';
  }else if(s=="tut"){
    return 't';
  }else if(s=="vuv"){
    return 'v';
  }else if(s=="wack"){
    return 'w';
  }else if(s=="yub"){
    return 'y';
  }else if(s=="zub"){
    return 'z';
  }
  //returning 'a' results in no translation and continuation of for loop in translator.
  return 'a';

}
