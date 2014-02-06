#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>

using namespace std;
typedef unsigned long long ulong;

ulong string_to_ulong(string s) {
  const char * ptr = s.c_str(); // gir adgang til char array
  stringstream ss;
  
  cout << "## string_to_ulong(); iteration av string: " << endl;
  for(int i = 0; i < sizeof(ulong); i++) { // iterer str så mange ggr det er plass til i ulong (8 bytes)
    char c = *(ptr+i);
    bitset<8> b(c); // ascii verdin til char lagres som binærkode på 1 byte
    ss << b.to_string(); // 8 bits føyes på stringen
    cout << c << "\t" << (int) c << "\t" << b.to_string() << endl;
  }
  cout << "# 64 bits: " << ss.str() << endl;  
  bitset<64> b(ss.str()); // stringen blir oversatt til binærkode
  ulong ul = b.to_ulong(); // binærkoden gjørs om til ulong
  cout << "# Returverdi i string_to_ulong(): " << ul << endl;
  return ul;
}

string ulong_tostring(ulong nr) {  
  bitset<64> b(nr); // ulong blir lagd til binærkode på 8 bytes
  stringstream ss;

  for(int i = 0; i < sizeof(ulong); i++) { // forskyver 8 bits fremover i de 64 bitene
    bitset<8> byte(b.to_string(), i*8, 8); // tar ut 8 bits fra koden.
    ss << (char)byte.to_ulong(); // binærkodens ulong castes til char og legges på stringen.
  }
  
  return ss.str();
}

int main(int argc, char* argv[]) {
  string text = "I love C++";
  cout << "## Input (main): \"" << text << "\"" << endl;
  string s = ulong_tostring(string_to_ulong(text));
  cout << "## Utskrift: \"" << s << "\"" << endl;
}
