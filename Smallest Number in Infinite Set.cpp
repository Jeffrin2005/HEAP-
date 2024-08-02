

class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    set<int> seen;
    int min_num;

public:
    SmallestInfiniteSet() {
        min_num = 1;
    }
    
    int popSmallest() {
        if (!heap.empty()) {
            int smallest = heap.top();
            heap.pop();
            seen.erase(smallest);
            return smallest;
        }
        min_num++;
        return min_num - 1;        
    }
    
    void addBack(int num) {
        if (min_num > num && seen.find(num) == seen.end()) {
            heap.push(num);
            seen.insert(num);
        }
    }
};
