//127. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, bool> vis;
        for(int i = 0; i < n; i++){
            vis[wordList[i]] = 1;
        }
        if(vis.find(beginWord) == vis.end()) vis[beginWord] = 1;
        if(vis.find(endWord) == vis.end()) return 0;
        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        vis.erase(beginWord);
        while(!que.empty()){
            auto [str, val] = que.front();
            que.pop();
            if(str == endWord) return val;
            for(int i = 0; i < str.size(); i++){
                char c = str[i];
                for(int j = 97; j <= 122; j++){ //ascii codes from lc a->z
                    if(c == j) continue;
                    str[i] = j;
                    if(vis.find(str) != vis.end()){ //agar mil gya
                        que.push({str, val + 1});
                        vis.erase(str);
                    }
                }
                str[i] = c;
            }
        }
        return 0;
    }
};