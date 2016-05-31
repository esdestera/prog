#include <stdio.h>
int main()
{
    float c[9], g[9], ef[9], gr, man, castig = 0; int n, i, man1, inv, ordine[9];
    printf("Capacitate rucsac: ");
    scanf("%f",&gr);
    printf("\nNumar obiecte: ");
    scanf("%d",&n);
    for( i = 1; i <= n; ++i )
        {
            ordine[i] = i;
            printf("\ngreutate obiect %d = ", i);
            scanf("%f",&g[i]);
            printf("  castig obiect %d = ", i);
            scanf("%f",&c[i]);
            ef[i] = c[i] / g[i]; /*calculam eficienta fiecarui obiect*/
        }
    /* sortam obiectele descrescator dupa eficiența de transport */
do
{
    inv = 0;
    for ( i = 1; i < n; ++i)
    if ( ef[i] < ef[i + 1] )
    { /* interschimbam eficientele obiectelor */
        man = ef[i], ef[i] = ef[i + 1], ef[i + 1] = man; /* interschimbam castigurile obiectelor */
        man = c[i], c[i] = c[i + 1], c[i + 1] = man; /* interschimbam greutatile obiectelor */
        man = g[i], g[i] = g[i + 1], g[i + 1] = man; /* interschimbam ordinea obiectelor */
        man1=ordine[i],ordine[i]=ordine[i+1],ordine[i+1]=man1; inv = 1;
    }
} while(inv);

    i = 1;                      /* cat timp nu am umplut rucsacul (gr > 0) si mai exista obiecte */
    while ( gr > 0 && i <= n)
    {                           /* obiectul i este incarcat intreg in rucsac */
        if ( gr > g[i] )
        {
            printf("\n obiectul %d: 1 \n", ordine[i]);  /* scad capacitatea rucsacului cu greutatea incarcata deja */
            gr -= g[i];                     /* cresc castigul cu castigul obiectului plasat in rucsac */
            castig += c[i];
        }
        else
            {                   /* daca nu pot incarca tot obiectul dar mai am inca loc */
                printf(" obiectul %d: %.2f \n", ordine[i], gr/g[i]);
                                /* plasez o fractiune gr/g[i] din obiect in rucsac */
                castig += c[i] * (gr/g[i]);
                gr = 0;         /* rucsac plin, capacitate 0 */
            }
        ++i;
    }
    printf("\ncastig total = %.3f", castig);
    return 0;
}

