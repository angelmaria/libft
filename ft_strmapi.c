#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)) // char: El tipo de retorno de la función f. Significa que la función f devolverá un carácter.
// (*f): Esto indica que f es un puntero a una función. Se escribe (*f) en lugar de char *(f) porque queremos que f sea un puntero a una función que devuelve un char, no una función que devuelve un puntero a un char.
// En la definición de la función, tendrás que proporcionar nombres a los parámetros para poder referirte a ellos dentro del cuerpo de la función. Pero en la declaración, especialmente en los archivos de cabecera (header files), es común ver funciones sin nombres de parámetros, lo que ayuda a mantener el código limpio y enfocado en los tipos de datos y la funcionalidad.
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1); // Reserva memoria para la nueva cadena, incluyendo el carácter nulo al final

	if (str == NULL)
		return (NULL); // Si la reserva de memoria falla, devuelve NULL
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]); // Aplica la función 'f' al carácter actual y lo asigna a la nueva cadena
		i++;
	}
	str[i] = '\0'; // Asegura que la nueva cadena esté terminada con un carácter nulo
	return (str); // Devuelve la nueva cadena transformada
}
// Test (borrar)
// Función de ejemplo para transformar los caracteres a mayúsculas
char	to_upper(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32); // Convierte a mayúscula si 'i' es par
	else if (i % 2 != 0 && c >= 'A' && c <= 'Z')
		return (c + 32); // Convierte a minúscula si 'i' es impar
	return (c); // Devuelve el carácter sin cambios si no es letra o no necesita cambio
}

// Función 'main' para probar 'ft_strmapi'
int	main(void)
{
	char const *s = "hola mundo";
	char *result;

	result = ft_strmapi(s, to_upper);
	if (result != NULL)
	{
		printf("Cadena original: %s\n", s);
		printf("Cadena transformada: %s\n", result);
		free(result); // No olvides liberar la memoria
	}
	else
	{
		printf("Error al reservar memoria.\n");
	}
	return (0);
}