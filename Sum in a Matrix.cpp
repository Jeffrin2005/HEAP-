class Solution {
public:
    int matrixSum(vector<vector<int>>& nums){
        int score = 0;
        priority_queue<int>maxHeap;
        vector<priority_queue<int>>rowMaxHeaps;
        for (auto& row : nums) {
            priority_queue<int>pq;// max-heap (top elements will be higher value)
            for(auto&num : row){// loopin for each row in the given 'nums_matrix
                pq.push(num);
            }
            rowMaxHeaps.push_back(move(pq));
        }
        /// so in the rowMaxHeaps heap contains the elemenets of each row in the given matrix (top elements with higher values)
        //  the matrix until all rows are empty
        while(!rowMaxHeaps.empty()){
            int iterationMax = 0;
            vector<priority_queue<int>>nextRowMaxHeaps;
            // Remove the largest element from each row and find the max of them
            for (auto&pq : rowMaxHeaps){
                if(!pq.empty()){
                    int top = pq.top();
                    pq.pop();
                    iterationMax = max(iterationMax,top);
                    // Only keep non-empty heaps for the next iteration
                    if(!pq.empty()){
                        nextRowMaxHeaps.push_back(move(pq));
                    }
                }
            }
            // Add the maximum of this iteration to the score
            score+=iterationMax;
            // Move to the next set of heaps
            rowMaxHeaps = std::move(nextRowMaxHeaps);
        }

        return score;
    }
};
