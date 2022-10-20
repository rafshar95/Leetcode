class Solution {
public:
    void dfs(std::string current_string, std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::unordered_map<string, double>& nominal_values){
        for(int i = 0; i < equations.size(); i++){
            if(equations[i][0] == current_string && nominal_values.find(equations[i][1]) == nominal_values.end()){
                nominal_values[equations[i][1]]  = nominal_values[equations[i][0]] * values[i];
                dfs(equations[i][1], equations, values, nominal_values);
            }
            if(equations[i][1] == current_string && nominal_values.find(equations[i][0]) == nominal_values.end()){
                nominal_values[equations[i][0]]  = nominal_values[equations[i][1]] / values[i];
                dfs(equations[i][0], equations, values, nominal_values);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<string, double> nominal_values;
        std::unordered_map<string, bool> string_exists;
        for(int i = 0; i < equations.size(); i++){
            string_exists[equations[i][0]] = true;
            string_exists[equations[i][1]] = true;
        }
        std::vector<double> results;

        for(int i = 0; i < queries.size(); i++){
            if(string_exists.find(queries[i][0]) == string_exists.end() || string_exists.find(queries[i][0]) == string_exists.end()){
                results.push_back(-1);
                continue;
            }
            nominal_values.clear();
            nominal_values[queries[i][0]] = 1;
            dfs(queries[i][0], equations, values, nominal_values);
            if(nominal_values.find(queries[i][1]) == nominal_values.end())
                results.push_back(-1);
            else
                results.push_back(nominal_values[queries[i][1]]);
        }
        return results;
    }
};
