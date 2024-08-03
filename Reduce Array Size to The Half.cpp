
// time comp = o(nlogn) space comp = o(n)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        priority_queue<int>maxHeap;
        int target = arr.size() / 2; // We need to remove at least half of the elements
        int removed = 0;
        int setSize = 0;
        // Count the frequency of each element
        for(auto&num : arr){
            mp[num]++;
        }
        // Push all frequencies into the max heap
        for (auto&x : mp){
                maxHeap.push(x.second);
            }
        // Remove elements until we've removed at least half
        while(removed < target){
            int freq = maxHeap.top();
            maxHeap.pop();
            removed+=freq;
            setSize++;
        }
        return setSize;
    }
};
