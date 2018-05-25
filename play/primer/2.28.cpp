#include <iostream>

using namespace std;

int main()
{
  //int i, *const cp;  //error: uninitialized const ‘cp’
  //int *p1, *const p2; //error: uninitialized const ‘p2’
  //const int ic, &r=ic; // error: uninitialized const ‘ic’
  //const int *const p3; //error: uninitialized const ‘p3’
  const int *p;
}
