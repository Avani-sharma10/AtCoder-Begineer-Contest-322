#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;
    
    int ans = S.find("ABC");
    if (ans >= 0) {
        ans += 1;
    }
    std::cout << ans << "\n";
    
    return 0;
}
