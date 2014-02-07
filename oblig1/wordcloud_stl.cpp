#include "./stop.h" // inkluderer ord som skal ignoreres.

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <cstring>

using namespace std;

void init_stopChars(set<char>& list) {
  int i = 0;
  char c;
  while((c = (int) *(stopchars_c+i++)) != '\0') {
    list.insert(c);
    cout << c << "\t" << (int) c << endl;
  }
}

void init_stopWords(set<string>& list) {
  int i = 0;
  char c = *(stopwords_c+i++);
  while(c != '\0') {
    stringstream ss;
    while(c != ',') {
      ss << c;
      c = (char) *(stopwords_c+i++);
    }
    list.insert(ss.str());
    c = *(stopwords_c+i++);
  }   
}
/*
 * Tar emot ord og liste, stripper den på ulovlige bokstaver,
 * og setter alle bokstaver til lower case.
 * Retunerer trimmet ord (string)
 */
string trimWord(string word, set<char>& invalid) {
  const char* ptr = word.c_str();
  stringstream ss;
  int i = 0;
  char c = *ptr; // ingorer første ord uten denne?
  set<char>::iterator it;
  while(c != '\0') {
    c = *(ptr+i++);
    bool validchar = true;
    for(it = invalid.begin();it != invalid.end();++it) {
      if(c == *it) {
	validchar = false;
	break;
      }
    }
    c = tolower(c); // setter lower case.
    if(validchar)
      ss << c;
  }
  string output = ss.str();
  return output;
}
void makeLowerCase() {}
bool is_stopWord(string word, set<string>& invalid) {
  for(set<string>::iterator it = invalid.begin(); it != invalid.end(); ++it) {
    string cmp = *it;
    if(strcmp(word.c_str(),cmp.c_str()) == 0) // if(word == cmp) funker ikke??
      return true;
  }
  return false;
}
void process_Word() { }
 
int main(int argc, char* argv[]) {
  set<char> stopChars;
  init_stopChars(stopChars);
  
  // test for å se om lista er riktig
  set<char>::iterator it;
  for(it = stopChars.begin(); it != stopChars.end(); ++it)
    if('\'' == *it) cout << *it << " OK!";

  set<string> stopWords;
  init_stopWords(stopWords);

  // test
  set<string>::iterator sit;
  for(sit = stopWords.begin(); sit!= stopWords.end(); ++sit)
    cout << *sit << " ";
  string word;
  int i = (argc > 1) ? std::atoi(argv[1]) : 20;
  std::cout << i << std::endl;
  
 // hente ut ord
  for(;i > 0; i--) {
    std::cin >> word;
    word = trimWord(word, stopChars);
    if(!is_stopWord(word, stopWords))
      std::cout << word << std::endl;
  }

  // strippe ord.

  // gjør til lowercase

  // sjekk om det finnes i stoplista.
  // if (false); legg inn i map (??)
}
