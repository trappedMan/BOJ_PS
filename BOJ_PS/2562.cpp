#include <iostream>
using namespace std;

int main() {
    int num[9];
    for (int i = 0; i < 9; i++) {
        cin >> num[i];
    }
    int max = num[0];
    int index = 0;
    for (int i = 1; i < 9; i++) {
        if (max < num[i]) {
            max = num[i];
            index = i;
        }
    }
    cout << max << '\n';
    cout << index << '\n';
    return 0;
}