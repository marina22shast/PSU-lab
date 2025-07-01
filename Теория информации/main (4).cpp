#include <iostream>
#include <vector>
#include <string>

constexpr int64_t n = 599, p = 257;
constexpr int64_t a = 119, b = 131;

void f1(int64_t x, int64_t y, int64_t& z2) {
    int64_t z0 = 0, d = 1, zz = -1;

    for (int i = 1; i <= b; i++)
        d = (d * a) % p;

    for (int i = 0; i < n; i++) {
        int64_t z1 = 1, z = 1;
        for (int j = 1; j <= i; j++) z = (z * x) % p;
        for (int j = 1; j <= n - i - 1; j++) z1 = (z1 * y) % p;
        zz = -zz;
        z0 = (z0 + z * z1 * zz) % p;
    }

    z2 = (z0 * d) % p;
    if (z2 < 0) z2 += p;
}

int64_t modInverse(int64_t t) {
    for (int64_t i = 1; i < p; i++)
        if ((i * t) % p == 1) return i;
    return 1;
}

int64_t f2(int64_t x, int64_t y) {
    int64_t d = 1;

    for (int i = 1; i <= b; i++)
        d = (d * a) % p;

    int64_t z1 = 1, z2 = 1;
    for (int i = 1; i <= n; i++) {
        z1 = (z1 * x) % p;
        z2 = (z2 * y) % p;
    }

    int64_t z00 = (z2 + z1) % p;
    if (z00 < 0) z00 += p;

    return (z00 * d) % p;
}

int main() {
    std::string s = "Polotsk State University 1234567890";
    size_t len = s.size();
    std::vector<int64_t> mas(len), mas1(len, 0), mas2(len, 0), mas3(len, 0);

    for (size_t i = 0; i < len; i++) {
        mas[i] = static_cast<int64_t>(s[i]);
        std::cout << s[i] << " " << mas[i] << std::endl;
    }

    int64_t x = 1;
    for (size_t i = 0; i < len; i++) {
        int64_t y = mas[i], z2;
        f1(x, y, z2);

        if (z2 == 0) {
            int64_t z1 = (x + y) % p;
            int64_t z2 = (y - x) % p;
            int64_t z3 = modInverse(2);
            mas1[i] = ((z1 + z2) * z3) % p;
        } else {
            int64_t z3 = modInverse(z2);
            int64_t z4 = ((z3 * f2(x, y)) - x) % p;
            if (z4 < 0) z4 += p;
            mas2[i] = z4;
        }

        mas3[i] = mas1[i] + mas2[i];
        std::cout << "i=" << i + 1 << ", " << mas3[i] << ", " << static_cast<char>(mas3[i]) << std::endl;
    }

    return 0;
}
