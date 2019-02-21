#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  // 360 / 40 = 9
  // 2full turns, 360*2
  // stop at the first,

  //int const nine_degree = 360/40;
  int const UNIT = 1;
  int const ONE_TURN = 40;
  int start, a, b, c, total;

  for(;;) {
    cin >> start >> a >> b >> c;
    if (start==0 && a==0 && b == 0 && c==0) break;

    // Step 1, two full turn
    total = 0;
    total += 2* ONE_TURN; 
  
    if (a > start) {
      total += a - start;
    } else if (start == a)  {
    
    } else {
      total += ONE_TURN - (abs(a-start));
    }
  
    // Step 2, 1 full turn
    start = a;
    total += ONE_TURN;
    if (b > start) {
      total += b - start;
    } else if ( b == start) {
      // impossible, consecutive numbers are unique
    } else {
      total += ONE_TURN - (b-start);
    }

    // Step 3, clockwise until the  3rd number
    start = b;
    if (star > c) {
      total += start - c;
    } else if (c == start) {
      // impossible
    } else {
      total += c - start;
    }
      
  }  
}
