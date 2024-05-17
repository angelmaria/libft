#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}
// Test (borrar)
int	main(void)
{
	const char *cadena = "Hola Mundo!";
	char caracter_a_buscar = 'M';
	char *resultado;

	resultado = ft_strchr(cadena, caracter_a_buscar);
	if (resultado != NULL)
		printf("Caracter encontrado: %s\n", resultado);
	else
		printf("Caracter no encontrado.\n");

	// Prueba con el carácter nulo
	resultado = ft_strchr(cadena, '\0');
	if (resultado != NULL)
		printf("Caracter nulo encontrado al final de la cadena: %s\n", resultado);
	else
		printf("Caracter nulo no encontrado.\n");

	return (0);
}

// o este otro código
char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
// o este otro código
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
