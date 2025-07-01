#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int obr(int a, int p)
{
    int fi, alfa, i;
    fi = p - 1;
    a = a % fi;
    if (a < 0)
    {
        a = a + fi;
    }

    for (i = 1; i <= fi - 1; i++)
        if ((i * a) % fi == 1)
        {
            alfa = i;
            return alfa;
        }
    return -1; 
}

int main()
{
    const int n = 20;
    int i, j, m;
    int m1, m2, m3, m4;
    int mas1[n+1], mas2[n+1], mas3[n+1], mas4[n+1];
    int S, S1, p1, p2, a1, a2, alfa1, alfa2;

    char mas[n+1] = "Sidorov-Petrov!";
    a1 = 5; 
    a2 = 13;
    p1 = 823;
    p2 = 967;
    alfa1 = obr(a1, p1);
    alfa2 = obr(a2, p2);
    
    for (i = 0; i <= n; i++)
    {
        printf("%d %c \n", mas[i], mas[i]);
    }
    
    for (j = 0; j <= n; j++)
    {
        m = mas[j];
       
        if (p1 < p2)
        {
            m1 = 1;
            for (i = 1; i <= a1; i++)
            {
                m1 = (m1 * m) % p1;
            }
            mas1[j] = m1;
            
            m2 = 1;
            for (i = 1; i <= alfa2; i++)
            {
                m2 = (m2 * m1) % p2;
            }
            mas2[j] = m2;
            
            m3 = 1;
            for (i = 1; i <= a2; i++)
            {
                m3 = (m3 * m2) % p2;
            }
            mas3[j] = m3;
            
            m4 = 1;
            for (i = 1; i <= alfa1; i++)
            {
                m4 = (m4 * m3) % p1;
            }
            mas4[j] = m4;
        }
        else
        {
           
            mas4[j] = m;
        }
    }
    
    for (j = 0; j <= n; j++)
    {
        printf("%c %c\n", mas[j], mas4[j]);
    }
    printf("alfa1=%d alfa2=%d \n", alfa1, alfa2);
       
}