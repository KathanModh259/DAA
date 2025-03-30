#include <iostream>
#include <vector>
using namespace std;

int maxVal = 0;

// Backtracking function
void knapsackBacktrack(vector<int> &wt, vector<int> &val, int W, int index, int currVal, int currWt)
{
    if (currWt > W)
        return;
    if (index == wt.size())
    {
        maxVal = max(maxVal, currVal);
        return;
    }

    // Include the current item
    knapsackBacktrack(wt, val, W, index + 1, currVal + val[index], currWt + wt[index]);

    // Exclude the current item
    knapsackBacktrack(wt, val, W, index + 1, currVal, currWt);
}

int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    knapsackBacktrack(weights, values, capacity, 0, 0, 0);
    cout << "Maximum sponsorship value (Backtracking): " << maxVal << endl;
    return 0;
}
