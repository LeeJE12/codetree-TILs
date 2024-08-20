#include <iostream>
using namespace std;

int N;

void printer(int N) {
    if (N==0) {
        return;
    }
    
    cout << "HelloWorld" << endl;
    printer(N-1);
}

int main() {
    cin >> N;
    printer(N);
    return 0;
}