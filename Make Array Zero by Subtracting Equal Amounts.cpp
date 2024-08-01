class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Create a Min heap from priority_queue
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto&x: nums){ // we only need non-zero elements
            if(x > 0){
            pq.push(x);
            }
            
        }
        int count = 0;
        int num = 0;
        while(!pq.empty()){
                int temp = pq.top() - num;
                if(temp != 0){
                    num = temp + num;
                    count++;
                }

                pq.pop();
            
        }

        return count;
    }
};
