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
    void Bfs(std::string& begin_word, std::unordered_map<std::string, std::vector<std::string>>& neighbors, std::unordered_map<std::string, int>& distance){
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
                    }
                }
            }
            head++;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<std::string, std::vector<std::string>> neighbors;
        std::unordered_map<std::string, int> distance;
        wordList.push_back(beginWord);
        EstablishEdges(wordList, neighbors);
        Bfs(beginWord, neighbors, distance);
        if(distance.find(endWord) == distance.end())
            return 0;
        return distance[endWord];
    }
};
