class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxHeap; // Max-heap for maximum values
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // Min-heap for minimum values
        int left = 0, right = 0;
        int result = 0;
        while (right < nums.size()){
            maxHeap.push({nums[right], right});
            minHeap.push({nums[right], right});
            // Check if current window is valid
            while (maxHeap.top().first - minHeap.top().first > limit){// taking window <= limit 
                left++; // Increment left to shrink the window
                // remove elements from heaps that are out of the current window
                while (maxHeap.top().second < left) maxHeap.pop();
                while (minHeap.top().second < left) minHeap.pop();
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};
// nums = [8,2,4,7] with limit = 4: dry run 

// maxHeap and minHeap are empty.
// left is initialized to 0, right is initialized to 0.
// 2. First Iteration (right = 0):
// Add nums[0] = 8 to both heaps.
// Both heaps now contain the pair (8, 0).
// The window [8] is valid since there's only one element.
// 3. Second Iteration (right = 1):
// Add nums[1] = 2 to both heaps.
// maxHeap contains (8, 0) and (2, 1), minHeap contains (2, 1) and (8, 0).
// The window [8, 2] is checked. The difference 8 - 2 = 6 is greater than limit = 4.
// Increment left to 1 to shrink the window.
// Now, maxHeap.top() is (8, 0), but since 0 < left, we pop it from maxHeap.
// Similarly, minHeap.top() is (2, 1), which is within the window, so it stays.
// Third Iteration (right = 2):
// Add nums[2] = 4 to both heaps.
// maxHeap contains (4, 2) and (2, 1), minHeap contains (2, 1) and (4, 2).
// The window [2, 4] is valid since 4 - 2 = 2 is less than limit = 4.
// 5. Fourth Iteration (right = 3):
// Add nums[3] = 7 to both heaps.
// maxHeap contains (7, 3), (4, 2), and (2, 1), minHeap contains (2, 1), (4, 2), and (7, 3).
// The window [2, 4, 7] is checked. The difference 7 - 2 = 5 is greater than limit = 4.
// Increment left to 2 to shrink the window.
// Now, minHeap.top() is (2, 1), but since 1 < left, we pop it from minHeap.
// Consider the array [8, 2, 4, 7] with a limit of 4:
// If we examine the subarray [8, 2], the maximum value is 8 and the minimum value is 2.


// logic of taking minheap and maxheap
//  The difference is 8 - 2 = 6, which is greater than the limit of 4.
//   This means there exists at least one pair of elements (in this case, 8 and 2) whose difference exceeds the limit, making this subarray invalid.
// Conversely, for the subarray [2, 4], the maximum value is 4 and the minimum value is 2. 
// The difference is 4 - 2 = 2, which is within the limit. 
// This confirms that all pairs within this subarray (though there's only one pair here) also have differences within the limit.



