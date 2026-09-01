#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {

    while (low <= high) {

        int pos = partition(arr, low, high);

        if (pos == k - 1)
            return arr[pos];

        if (pos > k - 1)
            high = pos - 1;

        else
            low = pos + 1;
    }

    return -1;
}

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid k";
        return 0;
    }

    cout << "Kth smallest element: "
         << kthSmallest(arr, 0, n - 1, k);

    return 0;
}