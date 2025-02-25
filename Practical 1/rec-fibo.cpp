#include <bits/stdc++.h>
using namespace std;

int operationCount = 0; // Global counter to track the number of operations

// Recursive function to calculate the nth Fibonacci number
int nthFibonacci(int n)
{
    operationCount++; // Count function call

    // Base case: if n is 0 or 1, return n
    if (n <= 1)
    {
        operationCount++; // Count condition check
        return n;
    }

    // Recursive case: sum of the two preceding Fibonacci numbers
    operationCount++; // Count addition operation
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

// Function to print the Fibonacci series up to nth term
void printFibonacciSeries(int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << nthFibonacci(i) << " "; // Print Fibonacci number
        operationCount++;               // Count the loop iteration
    }
    cout << endl;
}

int main()
{
    int n =16;        // Set the limit for the Fibonacci series
    operationCount++; // Count variable initialization

    cout << "Fibonacci series up to " << n << ": ";
    operationCount++; // Count message print
    printFibonacciSeries(n);
    operationCount++;
    operationCount++;

    cout << "Number of operations: " << operationCount << endl; // Print operation count
     // Count message print

    return 0;
}
