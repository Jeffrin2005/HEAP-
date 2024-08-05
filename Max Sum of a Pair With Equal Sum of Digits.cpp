//nums = [18,43,36,13,7]  (ans = 54)

// For 18: Sum of digits = 1 + 8 = 9. digitSumMap[9].push(18)
// For 43: Sum of digits = 4 + 3 = 7. digitSumMap[7].push(43)
// For 36: Sum of digits = 3 + 6 = 9. digitSumMap[9].push(36)
// For 13: Sum of digits = 1 + 3 = 4. digitSumMap[4].push(13)
// For 7: Sum of digits = 7. digitSumMap[7].push(7)
// The map now looks like:
// 9 -> [36, 18] (priority queue orders them as 36 being the top)
// 7 -> [43, 7]
// 4 -> [13]
// 3. Calculating Maximum Sum:
// For key 9: The queue has two elements. first = 36, second = 18. Sum = 36 + 18 = 54.
// For key 7: The queue has two elements. first = 43, second = 7. Sum = 43 + 7 = 50.
// For key 4: The queue has only one element, so it's skipped.
// 4. Finding the Maximum: The maximum of all valid sums is max(54, 50) = 54.
class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>>digitSumMap;
        for(auto&num : nums){
            int digitSum = sumOfDigits(num);
            digitSumMap[digitSum].push(num);
        }
        int maxSum = -1;
        for (auto&x : digitSumMap){
            if (x.second.size() > 1) {
                int first = x.second.top();
                x.second.pop();
                int second = x.second.top();
                maxSum = max(maxSum, first + second);
            }
        }

        return maxSum;
    }
};
