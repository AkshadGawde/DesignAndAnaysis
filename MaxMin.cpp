#include <iostream>
#include <climits>
using namespace std;

pair<int, int> findMinMax(int arr[], int low, int high)
{
    if (low == high)
    {
        return {arr[low], arr[low]};
    }

    if (high - low == 1)
    {
        return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    }

    int mid = (low + high) / 2;
    pair<int, int> left = findMinMax(arr, low, mid);
    pair<int, int> right = findMinMax(arr, mid + 1, high);

    return {min(left.first, right.first), max(left.second, right.second)};
}

int main()
{
    int arr[] = {3, 6, 1, 8, 4, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    pair<int, int> minMax = findMinMax(arr, 0, n - 1);
    cout << "Minimum element: " << minMax.first << endl;
    cout << "Maximum element: " << minMax.second << endl;
    return 0;
}
