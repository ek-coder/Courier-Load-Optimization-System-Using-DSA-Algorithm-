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
