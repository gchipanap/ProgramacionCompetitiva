/*
1. Growling Gears
https://open.kattis.com/problems/growlinggears
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int k;
        scanf("%d",&k);

        double max = -INFINITY;
        int max_i = 0;

        for (int i = 1; i <= k; i++)
        {

            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            double der = (double)b/(a<<1);
            double val = -a * der * der + b * der + c;

            if (val > max)
            {
                max = val;
                max_i = i;
            }
        }

        printf("%d\n", max_i);
    }
    return 0;
}