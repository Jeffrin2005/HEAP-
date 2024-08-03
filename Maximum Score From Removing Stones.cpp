
class Solution {
public:
    int maximumScore(int a, int b, int c) {
      priority_queue<int> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);
        int score = 0;
        while(true){
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if(first == 0 || second == 0){
                break;
            }
            // Take one stone from each of the two largest piles
            first--;
            second--;
            score++;
            // Push the updated counts back into the heap
            maxHeap.push(first);
            maxHeap.push(second);
        }
        return score;
    }
};
