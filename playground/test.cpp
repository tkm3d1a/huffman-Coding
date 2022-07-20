#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){

  char a = 'A';
  bitset<8> test("10101010");
  bitset<64> test3("1");

  cout << "a: " << a << endl;
  cout << "test: " << test << endl;
  cout << "test3: " << test3 << endl;

  int aSize = sizeof(a);
  int testSize = sizeof(test);
  int test3Size = sizeof(test3);

  cout << "a size: " << aSize << endl;
  cout << "test size: " << testSize << endl;
  cout << "test3 size: " << test3Size << endl;

}