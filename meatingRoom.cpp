#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings by their start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Initialize the priority queues
        // Min-heap to track the next available time for each room
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTimes;
        // Min-heap to track available rooms
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        
        // Step 3: Initialize counters for each room
        vector<int> roomUsage(n, 0);

        // Initially, all rooms are available
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        // Step 4: Process each meeting
        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Release all rooms that are free before the current meeting starts
            while (!endTimes.empty() && endTimes.top().first <= start) {
                availableRooms.push(endTimes.top().second);
                endTimes.pop();
            }

            if (!availableRooms.empty()) {
                // Assign the meeting to the earliest available room
                int room = availableRooms.top();
                availableRooms.pop();
                roomUsage[room]++;
                endTimes.push({end, room});
            } else {
                // No room available, assign the meeting to the room that gets free the earliest
                auto earliest = endTimes.top();
                endTimes.pop();
                int room = earliest.second;
                roomUsage[room]++;
                // Extend the end time for this room
                endTimes.push({earliest.first + (end - start), room});
            }
        }

        // Step 5: Find the room with the maximum usage
        int maxUsage = 0;
        int resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomUsage[i] > maxUsage) {
                maxUsage = roomUsage[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
