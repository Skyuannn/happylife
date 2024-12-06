#include <iostream>
using namespace std;

int main() {
    int a = 2;
    int b = 3;
    int e = 3;
    int c = a + (--b);
    int d = a + (e--);
    cout << c << d << endl;
    return 0;
}