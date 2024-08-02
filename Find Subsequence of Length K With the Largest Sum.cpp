//nums = [-1, -2, 3, 4] and k = 3
// Iterate through each element in nums:
// i = 0: Push (-1, 0) into the heap.
// i = 1: Push (-2, 1) into the heap. Heap now has (-2, 1), (-1, 0).
// i = 2: Push (3, 2) into the heap. Heap now has (-2, 1), (-1, 0), (3, 2).
// i = 3: Push (4, 3) into the heap. Heap now has (-2, 1), (-1, 0), (3, 2), (4, 3). Since the heap size exceeds k, pop the smallest element, which is (-2, 1). Heap becomes (-1, 0), (3, 2), (4, 3).
// 3. Extracting from the Min-Heap: 
// map will be in sorted order on the basis of index 
// Transfer elements from the heap to a map where the key is the index and the value is the number. This will automatically sort them by index.
// Pop (-1, 0), (3, 2), and (4, 3) from the heap and insert into the map. The map now has {0: -1, 2: 3, 3: 4}
// ans = [-1, 3 ,4 ].
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;// minheap 
        for(int i = 0; i < nums.size(); i++){
            q.push({nums[i], i});
            if (q.size() > k) {
                q.pop();
            }
        }
        map<int,int> m;// 
        while(!q.empty()){
            m.insert({q.top().second,q.top().first});
            q.pop();
        }
        vector<int>ans;
        for (auto&x : m){
            ans.push_back(x.second);
        }

        return ans;
    }
};
