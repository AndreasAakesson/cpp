#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
typedef unsigned long long ulong;

ulong string_to_ulong(string s) {
  const char * ptr = s.c_str();
  ulong ul;
  stringstream ss;
  for(int i = 0; i < sizeof(ulong); i++) { // går igjennom 8 bokstaver.
    char c = *(ptr+i);
    int rest;
    cout << c << " - " << (int) c << endl;
    for(int y = sizeof(ulong); y > 0; y--) { // finner ut binær tall representert i 1 byte
      rest = (int)c % 2;
      c = c / 2;
      ss << rest; // lagrer binærtall til string 
    }
    ss << "\t";
   
  }
  cout << ss.str() << endl;
  ul = stoull(ss.str(),NULL,2);
  return ul;
}

string ulong_tostring(ulong nr) {
  int bits = 64;
  char bcode[bits];
  int i = 0;
  bcode[i++] = '0';
  while(nr > 0) {
    bcode[i++] = (nr%2 == 0) ? '0' : '1';
    nr=nr/2;
    cout << bcode[i-1];
  }
  
  int bytes = 8;
  char output[bytes];
  i = 0;
  int c = 0, potens = 8-1;
  while(i < 8) {
    if(bcode[i++] == '1') c += 2^potens--;
  }
  output[0] = c;
  cout << output[0] << endl;
  string s;
  return s;
}

int main(int argc, char* argv[]) {
  string text = "I love C++";
  cout << text << endl;
  ulong ul = string_to_ulong(text);
  cout << ul << endl;
  string s = ulong_tostring(ul);
  cout << s << endl;


}
