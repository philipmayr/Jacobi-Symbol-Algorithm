// Compute Jacobi Symbol

#include <stdio.h>
#include <math.h>

int compute_Jacobi_symbol(int m, int n)
{
    m %= n;
    if (m == 0) return 0;
    
    int j = 1; 
    int t = 0;
    
    while (m % 2 == 0)
    {
        m /= 2;
        t += 1;
    }
    
    if ((n == 3 % 8 || n == -3 % 8) && t % 2 != 2)
    {
        j = -1;
    }
    
    if (m == 1) return j;
    else return j * (pow(-1, ((m - 1) * ((n - 1) / 4)))) * compute_Jacobi_symbol(n, m);
    
    return 0;
}

int main()
{
    int n, m;
    
    printf("Enter Jacobi symbol numerator: ");
    scanf("%d", &n);
    
    printf("Enter Jacobi symbol denominator: ");
    scanf("%d", &m);
    
    printf("\n");
    
    if (compute_Jacobi_symbol(m, n)) printf("%d is a quadradic residue modulo %d", n, m);
    else printf("%d is a quadradic nonresidue modulo %d", n, m);

    return 0;
}
