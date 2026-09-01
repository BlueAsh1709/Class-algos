#include <iostream>
using namespace std;

void binSort(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int bin[100] = {0};

    for (int i = 0; i < n; i++) {
        bin[arr[i]]++;
    }

    int k = 0;

    for (int i = 0; i <= max; i++) {
        while (bin[i] > 0) {
            arr[k] = i;
            k++;
            bin[i]--;
        }
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

    binSort(arr, n);

    cout << "\nSorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

    return 0;
}