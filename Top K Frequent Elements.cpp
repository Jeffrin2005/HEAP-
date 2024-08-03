#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
// nums = [1,1,1,2,2,3] and k = 2

// First Pair (1, 3):
// Push (3, 1) into the heap.
// Heap now: [(3, 1)]
// Second Pair (2, 2):
// Push (2, 2) into the heap.
// Heap now: [(2, 2), (3, 1)] (remember, the heap is a min-heap based on the first value of the pair, which is frequency)
// Third Pair (3, 1):
// Push (1, 3) into the heap.
// Heap now: [(1, 3), (3, 1), (2, 2)]
// Since the heap size exceeds k (which is 2), we pop the top element (which has the smallest frequency).
// Pop (1, 3) from the heap.
// Heap now: [(2, 2), (3, 1)]
// create the elements from the heap 
class Solution {
public:
//In a min-heap configured to compare elements based on their frequency, 
//the element with the smallest frequency count will be at the top of the heap.
struct Compare {
    bool operator()(pair<int,int>&a,pair<int, int>&b){
        return a.first > b.first; // Min-heap based on frequency
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k){
     map<int,int>mp;
    for(auto&num : nums){
            mp[num]++;
        }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>minHeap;
    //  heap of the top k elements
  for(auto&x : mp){
    int num = x.first;   // Element
    int freq = x.second; // Frequency of the element
    minHeap.push({freq, num});
    if (minHeap.size() > k){
        minHeap.pop();
    }
}
    //Extract the elements from the heap
   vector<int>topK;
    while(!minHeap.empty()){ // order does not matter [1,2] or [2,1];
        topK.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return topK;
    }
};
