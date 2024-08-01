class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        // Create a min-heap using priority_queue with greater comparison to simulate min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        vector<int>arr;
        arr.reserve(nums.size()); 
        while(!minHeap.empty()){
            int alice = minHeap.top(); // Alice removes the minimum element
            minHeap.pop();
            int bob = minHeap.top(); // Bob removes the next minimum element
            minHeap.pop();
            // Bob appends first, then Alice
            arr.push_back(bob);
            arr.push_back(alice);
        }

        return arr;
    }
};
