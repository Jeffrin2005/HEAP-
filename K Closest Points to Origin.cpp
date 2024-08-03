#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
// points = [[3,3],[5,-1],[-2,4]], k = 2  dry run 

// A max heap (maxHeap) is initialized with a custom comparator that maintains the largest distances at the top of the heap.
// 2. Iterating through points:
// For each point, we calculate the squared distance from the origin (0, 0) using the formula ({distance} = x^2 + y^2 ).
// 3. Processing each point:
// Point [3,3]:
// Squared distance = (3^2 + 3^2 = 18).
// Since the heap size is less than k (2), we push this distance and index into the heap.
// Heap now contains: [(18, 0)].
// Point [5,-1]:
// Squared distance = (5^2 + (-1)^2 = 26).
// Heap size is less than k, so we push this distance and index.
// Heap now contains: [(26, 1), (18, 0)] (26 is at the top because it's the largest).
// Point [-2,4]:
// Squared distance = ((-2)^2 + 4^2 = 20).
// Heap size equals k, but 20 is less than the top of the heap (26).
// We pop the top (26, 1) and push (20, 2).
// Heap now contains: [(20, 2), (18, 0)] (20 is at the top).
// after that creating a result vector 
class Solution {
public:
 struct Compare{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first < b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        // Max heap to store the k closest points with greater distances at the top
     
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>maxHeap;
        // Calculate squared distance and maintain only k smallest distances in the heap
        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(maxHeap.size() < k) {
                maxHeap.push({dist, i});
            }else if(dist < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({dist, i});
            }
        }
        // Collect the k closest points
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        // for(auto&x : points) cout << x << " x" << nl;
        return result;
    }
};
