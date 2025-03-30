#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure for a node in Branch & Bound
struct Node
{
    int level, profit, weight;
    float bound;
};

// Comparison function for priority queue
struct Compare
{
    bool operator()(Node const &a, Node const &b)
    {
        return a.bound < b.bound;
    }
};

// Function to calculate upper bound
float bound(Node u, int W, vector<int> &wt, vector<int> &val, int n)
{
    if (u.weight >= W)
        return 0;

    float profitBound = u.profit;
    int j = u.level + 1, totalWeight = u.weight;

    while (j < n && totalWeight + wt[j] <= W)
    {
        totalWeight += wt[j];
        profitBound += val[j];
        j++;
    }

    if (j < n)
        profitBound += (W - totalWeight) * (float)val[j] / wt[j];

    return profitBound;
}

// Branch and Bound solution for 0/1 Knapsack
int knapsackBnB(int W, vector<int> &wt, vector<int> &val, int n)
{
    priority_queue<Node, vector<Node>, Compare> pq;
    Node u, v;

    v.level = -1;
    v.profit = v.weight = 0;
    v.bound = bound(v, W, wt, val, n);
    pq.push(v);

    int maxProfit = 0;

    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();

        if (v.bound > maxProfit)
        {
            u.level = v.level + 1;
            u.weight = v.weight + wt[u.level];
            u.profit = v.profit + val[u.level];

            if (u.weight <= W && u.profit > maxProfit)
                maxProfit = u.profit;

            u.bound = bound(u, W, wt, val, n);
            if (u.bound > maxProfit)
                pq.push(u);

            u.weight = v.weight;
            u.profit = v.profit;
            u.bound = bound(u, W, wt, val, n);

            if (u.bound > maxProfit)
                pq.push(u);
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    cout << "Maximum sponsorship value (Branch & Bound): " << knapsackBnB(capacity, weights, values, values.size()) << endl;
    return 0;
}
