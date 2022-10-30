class Solution {
public:
        bool IsAdjacent(std::string& s1, std::string& s2){
        int number_of_letter_differences = 0;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i])
                number_of_letter_differences++;
        return number_of_letter_differences == 1;
    }
    void Insert(std::string& s1, std::string& s2, std::unordered_map<std::string, std::vector<std::string>>& neighbors){
        if(neighbors.find(s1) == neighbors.end())
            neighbors[s1] = {s2};
        else
            neighbors[s1].push_back(s2);
    }
    void EstablishEdges(std::vector<std::string>& word_list, std::unordered_map<std::string, std::vector<std::string>>& neighbors){
        for(int i = 0 ; i < word_list.size(); i++)
            for(int j = i + 1; j < word_list.size(); j++){
                if(IsAdjacent(word_list[i], word_list[j])){
                    Insert(word_list[i], word_list[j], neighbors);
                    Insert(word_list[j], word_list[i], neighbors);
                }
            }
    }
    void Bfs(std::string& begin_word, std::unordered_map<std::string, std::vector<std::string>>& neighbors, std::unordered_map<std::string, int>& distance, std::unordered_map<std::string, std::vector<std::string>>& parents){
        std::vector<std::string> bfs_queue;
        bfs_queue.push_back(begin_word);
        int head = 0;
        distance[begin_word] = 1;
        while(head != bfs_queue.size()){
            std::string front_string = bfs_queue[head];
            if(neighbors.find(front_string) != neighbors.end()){
                for(int i = 0; i < neighbors[front_string].size(); i++){
                    std::string neighbor_cp = neighbors[front_string][i];
                    if(distance.find(neighbor_cp) == distance.end()){
                        bfs_queue.push_back(neighbor_cp);
                        distance[neighbor_cp] = distance[front_string] + 1;
                        parents[neighbor_cp] = {front_string};
                    }
                    else if(distance[neighbor_cp] == distance[front_string] + 1){
                        parents[neighbor_cp].push_back(front_string);
                    }
                }
            }
            head++;
        }
    }
    void FindAllPaths(std::string& end_word, std::string& begin_word, std::unordered_map<std::string, std::vector<std::string>>& parents,  std::vector<std::vector<std::string>>& all_paths, std::vector<std::string>& cur_path){
        if(end_word == begin_word){
            cur_path.push_back(end_word);
            all_paths.push_back(cur_path);
            cur_path.pop_back();
            return;
        }
        for(int i = 0; i < parents[end_word].size(); i++){
            std::string parent = parents[end_word][i];
            cur_path.push_back(end_word);
            FindAllPaths(parent, begin_word, parents, all_paths, cur_path);
            cur_path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<std::string, std::vector<std::string>> neighbors;
        std::unordered_map<std::string, std::vector<std::string>> parents;
        std::unordered_map<std::string, int> distance;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == beginWord)
                break;
            if(i + 1 == wordList.size())
                wordList.push_back(beginWord);
        }
        EstablishEdges(wordList, neighbors);
        Bfs(beginWord, neighbors, distance, parents);
        if(distance.find(endWord) == distance.end())
            return {};
        std::vector<std::vector<std::string>> all_paths;
        std::vector<std::string> cur_path = {};
        FindAllPaths(endWord, beginWord, parents, all_paths, cur_path);
        for(int i = 0; i < all_paths.size(); i++)
            std::reverse(all_paths[i].begin(), all_paths[i].end());
        return all_paths;
    }
};
