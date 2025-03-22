# Courier Load Optimization System 🚚 (Using DSA Algorithm)

This project is a CLI-based C++ application that optimizes the loading of parcels into a courier truck using the **0/1 Knapsack Algorithm** from **DSA (Data Structures & Algorithms)**. The system schedules parcels into multiple trips based on truck capacity while maximizing profit.

## Features

- Implements dynamic programming for solving the Knapsack problem.
- Automatically schedules multiple trips based on remaining parcels.
- Maximizes total profit across all trips.
- Simple and user-friendly command-line interface.

## How It Works

1. Input truck capacity and parcel details (weight and profit).
2. The system runs the knapsack algorithm for each trip.
3. Parcels selected in each trip are marked as delivered.
4. The system repeats until all parcels are scheduled.

## Sample Output

```cli
Courier Load Optimization System
-----------------------------------------
Enter truck capacity (in kg): 10
Enter total number of parcels: 4

Parcel 1:
  Weight (kg): 5
  Profit (Rs): 60

Parcel 2:
  Weight (kg): 4
  Profit (Rs): 40

Parcel 3:
  Weight (kg): 6
  Profit (Rs): 50

Parcel 4:
  Weight (kg): 3
  Profit (Rs): 30

Scheduling trips based on capacity & maximizing profit...

🚚 --- Trip 1 ---
Parcel    Weight    Profit
--------------------------------
P1        5         60
P4        3         30
--------------------------------
Total Load: 8 kg | Trip Profit: Rs.90

🚚 --- Trip 2 ---
Parcel    Weight    Profit
--------------------------------
P2        4         40
P3        6         50
--------------------------------
Total Load: 10 kg | Trip Profit: Rs.90

✅ All parcels scheduled successfully!
Total Profit across all trips: Rs.180
-----------------------------------------
