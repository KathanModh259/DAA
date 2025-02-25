#include <bits/stdc++.h>
using namespace std;
int c = 0;

void merge(int arr[], int left, int mid, int right)
{
    c++; // merge function
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        c++; // for loop
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        c++; // for loop
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    // Merge the temp arrays
    while (i < n1 && j < n2)
    {
        c++; // while
        if (L[i] <= R[j])
        {
            c++; // if
            arr[k] = L[i];
            i++;
        }
        else
        {
            c++; // else
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1)
    {
        c++; // while
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2)
    {
        c++; // while
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    c++; // merge sort function
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArray(int arr[], int n)
{
    c++; // print array function
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        c++; // for loop
        cin >> arr[i];
    }

    cout << "Given array is: \n";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array is: \n";
    printArray(arr, n);

    cout << "\nc: " << c;
    return 0;
}