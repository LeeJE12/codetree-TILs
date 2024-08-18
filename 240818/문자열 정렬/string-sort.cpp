#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string st;
    cin >> st;
    sort(st.begin(), st.end());
    cout << st;

    return 0;
}