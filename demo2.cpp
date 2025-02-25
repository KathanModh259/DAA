#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    set<int> nums;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        nums.insert(arr[i]);
    }

    vector<int> missing;
    for (int i = 1; i <= n; i++) {
        if (nums.find(i) == nums.end()) {
            missing.push_back(i);
        }
    }

    if (missing.empty()) {
        cout << -1;
    } else {
        for (int num : missing) {
            cout << num << " ";
        }
    }

    return 0;
}
