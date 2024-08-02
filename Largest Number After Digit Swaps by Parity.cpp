class Solution {
public:
    int largestInteger(int num) {
     string s = to_string(num);
    priority_queue<int>evenDigits;
        priority_queue<int>oddDigits;
        // Separate digits into even and odd heaps
        for(auto&c : s){
            int digit = c - '0';
            if(digit % 2 == 0){
                evenDigits.push(digit);
            }else{
                oddDigits.push(digit);
            }
        }

        // Reconstruct the number with the largest digits from heaps in their respective positions
        string result;
        for(auto&c : s){
            int digit = c - '0';
            if(digit % 2 == 0){
                result+= '0' + evenDigits.top();
                evenDigits.pop();
            }else{
                result += '0' + oddDigits.top();
                oddDigits.pop();
            }
        }
        return stoi(result);
    }
};
