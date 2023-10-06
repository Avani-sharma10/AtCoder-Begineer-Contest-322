#include <bits/stdc++.h>

using i64 = long long;

void rotate(auto &s) {
    std::array<std::string, 4> t;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            t[3 - j] += s[i][j];
        }
    }
    s = t;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::array<std::string, 4> a, b, c;
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < 4; i++) {
        std::cin >> c[i];
    }
    
    for (int da = 0; da < 4; da++) {
        for (int db = 0; db < 4; db++) {
            for (int dc = 0; dc < 4; dc++) {
                for (int dxa = -3; dxa <= 3; dxa++) {
                    for (int dya = -3; dya <= 3; dya++) {
                        for (int dxb = -3; dxb <= 3; dxb++) {
                            for (int dyb = -3; dyb <= 3; dyb++) {
                                for (int dxc = -3; dxc <= 3; dxc++) {
                                    for (int dyc = -3; dyc <= 3; dyc++) {
                                        std::array<std::string, 4> s;
                                        bool ok = true;
                                        auto cover = [&](auto &a, int dx, int dy) {
                                            for (int i = 0; i < 4; i++) {
                                                for (int j = 0; j < 4; j++) {
                                                    int x = i + dx;
                                                    int y = j + dy;
                                                    if (a[i][j] == '#') {
                                                        if (x < 0 || x >= 4 || y < 0 || y >= 4 || s[x][y] == '#') {
                                                            ok = false;
                                                        } else {
                                                            s[x][y] = '#';
                                                        }
                                                    }
                                                }
                                            }
                                        };
                                        s.fill("....");
                                        cover(a, dxa, dya);
                                        cover(b, dxb, dyb);
                                        cover(c, dxc, dyc);
                                        for (int i = 0; i < 4; i++) {
                                            if (s[i] != "####") {
                                                ok = false;
                                            }
                                        }
                                        if (ok) {
                                            std::cout << "Yes\n";
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                rotate(c);
            }
            rotate(b);
        }
        rotate(a);
    }
    std::cout << "No\n";
    
    return 0;
}
