#include <iostream>
using namespace std;

int main()
{
    int n, key, counter = 0;

    // Input: Array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    counter++; // Increment for array size input

    int arr[n];
    counter++; // Increment for array creation

    // Input: Array elements
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        counter++; // Increment for each array assignment
    }

    // Input: Element to search
    cout << "Enter the element to search: ";
    cin >> key;
    counter++; // Increment for key assignment

    // Linear Search
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        counter++; // Increment for each loop iteration
        if (arr[i] == key)
        {
            counter++; // Increment for comparison
            result = i;
            counter++; // Increment for assignment
            break;
        }
        counter++; // Increment for comparison when key is not found
    }

    // Output the result
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    // Output the total counter value
    cout << "Total operations (assignments, comparisons, iterations): " << counter << endl;

    return 0;
}
