#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Parcel {
    int id;
    int weight;
    int profit;
    bool delivered = false;
};

int knapsack(vector<Parcel> &parcels, int capacity, vector<int> &selectedIds) {
    vector<Parcel> available;
    for (const auto& p : parcels) {
        if (!p.delivered) available.push_back(p);
    }

    int n = available.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Standard DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (available[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               available[i - 1].profit + dp[i - 1][w - available[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Traceback to select parcels
    int w = capacity;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            int id = available[i - 1].id;
            selectedIds.push_back(id);
            for (auto& p : parcels) {
                if (p.id == id) {
                    p.delivered = true;
                    break;
                }
            }
            w -= available[i - 1].weight;
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity, n;
    cout << "\nCourier Load Optimization System\n";
    cout << "-----------------------------------------\n";
    cout << "Enter truck capacity (in kg): ";
    cin >> capacity;
    cout << "Enter total number of parcels: ";
    cin >> n;

    vector<Parcel> parcels(n);
    for (int i = 0; i < n; i++) {
        cout << "\nParcel " << i + 1 << ":\n";
        cout << "  Weight (kg): ";
        cin >> parcels[i].weight;
        cout << "  Profit (Rs): ";
        cin >> parcels[i].profit;
        parcels[i].id = i + 1;
    }

    cout << "\nScheduling trips based on capacity & maximizing profit...\n";

    int trip = 1;
    int totalProfit = 0;
    while (true) {
        vector<int> selectedIds;
        int tripProfit = knapsack(parcels, capacity, selectedIds);

        if (selectedIds.empty()) break;

        cout << "\n🚚 --- Trip " << trip++ << " ---\n";
        cout << left << setw(10) << "Parcel" << setw(10) << "Weight" << setw(10) << "Profit" << endl;
        cout << "--------------------------------\n";
        int tripWeight = 0;
        for (int id : selectedIds) {
            for (auto& p : parcels) {
                if (p.id == id) {
                    cout << left << "P" << setw(9) << p.id << setw(10) << p.weight << setw(10) << p.profit << endl;
                    tripWeight += p.weight;
                    totalProfit += p.profit;
                }
            }
        }
        cout << "--------------------------------\n";
        cout << "Total Load: " << tripWeight << " kg | Trip Profit: Rs." << tripProfit << endl;
    }

    cout << "\n✅ All parcels scheduled successfully!";
    cout << "\n Total Profit across all trips: Rs." << totalProfit << "\n";
    cout << "-----------------------------------------\n";

    return 0;
}
