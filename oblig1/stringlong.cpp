#include <iostream>
#include <string>
#include <cstring>

using namespace std;
typedef unsigned long long ulong;

ulong string_to_ulong(string s) {
  ulong ul = (ulong)* s.c_str();
  return ul;
}

string ulong_tostring(ulong nr) {
  string* sp = (string*) &nr;
  return *sp;
}

int main(int argc, char* argv[]) {
  string text = "I love C++";
  cout << text << endl;
  ulong ul = string_to_ulong(text);
  cout << &ul << endl;
  string s = ulong_tostring(ul);
  cout << s << endl;


}
