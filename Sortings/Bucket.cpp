#include <iostream>
using namespace std;

void bucketSort(int arr[], int n) {
    int bucket[10][10] = {0};
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    int k = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {

            for (int x = j + 1; x < count[i]; x++) {
                if (bucket[i][j] > bucket[i][x]) {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][x];
                    bucket[i][x] = temp;
                }
            }

            arr[k] = bucket[i][j];
            k++;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements (0-99): ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

    bucketSort(arr, n);

    cout << "\nSorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

    return 0;
}