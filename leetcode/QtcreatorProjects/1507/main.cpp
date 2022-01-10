#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class SparseVector1 {
//public:
//    SparseVector(vector<int> &nums):v{nums} {
//     //not optimal for SPACE because we do not need to store everything on a sprace vector
//     //but it can be faster than hashing for large data set
//    }

//    // Return the dotProduct of two sparse vectors
//    int dotProduct(SparseVector& vec) {
//        int sum=0;
//        for(int i=0;i<vec.size();++i){
//            sum+=vec[i]*v[i];
//        }
//        return sum;
//    }
//    vector<int> v;
//};

//class SparseVector2 {
//public:
//    //hash looks faster but can be slower on large dataset due to hashing
//    SparseVector(vector<int> &nums) {
//        for(int i=0;i<nums.size();++i){
//            if(nums[i]!=0){
//                um[i]=nums[i];
//            }
//        }
//    }

//    // Return the dotProduct of two sparse vectors
//    int dotProduct(SparseVector& vec) {
//        int sum=0;
//        for(const auto& [k,v]: um){
//            if(v!=0){
//                sum+=v*vec.um[k];
//            }
//        }
//        return sum;
//    }
//    vector<int> v;
//    unordered_map<int,int> um;
//};

class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                vp.push_back({i, nums[i]});
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum=0;
        int i=0;
        int j=0;
        while(i<vp.size() && j<vec.vp.size()){
            if(vp[i].first==vec.vp[j].first){
                sum+=vp[i].second*vec.vp[j].second;
                ++i;
                ++j;
            } else if (vp[i].first<vec.vp[j].first){
                ++i;
            } else {
                ++j;
            }
        }
        return sum;
    }
    vector<pair<int,int>> vp;
};


int main()
{
    vector<int> v1{1,0,0,2,3};
    vector<int> v2{0,3,0,4,0};
    v1={0,1,0,0,0};
    v2={0,0,0,0,2};
    SparseVector sv1(v1);
    SparseVector sv2(v2);
    cout <<sv1.dotProduct(sv2);
    return 0;
}
