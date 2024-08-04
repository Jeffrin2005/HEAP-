

class Solution {
public:
    vector<int>sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>>minHeap;
        for(auto&num : nums){
            minHeap.push(num);
        }
        // Extract elements from the heap and store them back in the array
        int index = 0;
        while(!minHeap.empty()) {
            nums[index] = minHeap.top();
            index++;
            minHeap.pop();
        }

        return nums;
    }
};
