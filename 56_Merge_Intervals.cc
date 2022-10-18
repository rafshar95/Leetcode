class Solution {
public:
    bool IsSmaller(std::vector<int> x, std::vector<int> y){
        return x[0] <= y[0];
    }
    void Merge(std::vector<std::vector<int>>& intervals, int left, int right){
        int mid = (left + right) / 2;
        std::vector<std::vector<int>> tmp;
        for(int i = left, j = mid + 1; i <= mid || j <= right; ){
            if(i > mid){
                tmp.push_back(intervals[j]);
                j++;
            }
            else if(j > right){
                tmp.push_back(intervals[i]);
                i++;
            }
            else{
                if(IsSmaller(intervals[i], intervals[j])){
                    tmp.push_back(intervals[i]);
                    i++;
                }
                else{
                    tmp.push_back(intervals[j]);
                    j++;
                }
            }
        }
        for(int i = 0; i < tmp.size(); i++){
            intervals[i + left] = tmp[i];
        }
        tmp.clear();
    }
    void MergeSort(std::vector<std::vector<int>>& intervals, int left, int right){
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        MergeSort(intervals, left, mid);
        MergeSort(intervals, mid + 1, right);
        Merge(intervals, left, right);
    }
    vector<vector<int>> merge(vector<vector<int>>& Intervals) {
        //MergeSort(Intervals, 0, Intervals.size() - 1);
        std::sort(Intervals.begin(), Intervals.end());
        int max_finish = -1;
        int start = -1;
        std::vector<std::vector<int>> result;
        for(int i = 0; i < Intervals.size(); i++){
            if(Intervals[i][0] > max_finish){
                if(start != -1)
                    result.push_back({start, max_finish});
                start = Intervals[i][0];
                max_finish = Intervals[i][1];
            }
            else{
                max_finish = std::max(max_finish, Intervals[i][1]);
            }
        }
        result.push_back({start, max_finish});
        return result;
    }
};
