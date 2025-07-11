#include<iostream>
#include<algorithm>
using namespace std;

// Function to check if cows can be placed with at least 'dist' distance
bool canPlaceCows(int stalls[], int n, int cows, int dist) {
    int count = 1; // Place first cow at first stall
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if(count == cows) return true; // Placed all cows
    }
    return false; // Couldn't place all cows
}

// Function to find the largest minimum distance
int aggressiveCows(int stalls[], int n, int cows) {
    sort(stalls, stalls + n); // Sort the stall positions

    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlaceCows(stalls, n, cows, mid)) {
            result = mid;       // Possible answer, try for more
            low = mid + 1;
        } else {
            high = mid - 1;     // Try smaller distance
        }
    }
    return result;
}

int main() {
    int stalls[] = {1, 2, 4, 8, 9}; // Stall positions
    int n = sizeof(stalls)/sizeof(stalls[0]);
    int cows = 3;

    int maxMinDist = aggressiveCows(stalls, n, cows);
    cout << "Maximum minimum distance: " << maxMinDist << endl;

    return 0;
}
