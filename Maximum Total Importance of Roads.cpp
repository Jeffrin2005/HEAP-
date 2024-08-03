
#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //  Count the number of connections for each city
        vector<int>connections(n, 0);
        for(auto&road : roads) {
            connections[road[0]]++;
            connections[road[1]]++;
        }
        //  Use a priority queue to sort cities by their number of connections
        priority_queue<pair<int, int>> pq;// max-heap for connections[i] , connection with higher values will be in the top 
        for(int i = 0; i < n;i++){
            pq.push({connections[i], i});
        }
        // assign values to cities based on their number of connections
        vector<int>values(n);
        int value = n;
        while (!pq.empty()){
            int city = pq.top().second;// (i = city number) , (connections[i] = road connection)
            pq.pop();
            values[city] = value;// placing the maximum 'n' for maximum no of connection 
            // placing minimum 'n' for minimum no of connections
            value--;
        }
        ll ans = 0;
        for(auto& road : roads){
            ans+=values[road[0]] + values[road[1]];
        }

        return ans;
    }
};
