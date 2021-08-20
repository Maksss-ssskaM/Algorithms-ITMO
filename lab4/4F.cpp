#include <iostream>
#include <iomanip>
using namespace std;

double find_b(double *h, int n)
{
    double l = 0;
    double r = h[0];

    while (r - l > 0.0000001)
    {
        h[1] = (l + r) / 2;

        bool up = true;
        for (int i = 2; i < n; i++)
        {
            h[i] = 2 * h[i - 1] - h[i - 2] + 2;
            if (h[i] < 0)
            {
                up = false;
                break;
            }
        }
        if (up)
            r = h[1];
        else
            l = h[1];

    }
    return h[n - 1];

}
int main() {
    freopen("garland.in", "r", stdin); freopen("garland.out", "w", stdout);
    int n;
    cin >> n;

    double *h = new double[n];
    cin >> h[0];

    cout << fixed << setprecision(2) << find_b(h, n);

    return 0;
}
