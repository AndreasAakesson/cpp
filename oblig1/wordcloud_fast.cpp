/* Ikke så rask som navnet antyder... */

#include "./stop.h" // inkluderer ord som skal ignoreres.
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

/*
 * Enkellenket liste for structen node.
 */
class List
{
public:
  /* En node kjennetegnes av et unikt ord, og holder data på hvor mange ganger ordet har forekommet i en tekst. */
  struct node {
    string word;
    int count;
    struct node *next;
  } *head, *tail, *ptr;
  int length;

  List():head(NULL),tail(NULL){}
  ~List();

  struct List::node* initNode(string);
  struct List::node* findByWord(struct List::node*, string);
  void addNode(struct List::node*);
  void insertSort(struct List::node*);
  void deleteList(struct List::node*);
  void sortByCount(int);
  int size();
  bool empty();
  void displayNode(struct List::node*) const;
  void displayList(struct List::node*, int) const;
  void reallySlowSort();
};

List::~List() {
  node *current,*temp;
  current = head;
  temp = head;
  while(current != NULL) {
    current = current->next;
    delete temp;
    temp = current;
  }
  length = 0;
}

int List::size() {
  return length;
}

bool List::empty() {
  return (length == 0 && head == NULL);
}
/*
 * Oppretter ny node (wordcount) og retunerer referanse.
 */
struct List::node* List::initNode(string word) {
  struct node *ptr = new node;
  if( ptr == NULL )                         
    throw std::exception(); //return static_cast<struct node *>(NULL);  
  else {  
    ptr->word = word;
    ptr->count = 1;                        
    return ptr;                         
  }
}

/*
 * Starter søk fra og med ptr og finner referanse til sendt med ord.
 */
struct List::node* List::findByWord(struct node* ptr, string word) {
  if(ptr == NULL) return ptr;
  while(word != ptr->word) {    
    ptr = ptr->next;                          
    if(ptr == NULL)                          
      break;                                  
  }
  return ptr; 
}

/*
 * Plasserer node sist i listen.
 */
void List::addNode(struct node *newNode) {
  if(head == NULL) {
    head = newNode;  
    tail = newNode;
  }
  else {
    tail->next = newNode;       
    newNode->next = NULL;   
    tail = newNode;
  }
  length++;
}

/*
 * IKKE FERDIG/I BRUK
 */
void List::insertSort(struct node *node) {
  if(empty()) {
    head = node;
    tail = node;
    length++;
    return;
  }
  struct node *next, *current;
  current = head;
  while(current != NULL) {
    next = current;
  }
  length++;
}

/*
 * Skriver ut node til skjermen "ord:count"
 */
void List::displayNode(struct List::node *ptr) const {
  cout << ptr->word << ":" << ptr->count << endl;
}

/*
 * Iterer igjennom alle noder og skriver ut innholdet på de n første nodene.
 */
void List::displayList(struct List::node *ptr, int n) const {
  if(!ptr) cout << "Nothing to display" << endl;
  for( ;ptr && n > 0; n--) {
    displayNode(ptr);
    ptr = ptr->next;
  }
}

/*
 * Sletter element i lista fra og med oppgitt node.
 */ 
void List::deleteList(struct node *ptr) {
  if(empty()) return;   // finns inget å slette.      
  
  struct node *temp;
  if(ptr == head) { // hvis hele lista, nullstiller pekere.
    head = NULL;
    tail = NULL;
  }
  else { // hvis ikke, flytter tail (siste node) til elementet før oppgitt node.
    temp = head;
    while(temp->next != ptr)
      temp = temp->next;
    tail = temp;
  }

  while(ptr != NULL) { // itererer igjennom alle noder.
    temp = ptr->next; // tar vare på neste node som skal slettes.
    delete ptr;
    ptr = temp;
    length--;
  }
}

/*
 * Første versjon av sortering av nodene.
 * Ønsker å implementere egen comparator, men får det ikke til...
 */
void List::reallySlowSort() {
  if(length < 2) // gir ikke mening å sortere 1 element, eller tom liste.
    return; // tilfeldig løsning

  struct node * current, * temp;
  current = head;
  while(current->next != NULL) {
    if(current->count < (current->next)->count) { // hvis den til venstre er mindre enn den til høyre 
      temp = current->next; // lagre den større av de to verdiene.
      current->next = current->next->next; // fjerner den fra lista.
      
      if(temp->count > head->count) { // hvis temp er størst
	temp->next = head; // plasse først
	head = temp;
      }
      else {
	current = head; // starter lista på nytt for å finne hvor temp skal.
	while(temp->count <= (current->next)->count) // iterer til riktig plass
	  current = current->next;
	temp->next = current->next; // setter inn temp mellom de to nodene.
	current->next = temp;
      }
    }
    current = current->next;
  }
}

void List::sortByCount(int n) {}

/*
 * Tar emot ord og liste, stripper den på ulovlige bokstaver,
 * og setter alle bokstaver til lower case.
 * Retunerer trimmet ord (string)
 */
string trimWord(string word) {
  const char* ptr = word.c_str();
  int i = 0;
  char c = *ptr;
  string trimmed;
  while(c != '\0') {
    bool validchar = true; // lar oppgit tegn skrives til stringen.
    int y = 0;
    char x;
    while((x = (int) *(stopchars_c+y++)) != '\0') { // iterer over ulovlige bokstaver
      if(c == x) {
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
bool is_stopWord(string word) {
  int i = 0;
  char c = *(stopwords_c+i++);
  
  while(c != '\0') {
    string stop;
    while(c != ',') {
      stop += c;
      c = *(stopwords_c+i++);
    }
    
    if(word == stop)
      return true;
    c = *(stopwords_c+i++);
  }
  return false;
}

int main(int argc, char* argv[]) {
  string word;
  List wordCount;
  List::node* ptr;
  const int DEFAULT = 300;

  while(cin >> word) {
    word = trimWord(word); // trimmer ord
    if(!is_stopWord(word)) {
      ptr = wordCount.findByWord(wordCount.head, word); // leter etter ordet i listen.
      if(ptr != NULL) {
	ptr->count++; // inkrementerer hvis funnet.
      }
      else {
	ptr = wordCount.initNode(word); // oppretter og legger inn node bakerst hvis ikke funnet.
	wordCount.addNode(ptr);
      }
    }
  }
  int n = (argc > 1) ? atoi(argv[1]) : DEFAULT;
  wordCount.reallySlowSort(); // sorterer hele lista i synkende rekkefølge
  wordCount.displayList(wordCount.head, n); // skriver ut de n førsta linjene fra lista med start fra head.
  wordCount.deleteList(wordCount.head); // sletter alle element i lista.

  exit(0);
}
