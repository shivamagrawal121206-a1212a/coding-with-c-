#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 4; i++) {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < 4; i++) {
        cout << "Index is: " << i
             << " Value is: " << arr[i] << endl;
    }

    return 0;
}