#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    std::string S, T;
    std::cin >> S >> T;
    
    int ans = 2 * (T.substr(0, N) != S) + (T.substr(M - N) != S);
    std::cout << ans << "\n";
    
    return 0;
}
