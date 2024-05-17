#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle == NULL || needle[0] == '\0') // verifica si needle es NULL o una cadena vacía. Si es así devuelve haystack. 
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n) // recorre haystack hasta un máximo de n caracteres. 
	{
		if (haystack[i] == needle[j]) // si un carácter de haystack coincide con el primer carácter de needle, se verifica si los siguientes caracteres también coinciden.
		{
			while (haystack[i + j] == needle[j] && i + j < n) 
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i); // Si todos los caracteres de needle se encuentran secuencialmente dentro de haystack antes de n, se devuelve un puntero al inicio de esta subcadena en haystack.
				j++;
			}
			j = 0;
		}	
		i++;
	}
	return (NULL); // Si needle no se encuentra en haystack dentro de los primeros n caracteres, la función devuelve NULL.
}
// Test (borrar)
int main(void)
{
    const char *largeString = "Hola, este es un ejemplo de cadena grande.";
    const char *smallString = "ejemplo";
    char *result;

    // Prueba con n mayor que la longitud de 'largeString'.
    result = ft_strnstr(largeString, smallString, 50);
    if (result)
        printf("Encontrado: '%s'\n", result);
    else
        printf("No encontrado.\n");

    // Prueba con n menor que la posición de 'smallString'.
    result = ft_strnstr(largeString, smallString, 10);
    if (result)
        printf("Encontrado: '%s'\n", result);
    else
        printf("No encontrado.\n");

    // Prueba con una subcadena que no está presente.
    result = ft_strnstr(largeString, "noexiste", 50);
    if (result)
        printf("Encontrado: '%s'\n", result);
    else
        printf("No encontrado.\n");

    return 0;
}
