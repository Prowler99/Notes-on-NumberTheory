#include <iostream>
#include <algorithm>

using namespace std;

// pow(a, n) := a to the power of n
int pow(int a, int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= a;
    }
    return ans;
}

// Solve r^2l^4 + arl^2m^2 + bm^4 = rn^2 mod p
int exists_solution_mod(int a, int b, int r, int p) {
    // return pow(a, p);
    int cnt = 0;
    for (int l = 0; l < p; l++) {
        for (int m = 0; m < p; m++) {
            for (int n = 0; n < p; n++) {
                if (
                    ((r * pow(l, 4)
                    + a * pow(l, 2) * pow(m, 2)
                    + (b / r) * pow(m, 4)
                    - pow(n, 2)) % p
                    == 0) && (__gcd(l, m) == 1)
                ) {
                    cout << "  "
                        << l << " " << m << " " << n << " "
                        << (r * pow(l, 4)
                    + a * pow(l, 2) * pow(m, 2)
                    + (b / r) * pow(m, 4)
                    - pow(n, 2)) << endl;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    // cout << "gcd(0, 0) = " << __gcd(0, 0) << endl;
    int a = 2, b = -23, r = -1, p = 1;
    cout << "Input a and b: ";
    cin >> a >> b;
    while (r) {
        p = 1;
        cout << "Input r that you want to test: \n";
        cin >> r;
        cout << "a, b, r are " << a << " "
            << b << " " << r << endl;
        if (r) {
            if (b % r != 0) cout << "r does not divedes b!\n";
            while (p) {
                cout << "  Input p that you want to test: \n";
                cin >> p;
                if (p) {
                    cout << "There are " << endl
                        << exists_solution_mod(a, b, r, p)
                        << " non-trivial solutions.\n";
                } else cout << "  Stop testing r = " << r << endl;
            }
        } else cout << "End." << endl;
    }
}
