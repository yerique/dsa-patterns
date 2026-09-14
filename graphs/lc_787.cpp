//787. Cheapest Flights Within K Stops

//via bollman-ford most intuitive
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, 1e8);
        res[src] = 0;
        int times = k + 1;
        while(times--){
            vector<int> temp = res;
            for(int i = 0; i < flights.size(); i++){
                int s = flights[i][0];
                int d = flights[i][1];
                int wt = flights[i][2];
                if(res[s] == 1e8) continue;
                int newWt = res[s] + wt;
                if(newWt < temp[d]){
                    temp[d] = newWt;
                }
            }
            res = temp;
        }
        return (res[dst] == 1e8) ? -1 : res[dst];
    }
};

//via bfs (similar to rotten oranges)
class Solution {
public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int d = edges[i][1];
            int wt = edges[i][2];
            adj[s].push_back({d, wt});
        }
        vector<int> res(n, 1e8);
        queue<pair<int, int>> que;
        que.push({0, src});
        int noOfStops = 0;
        while(!que.empty() && noOfStops <= k){
            int s = que.size();
            while(s--){
                auto [cost, node] = que.front();
                que.pop();
                for(auto [neighbour, wt] :  adj[node]){
                    int newCost = cost + wt;
                    if(newCost < res[neighbour]){
                        que.push({newCost, neighbour});
                        res[neighbour] = newCost;
                    }
                }
            }
            noOfStops++;
        }
        return (res[dst] == 1e8) ? -1 : res[dst];
    }
};

//via dijkstra modified(not based on just minimum distanc yes that happenns via minheap but minimal distace with stops over the limit is not welcome so we only push if stops to get there were at max the limit)
class Solution {
public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int d = edges[i][1];
            int wt = edges[i][2];
            adj[s].push_back({d, wt});
        }
        vector<int> minStop(n, 1e8);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0}); // cost, node, stops
        while(!pq.empty()){
            auto popped = pq.top();
            int cost = popped[0]; int node = popped[1]; int stops = popped[2];
            pq.pop();
            if(node == dst) return cost;
            if(stops >= minStop[node]) continue;
            minStop[node] = stops;
            for(auto [neighbour, wt] : adj[node]){
                int newCost = cost + wt;
                if(stops <= k){
                    pq.push({newCost, neighbour, stops + 1}); //if you get there with k stops, k+1th flight is allowed, which will become the no of stops for the nieghbours this neighbour
                }
            }
        }
        return -1;
    }
};
//same as above just flight analogy ie., flight to get a ap = stops to get there + 1 ie., flight = stops + 1;
class Solution {
public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int s = edges[i][0];
            int d = edges[i][1];
            int wt = edges[i][2];
            adj[s].push_back({d, wt});
        }
        vector<int> minFlight(n, 1e8); //flights are edges basicaly, flight to get to a point is the stps to get there + 1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0}); // cost, node, flight
        while(!pq.empty()){
            auto popped = pq.top();
            int cost = popped[0]; int node = popped[1]; int flight = popped[2];
            pq.pop();
            if(node == dst) return cost;
            if(flight >= minFlight[node]) continue; //we are recording flights now so, if we get here after poppin the min heap (with a val of flight), this means before we alrady got a route with same no of flight but better cost so, ignore this one. just popping this out is only task.
            minFlight[node] = flight;
            for(auto [neighbour, wt] : adj[node]){
                int newCost = cost + wt;
                int newFlight = flight + 1; //flight to get to the neighbour
                if(newFlight <= k+1){ // max allowed stops is k then max allowed flght is k+1;
                    pq.push({newCost, neighbour, newFlight });
                }
            }
        }
        return -1;
    }
};