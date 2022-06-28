#include <iostream>

using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version)
{
    return false;
}

class Solution {
public:
    int firstBadVersion_test(int n) {
        int target = 99;
        
        int end = n;
        int mid = end/2;

        if (n==target){
            return n;
        }

        while(mid!=target)
        {
            if(mid>target){
                end = mid;
                mid = mid/2;
            } else if (mid<target){
                mid = (mid+1+end)/2;
            }

        }
//1 2 3 4 5 6 7
//mid 7/2 3
//1 2 3 4 5 6
//mid 6/2 3
        return mid;
    }

    int firstBadVersion(int n) {      
        int end = n;
        int mid = end/2;


        while(true)
        {
            if(isBadVersion(mid)){
                if(mid>=1 && !isBadVersion(mid-1)){
                    return mid;
                }
                end = mid;
                mid = mid/2;
            } else {
                mid = (mid+1+end)/2; // this can overfloww if mid is int
            }

        }
        return mid;
    }

    
};


int main()
{
  cout << 1/2 << endl;

  Solution s;
  int a = s.firstBadVersion(100);
  cout << a << endl;
}