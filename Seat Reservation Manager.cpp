class SeatManager {
private:
   priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    SeatManager(int n) {
        //  the heap with all seat numbers from 1 to n
        for(int i = 1; i <= n;i++){
            minHeap.push(i);
        }
    }
    
    int reserve() {
        // The top of the heap is the smallest number available
        int smallestAvailableSeat = minHeap.top();
        minHeap.pop(); 
        return smallestAvailableSeat;
    }
    
    void unreserve(int seatNumber) {
        // Add the seat number back to the heap
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
