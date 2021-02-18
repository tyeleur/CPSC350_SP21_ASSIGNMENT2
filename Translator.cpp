#include "Translator.h"

using namespace std;

//default constructor
Translator::Translator(){}

//default destructor
Translator::~Translator(){}

//public method, calls Model class to translate word character by character
string Translator::translateEnglishWord(string s){

  //create instance of model
  Model* mod = new Model();
  string ret = "";

  //itterate through input word letter by letter
  for(int i=0;i<s.size();++i){
    if(tolower(s[i])==tolower(s[i+1])){
      ret+= mod ->translateDoubleCharacter(s[i]);
    }else{
      ret+= mod ->translateSingleCharacter(s[i]);
    }
  }

  //destruct model instance
  mod->~Model();

  //return translated word
  return ret;
}

//public method, break sentence into words and translate separately. Stitch words back together to return full sentence
string Translator::translateEnglishSentence(string s){
  string ret = "";
  string placeholder= "";

  //itterate through letters to separate words and append string ret for translated sentence
  for (int i = 0;i<s.size();++i){
    if(int(s[i])>=65&&int(s[i])<=90){
      placeholder += s[i];
    }else if(int(s[i])>=97&&int(s[i])<=122){
      placeholder += s[i];
    }else{
      ret += translateEnglishWord(placeholder);
      ret += s[i];
      placeholder = "";
    }
  }

  //Catch any word left behind in string placeholder
  ret += translateEnglishWord(placeholder);

  //return translated sentence
  return ret;
}
//method to translate Tutnese words to english
string Translator::translateTutWord(string s){

  string ret = "";
  string placeholder = "";

  //create instance of model
  Model* mod = new Model();

  for(int i = 0; i<s.size(); ++i){

    placeholder += s[i];

    if(placeholder=="A"||placeholder=="I"||placeholder=="O"||placeholder=="U"||placeholder=="a"||placeholder=="i"||placeholder=="o"||placeholder=="u"){
      ret += s[i];
      placeholder = "";
    }

    //Letter E and X are intertwined in translation
    else if(placeholder=="E"){
      if(s[i+1]=='x'){
        ret+='X';
        i++;
        placeholder = "";
      }else{
        ret += s[i];
        placeholder = "";
      }
    }else if(placeholder=="e"){
      if(s[i+1]=='x'){
        ret+='x';
        i++;
        placeholder = "";
      }else{
        ret += s[i];
        placeholder = "";
      }
    }

    // Handle double characters for both capital and lowercase
    if(placeholder=="squa"){
      if(s[i+1]=='t'){
        if(s[i+2]=='u'&&s[i+3]=='t'){
          ret += "tt";
          i+=3;
        }else{
          ret += (s[i+2]);
          ret += s[i+2];
          i+=2;
        }
      }else if(s[i+1]=='e'){
        ret+="xx";
        i+=2;
      }else{
        ret+=s[i+1];
        ret+=s[i+1];
        if(s[i+1]=='c'||s[i+1]=='h'||s[i+1]=='k'||s[i+1]=='w'){
          i+=4;
        }else if(s[i+1]=='q'){
          i+=5;
        }else{
          i+=3;
        }
      }
      placeholder = "";
    }else if(placeholder=="Squa"){
      if(s[i+1]=='t'){
        if(s[i+2]=='u'&&s[i+3]=='t'){
          ret += "Tt";
          i+=3;
        }else{
          ret += toupper(s[i+2]);
          ret += s[i+2];
          i+=2;
        }
      }else if(s[i+1]=='e'){
        ret+="Xx";
        i+=2;
      }else{
        ret+=toupper(s[i+1]);
        ret+=s[i+1];
        if(s[i+1]=='c'||s[i+1]=='h'||s[i+1]=='k'||s[i+1]=='w'){
          i+=4;
        }else if(s[i+1]=='q'){
          i+=5;
        }else{
          i+=3;
        }
      }
      placeholder = "";
    }else{
      //All characters that are doubled/vowles are accounted for, rest go to Model class in method nonVowelTut
      char ch = mod -> nonVowelTut(placeholder);
      //If an a is returned, there is further necessary characters to translate
      if(!(ch=='a')){
        ret+=ch;
        placeholder = "";
      }
    }
  }
  if(!(placeholder=="")){
    cout << "Ran into problem while translating:  " << placeholder << endl;
  }

  return ret;
}

//Method to cut up Tutnese sentence and translate words individually
string Translator::translateTutSentence(string s){
  string ret = "";
  string placeholder= "";

  //itterate through letters to separate words and append string ret for translated sentence
  for (int i = 0;i<s.size();++i){
    if(int(s[i])>=65&&int(s[i])<=90){
      placeholder += s[i];
    }else if(int(s[i])>=97&&int(s[i])<=122){
      placeholder += s[i];
    }else{
      ret += translateTutWord(placeholder);
      ret += s[i];
      placeholder = "";
    }
  }

  //Catch any word left behind in string placeholder
  ret += translateTutWord(placeholder);

  //return translated sentence
  return ret;
}
