#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Step 1: Count the frequency of each integer
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        // Step 2: Use a priority queue (min-heap) to store the frequency and value pairs
        // The priority queue will store pairs {frequency, value}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& [key, value] : mp) {
            pq.push({value, key});
        }

        // Step 3: Remove elements from the priority queue until k reaches 0
        while (k > 0 && !pq.empty()) {
            auto [freq, value] = pq.top();
            pq.pop();
            if (k >= freq) {
                k -= freq;
            } else {
                pq.push({freq - k, value});
                k = 0;
            }
        }

        // Step 4: Return the number of unique integers left in the priority queue
        return pq.size();
    }
};
