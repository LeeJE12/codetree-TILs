#include <iostream>
using namespace std;

int t, n;
int arr[200];

int main() {
    cin >> n >> t;
    for(int i=1; i<=2*n; i++) {
        cin >> arr[i];
    }
    
    int temp;
    for(int i=0; i<t; i++) {
        temp = arr[2*n-1];
        for(int j=2*n; j >= 1; j--) {
            arr[j] = arr[j-1];
        }
        arr[1] = temp;
    }

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl; 
    for (int i=n+1; i<=2*n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}