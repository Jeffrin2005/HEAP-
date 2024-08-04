class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      map<string,int>freqMap;
    for(auto& word : words){
        freqMap[word]++;
    }
    // Min-heap to store the words based on frequency and lexicographical order
    auto comp = [&](string&a,string& b){
        return freqMap[a] > freqMap[b] || (freqMap[a] == freqMap[b] and a < b);
    };
    priority_queue<string,vector<string>,decltype(comp)>minHeap(comp);
    // Maintain a heap of size k
    for(auto&x : freqMap){
        minHeap.push(x.first); // elements with least frequncey in the top of the heap will be removed 
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    // Extract the elements from the heap and add to result
    vector<string>result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }// the result should be reverse 
    reverse(result.begin(),result.end());

    return result;
    }
};
