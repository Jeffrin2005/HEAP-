#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones){
    priority_queue<int> maxHeap(stones.begin(),stones.end());
        // Process the heap until we have one or no stones left
        while(maxHeap.size() > 1){
            int y = maxHeap.top(); // The heaviest stone
            maxHeap.pop();
            int x = maxHeap.top(); // The second heaviest stone
            maxHeap.pop();
            if(x != y){
                maxHeap.push(y - x); // Push the result of the smash
            }
        }
        // If there's one stone left, return its weight; otherwise, return 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
