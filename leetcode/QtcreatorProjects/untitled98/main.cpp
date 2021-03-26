//733. Flood Fill
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        vector<vector<int>> copy;
        for(const auto& row:image){
            vector<int> v;
            for(const auto& col:row){
                v.push_back(col);
            }
            copy.push_back(v);
        }
        helper(image,sr,sc,newColor,image[sr][sc], copy);
        return image;
    }
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor, vector<vector<int>>& copy ) {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || copy[sr][sc]==-1)
            return;
        int row=sr;
        int col=sc;
        if(image[row][col]==originalColor){
            image[row][col]=newColor;
            copy[row][col]=-1; //visited

            helper(image,row-1,col,newColor,originalColor,copy);
            helper(image,row+1,col,newColor,originalColor,copy);
            helper(image,row,col+1,newColor,originalColor,copy);
            helper(image,row,col-1,newColor,originalColor,copy);
        }
    }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
