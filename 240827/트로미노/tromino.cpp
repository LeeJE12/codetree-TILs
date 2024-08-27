#include <iostream>
using namespace std;

int n, m;
int arr[200][200];

//◤
int block1(int n, int m) {
    int max = 0;
    int sum = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            sum = arr[i][j] + arr[i+1][j] + arr[i][j+1];
            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

//◥
int block2(int n, int m) {
    int max = 0;
    int sum = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=1; j<m; j++) {
            sum = arr[i][j] + arr[i][j-1] + arr[i+1][j];
            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

//◣
int block3(int n, int m) {
    int max = 0;
    int sum = 0;

    for (int i=1; i<n; i++) {
        for (int j=0; j<m-1; j++) {
            sum = arr[i][j] + arr[i-1][j] + arr[i][j+1];
            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

//◢
int block4(int n, int m) {
    int max = 0;
    int sum = 0;

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            sum = arr[i][j] + arr[i-1][j] + arr[i][j-1];
            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

// ㅡ
int block5(int n, int m) {
    int max = 0;
    int sum = 0;

    for (int i=0; i<n; i++) {
        for (int j=1; j<m-1; j++) {
            sum = arr[i][j] + arr[i][j-1] + arr[i][j+1];
            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

// |
int block6(int n, int m) {
    int max = 0;
    int sum = 0;

    for (int i=1; i<n-1; i++) {
        for (int j=0; j<m; j++) {
            sum = arr[i][j] + arr[i-1][j] + arr[i+1][j];
            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int max = block1(n, m);
    if (max < block2(n,m)){
        max = block2(n,m);
    }

    if (max < block3(n,m)) {
        max = block3(n,m);
    }

    if (max < block4(n,m)) {
        max = block4(n,m);
    }

    if (max < block5(n,m)) {
        max = block5(n,m);
    }

    if (max < block6(n,m)) {
        max = block6(n,m);
    }

    cout << max;

    return 0;
}