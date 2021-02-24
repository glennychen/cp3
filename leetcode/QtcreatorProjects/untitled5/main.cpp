//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
#include <iostream>
#include <vector>

using namespace std;

//Binary search optimiazation
int countNegatives(vector<vector<int>>& grid) {
    int count=0;
    for(const auto& v: grid) {
        for(size_t i=0; i<v.size();++i) {
            //since v is already sorted (in non-increasing order),
            //we can shortcut the loop
            if (v[i]<0) {
                count+=v.size()-i;
                break;
            }
        }
    }
    return count;
}

int binarysearch(vector<int> v, int target){
    int low=0;
    int high = v.size()-1;
    //while (low<high){ //BUG: low and high is the same for single element
    while (low<=high){
        //int mid=(high-low)/2; //BUG: we want to calculate the average index in between, so +, but not range, which is -
        int mid=(high+low)/2;
        int guess = v[mid];
        if (guess==target)
            return mid;
        if (guess>target){
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return -1;
}

int SLOWERbinarysearch(vector<int> v, int target){
    int mid = v.size()/2;
    if (v[mid]==target) return mid;
    if (mid==0) return -1;

    vector<int> nv;
    if (v[mid]>target) {
        copy(v.begin(), v.begin()+mid, back_inserter(nv));
        return binarysearch(nv, target);
    }
    else {
        //copy(v.begin()+mid, v.end(), back_inserter(nv)); wut
        copy(v.begin()+mid+1, v.end(), back_inserter(nv));
        return binarysearch(nv, target);
    }

    // 3 2 1 -1
    // search -1
    //
}

int NxM_complexitycountNegatives(vector<vector<int>>& grid) {
    int count=0;
    for(const auto& v: grid) {
        for(size_t i=0; i<v.size();++i) {
            //since v is already sorted (in non-increasing order),
            //we can shortcut the loop
            if (v[i]<0) {
                count+=v.size()-i;
                break;
            }
        }
    }
    return count;
}


int main()
{
    vector<int>v {1,2,3};
    binarysearch(v,3);
    return 0;
}
