#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
// matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
// k = 8
// Push (1, {0, 0}), (10, {1, 0}), (12, {2, 0}) into the heap.
// First 7 Extractions:
// Extract (1, {0, 0}), push (5, {0, 1}).
// Extract (5, {0, 1}), push (9, {0, 2}).
// Extract (9, {0, 2}).
// Extract (10, {1, 0}), push (11, {1, 1}).
// Extract (11, {1, 1}), push (13, {1, 2}).
// Extract (12, {2, 0}), push (13, {2, 1}).
// Extract (13, {1, 2}), push (15, {2, 2}).
// Eighth Extraction:
// Extract (13, {2, 1}). This is the 8th extraction, so 13 is the 8th smallest element.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        struct Compare{
        bool operator()(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            return a.first > b.first;
        }
    };
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,Compare>minHeap;
    int n = matrix.size();
    //  the heap with the first element of each row
    for(int i = 0; i < n;i++){
        minHeap.push({matrix[i][0], {i, 0}});
    }
    int result = 0;
    // Extract-min k times
    for (int i = 0; i < k; i++){
        auto elem = minHeap.top();
        minHeap.pop();
        result = elem.first;
        int row = elem.second.first;
        int col = elem.second.second;
        // If there is a next element in the row, add it to the heap
        if (col + 1 < n) {
            minHeap.push({matrix[row][col + 1], {row, col + 1}});
        }
    }

    return result;
    }
};
