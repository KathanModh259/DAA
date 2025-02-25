#include <bits/stdc++.h>
using namespace std;

int mergeCount = 0, quickCount = 0;

// Merge Sort Implementation
void merge(int arr[], int left, int mid, int right)
{
    mergeCount++;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
        mergeCount++;
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
        mergeCount++;
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        mergeCount++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
        mergeCount++;
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
        mergeCount++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    mergeCount++;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Quick Sort Implementation
int partition(int arr[], int low, int high)
{
    quickCount++;
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        quickCount++;
        if (arr[j] < pivot)
        {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        quickCount++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], arr2[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    cout << "\nOriginal array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);
    cout << "\nSorted array using Merge Sort: ";
    printArray(arr, n);
    cout << "Merge Sort Operation Count: " << mergeCount << endl;

    quickSort(arr2, 0, n - 1);
    cout << "\nSorted array using Quick Sort: ";
    printArray(arr2, n);
    cout << "Quick Sort Operation Count: " << quickCount << endl;

    return 0;
}
