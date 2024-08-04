

class Solution {
public:
    int minStoneSum(std::vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(),piles.end());
        // Perform k operations
        for(int i = 0; i < k; i++){
            int top = maxHeap.top();
            maxHeap.pop();
            // Remove floor(top / 2) stones from the largest pile
            top-=top / 2;
            // Push the modified pile back into the heap
            maxHeap.push(top);
        }
        // Calculate the remaining total number of stones
        int remainingStones = 0;
        while(!maxHeap.empty()){
            remainingStones+=maxHeap.top();
            maxHeap.pop();
        }
        return remainingStones;
    }
};
