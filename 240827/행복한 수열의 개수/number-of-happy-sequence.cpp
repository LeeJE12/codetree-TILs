#include <iostream>
using namespace std;

int n, m;
int arr[100][100];

int row (int n) {
    int num=0, cnt=1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[i][j] == arr[i][j+1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt >= m) {
                num ++;
                //cout << "row count : " << num << " i : " << i << endl;
                cnt = 1;
                break;
            }
        }
    }
    return num;
}

int column(int n) {
    int num=0, cnt=1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[j][i] == arr[j+1][i]) {
                cnt++;
            } else {
                cnt = 1;
            }
        
            if (cnt >= m) {
                num ++;
                //cout << "column count : " << num << " i : " << i << endl;
                cnt = 1;
                break;
            }
        }
    }
    return num;
}

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int num=0;

    if (n!=1) {
        num+= row(n);
        num+= column(n);
    } else {
        if (m=0) {
            num = 0;
        } else {
            num = 2;
        }
    }


    cout << num;

    return 0;
}