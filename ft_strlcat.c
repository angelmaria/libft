#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i; // índice que recorre la cadena dst
	size_t	j; // índice que recorre la cadena src 

	i = 0;
	j = 0;
    // Encuentra el final de la cadena dst y asegura que no exceda el tamaño del buffer.
	while (dst[i] && i < size)
		i++;
    // Comienza a concatenar src a dst, comprobando que no se sobrepase el tamaño del buffer.
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
    // Asegura que la cadena resultante esté terminada en nulo.
	if (i < size)
		dst[i + j] = '\0';
    // Retorna la longitud total que tendría la cadena dst si se hubiera dado suficiente espacio.
	return (i + strlen(src));
}
// Test (borrar)
int main(void)
{
    char dest[44] = "Texto inicial, ";
    const char src[] = "y aquí va el texto añadido.";
    size_t result;

    // Antes de la concatenación
    printf("Antes: %s\n", dest);

    // Concatena src a dest
    result = ft_strlcat(dest, src, sizeof(dest));
    
    // Después de la concatenación
    printf("Después: %s\n", dest);
    
    // Imprime la longitud total que tendría dest si hubiera suficiente espacio
    printf("Longitud total esperada: %zu\n", result);

    return 0;
}