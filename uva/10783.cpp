// UVA 10783 - Odd Sum
#include <iostream>
using namespace std;

int main() {
  int num;
  cin >> num;
  for(int i=0;i<num;++i){
    int a,b, total;
    total=0;
    cin >> a >> b;
    for(int j=a;j<=b;++j){
      if(j%2==1){ //not if(a%2==1)
	total += j;
      }
    }
    cout << "Case " << (i+1) << ": " << total << endl;
  }
  return 0;
}
