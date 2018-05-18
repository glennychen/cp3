// UVA 100 - The 3n + 1 problem                                                                                                                                                                                                              
#include <iostream>
#include <vector>

using namespace std;

int three_n_plus_1(int n)
{
    int input = n;
    int count = 1;

    while(n!=1) {
        ++count;
        if(n%2==1) {
            n = 3*n+1;
        } else {
            n = n/2;
        }
    }
    // cout << input; //DEBUG
    //cout << " count: " << count << endl; //DEBUG
    return count;
}

int main() {
    for(;;){
        int i, j, max_cycle;
        cin >> i;
        if (cin.fail()) break;
        cin >> j;
        cout << i << " " << j;
        int tmp;
        if (j<i) {
            tmp = i;
            i=j;
            j = tmp;
        }

        max_cycle = 0;
        for(int k=i; k<=j; ++k){
            int cycle = three_n_plus_1(k);
            if (cycle>max_cycle) {
                max_cycle = cycle;
            }
        }
        cout << " " << max_cycle << endl;

    }
    return 0;
}

