#include "./stop.h" // inkluderer ord som skal ignoreres.

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <cstring>
#include <stdlib.h>

using namespace std;

/*
 * Legger inn ulovlige chars i set stopChars.
 */
void init_stopChars(set<char>& list) {
  int i = 0;
  char c;
  while((c = (int) *(stopchars_c+i++)) != '\0')
    list.insert(c);
}

/*
 * Legger inn ulovlige ord i set stopWords
 */
void init_stopWords(set<string>& list) {
  int i = 0;
  char c = *(stopwords_c+i++);
  while(c != '\0') {
    string s;
    while(c != ',') {
      s += c; // bygger opp ord
      c = (char) *(stopwords_c+i++);
    }
    list.insert(s); // setter inn ord når delimiter "," er funnet.
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
  string trimmed;
  int i = 0;
  char c = *ptr;
  set<char>::iterator it;
  while(c != '\0') {
    bool validchar = true; // lar oppgit tegn skrives til stringen.
    for(it = invalid.begin();it != invalid.end();++it) { // iterer over ulovlige bokstaver
      if(c == *it) {
	validchar = false; // ignorer bokstaven
	break; // går ur løkke
      }
    }
    if(validchar) { // hvis bokstaven er lovlig, legg den til i ordet.
      c = tolower(c); // setter lower case.
      trimmed += c;
    }
    c = *(ptr+(++i));
  }
  return trimmed;
}

/*
 * Retuner utfallet om gitt ord finnes i listen av stopp-ord.
 */
bool is_stopWord(string word, set<string>& invalid) {
  for(set<string>::iterator it = invalid.begin(); it != invalid.end(); ++it) {
    string cmp = *it;
    if(strcmp(word.c_str(),cmp.c_str()) == 0) // if(word == cmp) funker ikke??
      return true;
  }
  return false;
}

/*
 * Sorterer ord etter count (descending) i multimap, og skriver ut de n første orden med dess count
 */
void print_nHighestCount(map<string,int>& words, int n) {
  multimap<int, string, greater<int> > sortByCount; // oppretter multimap som bruker compartorn std::greater
  map<string, int>::const_iterator wIter;
  char delimiter = ':';

  for (wIter = words.begin(); wIter != words.end(); wIter++)
    sortByCount.insert(pair<int, string>(wIter->second, wIter->first)); // snur verdiene og setter inn count som index, med størst først

  multimap<int, string>::const_iterator cIter;
  for (cIter = sortByCount.begin(); cIter != sortByCount.end() && n > 0; cIter++) {
    cout << cIter->second << delimiter << cIter->first << endl; // skriver ut ordet etterfølgt av : og sist count
    n--; // teller ned antall element som er igjen for utskrift.
  }
} 

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cout << "Missing argument; wordcloud <n top results>" << endl;
    exit(0);
  }
  
  // oppretter liste for ulovlige tegn
  set<char> stopChars;
  init_stopChars(stopChars);
  
  // oppretter liste for ulovlige ord
  set<string> stopWords;
  init_stopWords(stopWords);
  
  string word;
  map<string, int> words;
  
  while(cin >> word) { // leser av ord for ord 
    word = trimWord(word, stopChars); // trimmer ordet på ulovlige tegn og setter alle bokstaver til lower case.
    if(!is_stopWord(word, stopWords)) { // hvis ordet ikke er ulovlig
      words[word]++; // inkrementerer counten på oppgitt ord i mapen.
    }
  }

  int n = atoi(argv[1]); // antall ord som skal vises.
  print_nHighestCount(words, n); // skriver ut n antall ord med størst count.
  exit(0);
}
