class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = 0;
        int index = 0; //using index as the counter. It seems just using the tranditional for loop that can make the code cleaner
        bool any_valid_point = false;
        int min_distance = numeric_limits<int>::max(); // #include <limit>
        for(const auto& point: points) {
            if(point[0]==x || point[1]==y) {
                any_valid_point = true;
                int manhattan_distance = abs(x-point[0])+abs(y-point[1]); //std::abs
                if(manhattan_distance<min_distance) {
                    min_distance = manhattan_distance;
                    ans = index;
                }
            }
            ++index;
        }
        if(!any_valid_point) {
            return -1;
        }
        return ans;
    }
};
