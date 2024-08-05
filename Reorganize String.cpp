

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> count;
        for(auto&c : s){
            count[c]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(auto&p : count){
            maxHeap.push({p.second, p.first});// {count, character } heap with maximum count 
        }
        string result = "";
        while(maxHeap.size() > 1){// needs atleast two elements
            auto top1 = maxHeap.top(); maxHeap.pop();
            auto top2 = maxHeap.top(); maxHeap.pop();
            result+=top1.second;
            result+=top2.second;
            top1.first--;
             top2.first--;
            if (top1.first > 0) {
                maxHeap.push(top1);
            }
            if (top2.first > 0) {
                maxHeap.push(top2);
            }
        }

        if (!maxHeap.empty()) {
            auto last = maxHeap.top();
            if (last.first > 1) {
                return ""; // Not possible to rearrange
            }
            result += last.second;
        }

        return result;
    }
};

// Let's consider the example string s = "aaab".
// Initial Setup:
// Character Count: {a: 3, b: 1}
// Building the Max Heap:
// Heap Content: [(3, 'a'), (1, 'b')] (sorted by count in descending order)
// Processing the Heap:
// Initial Result String: ""
// First Iteration of the While Loop:
// Pop Two Elements:
// Top1: (3, 'a')
// Top2: (1, 'b')
// Update Result: "ab"
// Decrement Counts and Push Back if Needed:
// Top1: (2, 'a') (pushed back into heap)
// Top2: (0, 'b') (not pushed back as count is zero)
// Updated Heap: [(2, 'a')]
// Exiting the While Loop:
// Heap Size Check: size <= 1 (True, loop exits)
// Final Check for Remaining Characters:
// Check Remaining Heap:
// Last Element in Heap: (2, 'a')
// Count Check: count > 1 (True, count is 2)
// Since the count of 'a' is more than 1, adding it to the result string "ab" would result in "aba" followed by another 'a', making the final string "abaa", 
// which violates the condition as the last two characters are the same.
