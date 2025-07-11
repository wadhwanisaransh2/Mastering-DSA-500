#include<iostream>
using namespace std;

// Function to check if we can allocate boards to painters with maxTime limit
bool isPossible(int boards[], int n, int k, int maxTime) {
    int painterCount = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return false; // Can't paint this board in maxTime

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painterCount++;
            currTime = boards[i];

            if (painterCount > k) return false;
        }
    }

    return true;
}

// Main function to find minimum time
int painterPartition(int boards[], int n, int k) {
    int sum = 0, maxBoard = 0;
    for (int i = 0; i < n; i++) {
        sum += boards[i];
        maxBoard = max(maxBoard, boards[i]);
    }

    int low = maxBoard, high = sum, result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;        // Try to minimize the time
            high = mid - 1;
        } else {
            low = mid + 1;       // Increase time limit
        }
    }

    return result;
}

int main() {
    int boards[] = {10, 20, 30, 40};  // Board lengths
    int n = sizeof(boards)/sizeof(boards[0]);
    int painters = 2;

    int minTime = painterPartition(boards, n, painters);
    cout << "Minimum time to paint all boards: " << minTime << endl;

    return 0;
}
