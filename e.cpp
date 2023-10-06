#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K, P;
    std::cin >> N >> K >> P;
    
    std::vector<int> pw(K + 1);
    pw[0] = 1;
    for (int i = 1; i <= K; i++) {
        pw[i] = pw[i - 1] * (P + 1);
    }
    
    std::vector dp(pw[K], -1LL);
    dp[0] = 0;
    
    for (int i = 0; i < N; i++) {
        int C;
        std::cin >> C;
        
        std::vector<int> A(K);
        for (int j = 0; j < K; j++) {
            std::cin >> A[j];
        }
        
        for (int s = pw[K] - 1; s >= 0; s--) {
            int t = 0;
            for (int j = 0; j < K; j++) {
                int a = s / pw[j] % (P + 1);
                int na = std::min(P, a + A[j]);
                t += na * pw[j];
            }
            if (dp[s] != -1 && (dp[t] == -1 || dp[t] > dp[s] + C)) {
                dp[t] = dp[s] + C;
            }
        }
    }
    std::cout << dp.back() << "\n";
    
    return 0;
}
