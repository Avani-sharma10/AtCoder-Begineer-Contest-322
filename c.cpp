#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    int lst = 0;
    for (int i = 0; i < M; i++) {
        int A;
        std::cin >> A;
        
        for (int x = lst + 1; x <= A; x++) {
            std::cout << A - x << "\n";
        }
        lst = A;
    }
    
    return 0;
}
