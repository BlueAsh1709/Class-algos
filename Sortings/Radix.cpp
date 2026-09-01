#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int place) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int place = 1; max / place > 0; place = place * 10) {
        countingSort(arr, n, place);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

    radixSort(arr, n);

    cout << "\nSorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

    return 0;
}