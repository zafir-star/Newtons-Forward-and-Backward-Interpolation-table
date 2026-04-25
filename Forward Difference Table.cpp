#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float calculateP(float p, int n) {
    float temp = p;
    for (int i = 1; i < n; i++)
        temp = temp * (p - i);
    return temp;
}

int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n = 4;
    float x[] = { 45, 50, 55, 60 };
    float y[n][n];
    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    cout << "\nFORWARD DIFFERENCE TABLE\n\n";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << setw(4) << y[i][j] << "\t";
        }
        cout << endl;
    }

    float value = 52;
    float sum = y[0][0];
    float p = (value - x[0]) / (x[1] - x[0]);
    
    for (int i = 1; i < n; i++) {
        sum = sum + (calculateP(p, i) * y[0][i]) / factorial(i);
    }

    cout << "\nValue at " << value << " is " << sum << endl;

    return 0;
}