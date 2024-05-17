#include "libft.h"

void	*ft_calloc(size_t count, size_t size) // 2 argumentso: la cantidad de elementos y el tamañao de cada elemento respectivamente.
{
	size_t	b;
	void	*p; // puntero para apuntar al bloque de memoria asignado. 

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	b = count * size; // el tamaño total de b = multiplicando el númeor de elementos por su tamaño. 
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, b);
	return (p);
}
// Test (borrar)
int main(void)
{
    int *array;
    int n;
    int i;

    // Definir el número de elementos del arreglo
    n = 5;

    // Usar ft_calloc para asignar memoria para el arreglo
    array = (int *)ft_calloc(n, sizeof(int));

    // Comprobar si ft_calloc retornó NULL
    if (!array)
    {
        printf("La asignación de memoria falló.\n");
        return (1);
    }

    // Imprimir los valores del arreglo para verificar que se inicializaron a cero
    printf("Valores del arreglo después de usar ft_calloc:\n");
    i = 0;
    while(i < n)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    // Liberar la memoria asignada
    free(array);

    return (0);
}
