#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i, j;
    for (j = 39; j >= -39; j--)
    {
        for (i = -35; i <= 35; i++)
        {
            if (((abs(j - 25) < 14 && abs(i) < 6) || (abs(j - 25) == 13 && abs(i) < 10)) || (pow(abs(i) - 9, 2) + 2 * pow(j, 2) <= 100) || (9 * abs(i) - 14 * j - 210 <= 0 && j <= -3) || (pow(i, 2) + 2 * pow(j + 30, 2) <= 225 && pow(i, 2) + 2 * pow(j + 30, 2) >= 64 && j < -29) || (abs(abs(i) - 11.5) < 3.5 && abs(j + 23) < 7))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    {
        char ch;
        char a[20][20]; /* 2D array declaration */

        printf("enter i or I");
        scanf(" %c", &ch); /* read input */
        printf("\n\n\n");  /* for new lines (optional) */
        int i, j, k;
        switch (ch)
        {
        case 'I':
        case 'i':
            for (i = 0; i < 8; i++)
            { /* for every row */
                if (i == 0 || i == 7)
                {                            /* if row is either 1st or last */
                    for (j = 0; j < 11; j++) /* for every column */
                        printf("\x03");      /* print love symbol */
                    printf("\n");
                }
                else
                { /* if row is neither 1st nor last */
                    printf(" \x03\n");
                }
            }
            printf("\n\n\n"); /* after printing I, new lines */

        case 'L':
            for (i = 0; i < 10; i++) /* 1st store love symbol in all element spaces */
            {
                for (j = 0; j < 12; j++)
                {
                    a[i][j] = '\x03';
                }
            }
            for (i = 0; i < 2; i++)  /* replace some of the above symbols with white spaces */
                a[i][5] = ' ';       /* top space */
            for (i = 2; i < 10; i++) /* left spaces */
            {
                for (j = 0; j < i - 1; j++)
                    a[i][j] = ' ';
            }
            for (i = 2; i < 10; i++)
            { /* right spaces */

                for (j = 10; j > 11 - i; j--)
                    a[i][j] = ' ';
            }
            for (i = 0; i < 10; i++)
            { /* print */
                for (j = 0; j < 11; j++)
                    printf("%c", a[i][j]);
                printf("\n");
            }
        case 'U':
            for (i = 0; i < 8; i++)
            {               /* for every row */
                if (i != 7) /* if its not last row */
                    printf("\x03 \x03");
                else
                { /* if its last row */

                    for (j = 0; j < 11; j++)
                        printf("\x03");
                }
                printf("\n");
            }
        }
    }

    {
        float n, i, j, t, s;
        printf("Enter the size of fish\n");
        scanf("%f", &n);
        n = n + 14;
        s = n / 10;
        t = 4.72 / n;
        for (j = floor(s); j >= -ceil(s); j--)
        {
            for (i = 0; i <= 4; i = i + t)
            {
                if ((j < s / 2 && j > s / 4 && i < 1 && i > 0.8 || j == 0 && i < 0.6) || (pow(j / s, 2) >= pow(sin(i), 2)))
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}