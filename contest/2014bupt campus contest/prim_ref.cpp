#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
bool is_prime[1000005];
bool is_prime_small[50000];
void segment_sieve(ll a, ll b) {
    for (int i = 0; (ll) i * i <= b; i++) is_prime_small[i] = true;
    for (int i = 0; i <= b - a; i++) is_prime[i] = true;

    for (int i = 2; (ll) i * i <= b; i++) {
        if (is_prime_small[i]) {
            for (int j = 2 * i; (ll) j * j <= b; j += i) is_prime_small[j] = false;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j <= b; j += i) is_prime[j - a] = false;
        }
    }
}
int ans[1000000];
int main() {
    int t;
    cin >> t;
    ll a, b;

    while(t--) {
        cin >> a >> b;
        segment_sieve(a, b);
        int k = 0;
        for (int i = 0; i <= b - a; i++) {
            if (is_prime[i]) {
                if (a + i == 1) continue;
                ans[k++] = a + i;
            }
        }
        if (k < 3) puts("-1");
        else {
            int maxs = -1, mini = 2100000000;
            int max_left, max_right, mini_left, mini_right;
            for (int i = 1; i < k; i++) {
                if (ans[i] - ans[i - 1] > maxs) {
                    maxs = ans[i] - ans[i - 1];
                    max_left = ans[i - 1];
                    max_right = ans[i];
                }
                if (ans[i] - ans[i - 1] < mini) {
                    mini = ans[i] - ans[i - 1];
                    mini_left = ans[i - 1];
                    mini_right = ans[i];
                }
            }
            printf("%d %d %d %d\n", mini_left, mini_right, max_left, max_right);
        }

    }
}
