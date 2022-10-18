class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n - 1, left = 0, right = n -1;
        int cur_x = 0, cur_y = 0, dir = 0;
        int cur_cnt = 0;
        std::vector<std::vector<int>> result(n, std::vector<int> (n));
        while(top <= bottom && left <= right){
            cur_cnt++;
            result[cur_y][cur_x] = cur_cnt;
            if(dir == 0){
                if(cur_x < right)
                    cur_x++;
                else{
                    cur_y++;
                    top++;
                    dir = 1;
                }
            }
            else if(dir == 1){
                if(cur_y < bottom)
                    cur_y++;
                else{
                    cur_x--;
                    right--;
                    dir = 2;
                }
            }
            else if(dir == 2){
                if(cur_x > left)
                    cur_x--;
                else{
                    cur_y--;
                    bottom--;
                    dir = 3;
                }
            }
            else{
                if(cur_y > top)
                    cur_y--;
                else{
                    cur_x++;
                    dir = 0;
                    left++;
                }
            }
        }
        return result;
    }
};
