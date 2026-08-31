//767. Reorganize String

struct cmp {
    bool operator()(const pair<int, char>&a, const pair<int, char>&b) const{
        if(a.first != b.first) return (a.first < b.first);
        return (a.second < b.second);
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> hm;
        for(int i = 0; i < n; i++){
            hm[s[i]]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        for( auto i : hm){
            int freq = i.second;
            int letter = i.first;
            pq.push({freq, letter});
        }
        string res = ""; int idx = 0;
        while(!pq.empty()){
            pair<int, char> p1 = pq.top();
            pq.pop();
            if(idx == 0 || res[idx-1] != p1.second){
                res.push_back(p1.second);
                idx++;
                p1.first--;
                if(p1.first > 0) pq.push(p1);

            }else{
                if(pq.empty()){
                    return "";
                }
                pair<int, char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                idx++;
                p2.first--;
                if(p2.first > 0) pq.push(p2);
                pq.push(p1);
            }
        }
        return res;
    }
};