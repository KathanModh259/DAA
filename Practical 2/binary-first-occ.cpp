#include <bits/stdc++.h>
using namespace std;

int counter = 0; // Counts only the number of iterations

int main()
{
N:
    int n;
    cout << "Enter Length of array: ";
    cin >> n;

    vector<int> arr1(n); // Dynamic array
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i];
        if (i != n - 1)
            cout << ",";
    }
    cout << "]";

    cout << "\nWhich number you want to search: ";
    int key, mid;
    cin >> key;

    int low = 0, high = n - 1, ans = -1;

    // Binary search for the first occurrence
    while (low <= high)
    {
        counter++; // Increment for each iteration of the binary search loop
        mid = (high + low) / 2;

        if (arr1[mid] == key)
        {
            ans = mid;
            break; // Exit immediately for the best case
        }
        else if (arr1[mid] < key)
        {
            low = mid + 1; // Update low
        }
        else
        {
            high = mid - 1; // Update high
        }
    }

    if (ans != -1)
        cout << endl
            << key << " is first occurring on \"" << ans << "\" INDEX";
    else
        cout<< endl
             << key << " is on \"" << -1 << "\" INDEX";

    cout << endl
         << "Counter value: " << counter;
    goto N ;
     return 0;
}
