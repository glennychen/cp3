#include <iostream>

using namespace std;

int main()
{
  //https://stackoverflow.com/questions/25538672/post-increment-in-while-loop-in-c
  int n = 11;
  //while (--n) { // bug, missing 10
  //while (n--) { // bug, missing 10
  while (--n){
    cout << n << endl;
  }

  return 0;
}
