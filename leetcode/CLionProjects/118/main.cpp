class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> current;
        for(int i=0;i<numRows;++i) {
            if(i==0){
                current = {1};
                ans.push_back(current);
            } else if(i==1) {
                current = {1,1};
                ans.push_back(current);
            } else {
                vector<int> new_row;
                new_row.push_back(1);
                for(int j=0;j<current.size();++j) {
                    if(j==current.size()-1) { break; }
                    if(j+1<current.size()) { //-1 because we can skip the last, so one less to check, weakness, practcie how to check bound
                        new_row.push_back(current[j]+current[j+1]);
                    }
                }
                new_row.push_back(1);
                ans.push_back(new_row);
                current=new_row;
            }
        }
        return ans;
    }
};