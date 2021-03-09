//Remove Palindromic Subsequences
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool is_palindrom(string s)
    {
        for(int i=0,j=s.size()-1; i<j;++i,--j){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    int normal_stragety(string s)
    {
        if(s.size()==0)
            return 0;
        if(is_palindrom(s))
            return 1;
        return 2;
    }

    int count_stragety(string s){
        if(count(s.begin(),s.end(),'a')==count(s.begin(),s.end(),'b'))
            return 1;
        return 2;
    }
    int front_back_stragety(string s) {
        int step=0;

        while(!s.empty()){
            vector<int> remove_index_from_front;
            for(int i=0,j=s.size()-1;i<=j;){
                if(s[i]==s[j]){
                    remove_index_from_front.push_back(i);
                    if(i!=j) {
                        remove_index_from_front.push_back(j);
                    }
                    ++i;
                    --j;
                } else {
                    --j;
                }
            }
            vector<int> remove_index_from_back;
            for(int i=0,j=s.size()-1;i<=j;){
                if(s[i]==s[j]){
                    remove_index_from_back.push_back(i);
                    if(i!=j) {
                        remove_index_from_back.push_back(j);
                    }
                    ++i;
                    --j;
                } else {
                    ++i; //how to refactor this?
                }
            }

            vector<int> remove_index;
            if (remove_index_from_front.size()> remove_index_from_back.size())
                remove_index= remove_index_from_front;
            else
                remove_index = remove_index_from_back;

            if(s.size()==remove_index.size()){
                s="";
                ++step;
                continue;
            } else {
                sort(remove_index.begin(), remove_index.end());
                for(const auto& index: remove_index){
                    s[index]='*';
                }
                auto last = remove(s.begin(), s.end(), '*');
                s.erase(last, s.end());
                ++step;
            }
        }

        return step;
    }

    int removePalindromeSub(string s) {
        int count = count_stragety(s);
        int front_back = front_back_stragety(s);
        int normal = normal_stragety(s);
        return normal;
    }
};


int main()
{
    Solution s;
    //s.removePalindromeSub("ababbbaaba");
    s.removePalindromeSub("abbaaaab"); //front back does not return the min step..
    //s.removePalindromeSub("baaba");
    //s.removePalindromeSub("ababa");
    return 0;
}
