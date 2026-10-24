//Towers of Hanoi
#include <iostream>
using namespace std;
void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, source, destination, auxiliary);       //moving from src to aux

    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    hanoi(n - 1, auxiliary, source, destination);      //moving from aux to dest
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    if (n < 1) {
        cout << "Number of disks must be at least 1." << endl;
        return 1;
    }

    hanoi(n, 'A', 'B', 'C');

    return 0;
}