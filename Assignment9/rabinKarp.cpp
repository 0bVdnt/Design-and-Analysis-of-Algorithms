#include <iostream>
using namespace std;

void rabinKarp(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    int d = 256, q = 101;
    int p = 0, t = 0, h = 1;

    // h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && text.substr(i, m) == pattern)
            cout << "Pattern found at index " << i << endl;

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    rabinKarp("ababcabcabababd", "ababd");
    return 0;
}
