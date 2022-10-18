class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int min_coordinate = newInterval[0];
        int max_coordinate = newInterval[1];
        std::vector<std::vector<int>> result;
        bool inserted_new_interval = false;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]){
                min_coordinate = std::min(intervals[i][0], min_coordinate);
            }
            if(intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[1]){
                max_coordinate = std::max(intervals[i][1], max_coordinate);
            }
            if(intervals[i][1] < min_coordinate)
                result.push_back(intervals[i]);
            if(intervals[i][0] > max_coordinate){
                if(!inserted_new_interval){
                    result.push_back({min_coordinate, max_coordinate});
                    inserted_new_interval = true;
                    result.push_back(intervals[i]);
                }
                else
                    result.push_back(intervals[i]);
            }

        }
        if(!inserted_new_interval)
            result.push_back({min_coordinate, max_coordinate});
        return result;
    }
};
