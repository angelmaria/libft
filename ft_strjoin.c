#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)); // Asigna memoria dinámicamente para la nueva cadena. La cantidad de memoria es igual al tamaño de s1 más el tamaño de s2, más uno para el carácter nulo de terminación.
	if (str == NULL)
		return (NULL); // Verifica si la asignación de memoria falló
	while (s1[i] != '\0')
	{
		str[i] = s1[i]; // Copia la cadena s1 en la nueva cadena str hasta que se encuentre el carácter nulo que indica el final de s1.
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
// Test (borrar)
int main() {
    char const *s1 = "Hola, ";
    char const *s2 = "mundo!";
    char *resultado;

    // Usar ft_strjoin para concatenar s1 y s2
    resultado = ft_strjoin(s1, s2);
    if (resultado) {
        printf("Cadena concatenada: %s\n", resultado);
        free(resultado); // Liberar la memoria asignada
    } else {
        printf("No se pudo concatenar las cadenas.\n");
    }

    return 0;
}
