#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortVector(vector<int>& list) {
    sort(list.begin(), list.end());

    cout << "Sorted list: ";
    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

