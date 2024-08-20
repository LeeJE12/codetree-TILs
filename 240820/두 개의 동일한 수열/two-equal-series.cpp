#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int n;

int main() {
    cin >> n;
    int A[n], B[n];

    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    for(int i=0; i<n; i++) {
        cin >> B[i];
    }

    sort(A, A+n);
    sort(B, B+n);

    for(int i=0; i<n; i++) {
        if (A[i] == B[i]) {
            continue;
        } else {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}