#include <iostream>

using namespace std;

int i = 100, sum=0;

int main()
{
  for(int i=0;i!=10;++i){
    sum += i;cout << i << ":" << sum << endl;
  }
  cout << i << " " << sum << endl;

  return 0;
}
