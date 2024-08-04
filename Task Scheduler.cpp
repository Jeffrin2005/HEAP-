class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>freq;
    for(auto&task : tasks) freq[task]++;
    // Max heap to execute the task with the highest frequency first
  priority_queue<int> maxHeap;
    for(auto&p : freq){
        maxHeap.push(p.second); 
    }
    int cycles = 0;
    while(!maxHeap.empty()) {
        vector<int>temp;
        // maxheap will contain the count of each charcters

//        Cycle:   0   1   2   3   4   5   6   7
//        Task:    A   B  idle A   B  idle A   B
        // We need to wait for 'n + 1' intervals before re-executing the same task
        for (int i = 0; i <= n; i++){
            if(!maxHeap.empty()){
                temp.push_back(maxHeap.top());// we will wait for n+1 second  (temp will contain the count of each characters)
                maxHeap.pop();
            }
        }
        // Decrease the count of tasks and push back to heap if they are still left
        for(auto&count : temp){
            count--;
            if(count > 0){  // after decrement the count of character , the heap will contain the next higher character count
                maxHeap.push(count);
            }
        }
        // If the heap is empty, we only increment cycles by the number of tasks executed in this round
        // Otherwise, we must count the whole frame of 'n + 1' cycles
        if(maxHeap.empty()){   // if heap is  empty ,it means the next character must be in the n+1 seconds 
            cycles+=temp.size();
        }else{ // if heap is  empty ,it means the next character must be in the n+1 seconds 
                 // (cycles contain  the no of seconds)
              cycles+=(n+1);
        }
    }
    return cycles;
    }
};
