#include <iostream>

using namespace std;

// Function to calculate (x * y) % m
long long multiplyMod(long long x, long long y, long long m) {
    long long result = 0;
    x %= m;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result + x) % m;
        }
        x = (x * 2) % m;
        y /= 2;
    }
    return result;
}

// Function to calculate A^k % m using divide and conquer
long long powerMod(long long A, long long k, long long m) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 0) {
        long long temp = powerMod(A, k / 2, m);
        return multiplyMod(temp, temp, m) % m;
    } else {
        return (A * powerMod(A, k - 1, m)) % m;
    }
}

int main() {
    long long A = 7;
    long long k = 13;
    long long m = 1000000007;

    long long result = powerMod(A, k, m);

    cout << A << "^" << k << " % " << m << " = " << result << endl;

    return 0;
    //answer is 889009735
}
