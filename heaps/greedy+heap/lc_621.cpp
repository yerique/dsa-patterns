//621. Task Scheduler

//one-way to do is this-a better in the below
struct cmp {
    bool operator()(const pair<int, char>&a, const pair<int, char>&b) const{
        if(a.first != b.first) return (a.first < b.first);
        return (a.second < b.second);
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        unordered_map<char, int> hm;
        for(int i = 0; i < s; i++){
            hm[tasks[i]]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        for(auto i : hm){
            int freq = i.second;
            char task = i.first;
            pq.push({freq, task});
        }
        int totalTime = 0;
        while(!pq.empty()){
            int roundSize = n + 1;
            int slotsInRound = roundSize;
            int tasksExecutedInRound = 0;

            vector<pair<int, char>> currRoundTasks;
            while(slotsInRound > 0 && !pq.empty()){
                pair<int, char> task = pq.top(); pq.pop();

                slotsInRound--;
                tasksExecutedInRound++;

                task.first--;
                currRoundTasks.push_back(task);
            }
            for(auto task : currRoundTasks){
                if(task.first > 0){
                    pq.push(task);
                }
            }

            if(pq.empty()){
                totalTime += tasksExecutedInRound;
            }else{
                totalTime += roundSize;
            }
        }
        return totalTime;
    }
};

/*
 * ============================================================================
 * FLOWCHART
 * ============================================================================
 *
 *                 +--------------------------------------+
 *                 | Count Task Frequencies -> Max-Heap   |
 *                 +--------------------------------------+
 *                                    |
 *                                    v
 *                 +--------------------------------------+ <---------+
 *                 | While Heap is NOT empty:             |           |
 *                 | Open a new round of (n + 1) slots    |           |
 *                 +--------------------------------------+           |
 *                                    |                               |
 *                                    v                               |
 *                 +--------------------------------------+           |
 *                 |  Pop up to (n + 1) distinct tasks    |           |
 *                 |  from Heap:                          |           |
 *                 |  - Decrement frequency (task.first--) |          |
 *                 |  - Store in 'temp' list              |           |
 *                 |  - Track 'tasksExecuted++'           |           |
 *                 +--------------------------------------+           |
 *                                    |                               |
 *                                    v                               |
 *                 +--------------------------------------+           |
 *                 |  Push tasks from 'temp' list back    |           |
 *                 |  into Heap (ONLY if task.first > 0)  |           |
 *                 +--------------------------------------+           |
 *                                    |                               |
 *                            [ Is Heap empty? ]                      |
 *                               /          \                         |
 *                       (Yes)  /            \ (No)                   |
 *                             v              v                       |
 *                  +-------------+  +--------------------------------+
 *                  | Add ONLY    |  | Add full (n + 1) round size    |
 *                  | tasksExecuted| (Includes tasks + idle slots)    |
 *                  +-------------+  +--------------------------------+
 *                             \              /                       |
 *                              v            v                        |
 *                      +-----------------------------+               |
 *                      |       totalTime += X        |---------------+
 *                      +-----------------------------+
 *                                    |
 *                          (Loop breaks when empty)
 *                                    v
 *                      +-----------------------------+
 *                      |      Return totalTime       |
 *                      +-----------------------------+
 * ============================================================================
 */

//a better solution:
struct cmp {
    bool operator()(const pair<int, char>&a, const pair<int, char>&b) const{
        if(a.first != b.first) return (a.first < b.first);
        return (a.second < b.second);
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int> frequency;
        for (int i = 0; i < m; i++) {
            frequency[tasks[i]]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        unordered_map<char, int> eligiblePos;
        for (auto task : frequency) {
            pq.push({task.second, task.first});
            eligiblePos[task.first] = 1;
        }
        int currTaskPos = 1;
        while (!pq.empty()) {
            vector<pair<int, char>> temp;
            while (!pq.empty()) {
                pair<int, char > maxTask = pq.top();
                pq.pop();
                if (currTaskPos >= eligiblePos[maxTask.second]) {
                    maxTask.first--;
                    if (maxTask.first > 0) {
                        pq.push(maxTask);
                    }
                    eligiblePos[maxTask.second] = currTaskPos + n + 1;
                    break;
                }else {
                    temp.push_back(maxTask);
                }
            }
            for (auto task : temp) {
                pq.push(task);
            }
            currTaskPos++;
        }
        return currTaskPos - 1;
    }
};
