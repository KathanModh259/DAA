#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int swapCounter = 0;      // Counts the number of swaps
    int operationCounter = 0; // Counts for loops and variable allocations

    // Print the initial array
    cout << "Initial array: ";
    for (int num : arr)
    {
        cout << num << " ";
        operationCounter++; // Counting access to array elements
    }
    cout << endl;

    // Insertion Sort Logic
    for (int i = 1; i < n; i++)
    {
        operationCounter++; // Increment for the outer loop
        int key = arr[i];
        operationCounter++; // Variable allocation for key
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            operationCounter++; // Increment for while condition check
            arr[j + 1] = arr[j];
            swapCounter++; // Increment for a "logical swap"
            j--;
        }
        arr[j + 1] = key;
        swapCounter++; // Increment for placing the key
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
        operationCounter++; // Counting access to array elements
    }
    cout << endl;

    // Display statistics
    cout << "Total swaps: " << swapCounter << endl;
    cout << "Total operations: " << operationCounter << endl;
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    // Print message for the sorting process
    cout << "Starting insertion sort..." << endl;

    insertionSort(arr);

    // Print completion message
    cout << "Sorting completed!" << endl;

    return 0;
}
