#include <iostream>
using namespace std;

int n, m;
int arr[100][100];

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int num=0, cnt=1;
    for (int i=0; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (arr[i][j] == arr[i][j-1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt >= m) {
                num ++;
                cnt = 1;
                break;
            }
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[j][i] == arr[j][i-1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt >= m) {
                num ++;
                cnt = 1;
                break;
            }
        }
    }

    cout << num;

    return 0;
}