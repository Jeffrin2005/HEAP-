

class Solution {
public:
    int fillCups(std::vector<int>& amount){
        // Create a max heap to always process the type of cup with the maximum remaining amount first
        priority_queue<int> maxHeap;
         for(auto&a : amount){
            if(a > 0) maxHeap.push(a);
        }
        int sec = 0;
        // Process the heap until all cups are filled
        while(!maxHeap.empty()){
            int first = 0;
            int  second = 0;
            // Take the top element (the largest one) 
            if(!maxHeap.empty()){
                first = maxHeap.top();
                maxHeap.pop();
            }             // we can fill 2 cups at a time
            // Take the next top element if available
            if (!maxHeap.empty()) {
                second = maxHeap.top();
                maxHeap.pop();
            }
            // Increment the number of seconds
            sec++;
            // Decrease the count of these types and push back if still needed
            if (--first > 0) maxHeap.push(first);
            if (--second > 0) maxHeap.push(second);
        }
        
        return sec;
    }
};
