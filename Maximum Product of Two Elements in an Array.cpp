
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Max-heap to store larger elements in the top 
        priority_queue<int> pq(nums.begin(),nums.end());
        int max1 = pq.top();
         pq.pop();
        int max2 = pq.top();
         pq.pop();
        return (max1 - 1) * (max2 - 1);
    }
};
