#include <iostream>
#include <omp.h>

#define N 100
#define chunk 10
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Ejecución 1: Parámetros relativamente pequeños\n";
    float a[N], b[N], c[N];
    int i;
    
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10; // Cambiar patrón para variar los resultados
        b[i] = (i + 3) * 3.7;
    }
    int pedazos = chunk;
    
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    
    for(i = 0; i < N; i++)
       c[i] = a[i] + b[i];
    
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}