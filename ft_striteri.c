#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*)) // Toma dos parámetros:
// char *s: Un puntero a una cadena de caracteres.
// void (*f)(unsigned int, char*): Un puntero a una función que no devuelve ningún valor (void) y toma dos parámetros: un unsigned int y un puntero a un carácter (char*).
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
// Test (borrar)
void print_char(unsigned int i, char *c)
{
    printf("Índice %u: Carácter %c\n", i, *c);
}

int main(void)
{
    char str[] = "Hola, mundo!";

    // Llamamos a ft_striteri con la cadena 'str' y la función 'print_char'.
    ft_striteri(str, print_char);
    return (0);
}

// La diferencia principal entre las funciones ft_striteri y ft_strmapi en C es cómo manejan la cadena de caracteres y qué devuelven:

// ft_striteri: Esta función toma una cadena de caracteres s y aplica una función f a cada carácter de la cadena. La función f recibe el índice del carácter y un puntero al carácter, permitiendo modificar directamente el carácter en la cadena originalft_striteri no devuelve nada; su propósito es realizar operaciones en la cadena original1.
// ft_strmapi: Similar a ft_striteri, ft_strmapi también aplica una función a cada carácter de una cadena. Sin embargo, en lugar de modificar la cadena original, ft_strmapi crea una nueva cadena con los resultados de aplicar la función f a cada carácter de la cadena original. La función f recibe el índice del carácter y el carácter mismo, y el resultado de f se coloca en la nueva cadena en el índice correspondienteft_strmapi devuelve un puntero a la nueva cadena creada2.
// En resumen, ft_striteri modifica la cadena original y no devuelve nada, mientras que ft_strmapi crea y devuelve una nueva cadena con los caracteres modificados por la función aplicada.