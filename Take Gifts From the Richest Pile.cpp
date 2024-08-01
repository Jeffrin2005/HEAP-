#include <bits/stdc++.h>
#define ll long long 

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
          priority_queue<int>pq(gifts.begin(), gifts.end());
        ll ans = 0;
     
        while(k--){
           int  x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
