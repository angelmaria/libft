#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i])) // Recorre la cadena s1 desde el inicio y salta los caracteres que están en 'set'
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i) // Recorre la cadena s1 desde el final y salta los caracteres que están en 'set'
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));  // Reserva memoria para la nueva cadena recortada
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1); // Copia la parte recortada de s1 a la nueva cadena 'str'
	}
	return (str); // Devuelve la nueva cadena recortada o NULL si no se pudo reservar memoria
}
// Test (borrar)
int main(void)
{
    char const *s1 = "   Hola, mundo!   ";
    char const *set = " ";
    char *resultado;

    resultado = ft_strtrim(s1, set);
    if (resultado != NULL)
    {
        printf("Cadena original: '%s'\n", s1);
        printf("Cadena recortada: '%s'\n", resultado);
        free(resultado);
    }
    else
    {
        printf("Error al reservar memoria.\n");
    }
    return (0);
}