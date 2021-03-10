#define CATCH_CONFIG_MAIN
#include<catch2/catch_all.hpp>
#include<vector>
#include<string>
using namespace std;

//https://leetcode.com/problems/shortest-distance-to-a-character/
vector<int> shortestToChar(string s, char c) {
    vector<int> output;

    output.push_back(s.find(c));//first element always count from the left, not from the right
    for(int i=1;i<s.size()-1;++i){
        int pos=s.find(c,i); // "It is guaranteed that c occurs at least once in s" (from it's starting position)

        int rpos=s.rfind(c,i); // rfind mind not hit the target because it is not guarantee
        if(rpos==string::npos){
            output.push_back(abs(i-pos));
        }else{
            output.push_back(min(abs(i-pos), abs(i-rpos)));
        }
    }
    //output.push_back(s.rfind(c));//bug, because rfind returns index counting from the left
    int rlast=s.rfind(c);
    int rlast_distance=s.size()-1-rlast;
    output.push_back(rlast_distance);
    return output;
}

vector<int> O_of_n_shortestToChar(string S, char C) {
           int n = S.size(), pos = -n;
           vector<int> res(n, n);


           for (int i = 0; i < n; ++i) {
               if (S[i] == C)
                   pos = i;
               res[i] = i - pos; //think i is on the right (i.e. larger) of pos(pos is the target)
                                 //so i-pos is the distance.
                                 //for example, we found target before (=pos), now the later i position
                                 // is i-pos away from pos.
           }
           for (int i = pos - 1; i >= 0; --i) {
               if (S[i] == C)
                   pos = i;

                                //think i is on the left (i.e. smaller) of pos(pos is the target)
                                //so i-pos is the distance
                                //for example, we found target before (=pos), now later i position
                                // is pos-i away from pos
               res[i] = min(res[i], pos - i);
           }
           return res;
    }

TEST_CASE( "Integer to Roman") {
    vector<int> v{3,2,1,0,1,0,0,1,2,2,1,0};
    REQUIRE( shortestToChar("loveleetcode", 'e') == v  );

    vector<int> v2 = {3,2,1,0};
    REQUIRE( shortestToChar("aaab",'b') == v2 );

    vector<int> v3 = {4,3,2,1,0,1,2,3,4,5};
    REQUIRE( shortestToChar("xuzmnimdwf", 'n') == v3 );

    vector<int> v4{3,2,1,0,1,0,0,1,2,2,1,0};
    REQUIRE( O_of_n_shortestToChar("loveleetcode", 'e') == v4  );
}
