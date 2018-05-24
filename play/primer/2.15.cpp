#include <iostream>

using namespace std;

int main()
{

  int ival = 1.01; // truncate 1
  //int &ival = 1.01 //error need an object to initialize an reference
  int &rval2 = ival;
  //int &rval3; // error, must initialize a reference
  cout << ival << endl;
  cout << rval2 << endl;

  return 0;
}
