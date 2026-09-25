//30. Substring with Concatenation of All Words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.size();
        int n = words.size();
        int m = words[0].size();

        unordered_map<string, int> wordCount; //need
        for(auto& w : words){
            wordCount[w]++;
        }
        vector<int>res;
        int total = n * m;//length of the substr we will have to check on
        if(total > size) return res;

        for(int startOff = 0; startOff < m; startOff++){
            unordered_map<string, int> window;
            int count = 0;
            int left = startOff;

            for(int right = startOff; right + m <= size; right += m){
                string word = s.substr(right, m);
                if(!wordCount.count(word)){
                    window.clear();
                    count = 0;
                    left = right + m;
                    continue;
                }
                window[word]++;
                count++;

                while(window[word] > wordCount[word]){
                    string leftWord = s.substr(left, m);
                    window[leftWord]--;
                    count--;
                    left += m;
                }
                if(count == n){
                    res.push_back(left);
                    string leftWord = s.substr(left, m);
                    window[leftWord]--;
                    count--;
                    left += m;
                }
            }
        }
        return res;
    }
};
