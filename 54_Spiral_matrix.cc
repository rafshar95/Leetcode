class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int cur_x = 0, cur_y =0, min_x = 0, min_y = 0, max_x = m - 1, max_y = n - 1;
        int dir = 0;
        std::vector<int> order;
        while(cur_x <= max_x && cur_x >= min_x && cur_y >= min_y && cur_y <= max_y){
            order.push_back(matrix[cur_y][cur_x]);
            if(cur_x == max_x && cur_x == min_x && cur_y == max_y && cur_y == min_y)
                break;
            if(dir == 0){
                if(cur_x < max_x)
                    cur_x++;
                else{
                    dir = 1;
                    cur_y++;
                    min_y++;
                }
            }
            else if(dir == 1){
                if(cur_y < max_y)
                    cur_y++;
                else{
                    dir = 2;
                    cur_x--;
                    max_x--;
                }
            }
            else if(dir == 2){
                if(cur_x > min_x)
                    cur_x--;
                else{
                    dir = 3;
                    cur_y--;
                    max_y--;
                }
            }
            else if(dir == 3){
                if(cur_y > min_y)
                    cur_y--;
                else{
                    dir = 0;
                    cur_x++;
                    min_x++;
                }
            }

        }
        return order;
    }
};
