class Solution {
public:

    static bool cmp(vector<int>&t1, vector<int>&t2){
        return t1[1] < t2[1]; //sort based on from distance
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(),cmp);// sort based on from 'distance'
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int curr = 0; //current capacity
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().first <= trips[i][1]){
//before reaching our next from distance 
//we will remove the passengers with to distance lesser than it
                curr -= pq.top().second;
                pq.pop();
            }

            curr += trips[i][0]; //add new passengers 
            if(curr > capacity) return false; //check capacity overflow
            pq.push({trips[i][2], trips[i][0]});
        }
        return true;

    }
};
