
class Solution {
public:
    string longestDiverseString(int a, int b, int c){
      priority_queue<pair<int, char>>maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});
        string result;
        while(!maxHeap.empty()){
                 // to get the longest possible happy string we are makeing 'bb_' , 'aa_', 'cc_'
           pair<int,char>top1 = maxHeap.top();
            maxHeap.pop();
            int count1 = top1.first;// count of 'a' ,'b','c'
            char char1 = top1.second;// 'a','b','c'
            int length = result.size();
            // Check if the last two characters are the same as this one
            // checking this condition aaa", "bbb", or "ccc"
            // currently we have 'aa_' or 'bb_c' or 'cc_', on the basis of frequency of maximum character in heap  
            if(length >= 2 && result[length - 1] == char1 && result[length - 2] == char1){
                if(maxHeap.empty()) break; // No other character to use
                // Use the next most frequent character
                pair<int,char>top2 = maxHeap.top();// using another character 
                maxHeap.pop();
                int count2 = top2.first;
                char char2 = top2.second;
                result+=char2;
                count2--;
                if(count2 > 0){
                    maxHeap.push({count2, char2});
                }
                maxHeap.push({count1, char1}); // Push char1 back for potential later use
            }else{
                result+=char1;
                count1--;
                if(count1 > 0){
                    maxHeap.push({count1, char1});
                }
            }
        }

        return result;
    }
};
