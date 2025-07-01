#include <stdio.h>
#include <math.h>

int abc(int m, int p) {
    m = m % p;
    if (m < 0) m += p;

    for (int i = 1; i < p; i++) {
        if ((i * m) % p == 1)
            return i;
    }

    return -1; 
}

const int p = 257, n = 30;

int main() {
    int i, j, mas1[2][n + 1], mas2[n + 1];
    int a11, a12, a21, a22, x, y, f1, f2, s, k, s1, s2, s3;
    char mas[n + 1] = "Polotsk State University";

    a11 = 3; a12 = 5; a21 = 7; a22 = 11;

    for (i = 0; i <= n; i++) {
        printf("%d %c\n", mas[i], mas[i]);
    }

    s = (a11 * a22 - a12 * a21) % p;
    if (s < 0) {
        s = s + p;
    }

    if (s == 0) {
        printf("take new key\n");
    } else {
        printf("s=%d\n", s);
    }

    for (j = 0; j <= n; j++) {
        k = int(j / 2);

        if (j % 2 == 0) {
            x = mas[j];
        }

        if (j % 2 == 1) {
            y = mas[j];

            f1 = (a11 * x + a12 * y) % p;
            f2 = (a21 * x + a22 * y) % p;

            mas1[0][k] = f1;
            mas1[1][k] = f2;
        }
    }


    s1 = abc(s, p);


    for (k = 0; k <= n / 2; k++) {
        f1 = mas1[0][k];
        f2 = mas1[1][k];

        s2 = (f1 * a22 - f2 * a12) % p;
        if (s2 < 0) s2 += p;

        s3 = (f2 * a11 - f1 * a21) % p;
        if (s3 < 0) s3 += p;

        x = (s2 * s1) % p;
        y = (s3 * s1) % p;

        mas2[2 * k] = x;
        mas2[2 * k + 1] = y;
    }

    for (i = 0; i <= n; i++) {
        printf("%c %c\n", mas[i], mas2[i]);
    }

    return 0;
}