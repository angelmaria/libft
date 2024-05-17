#include "libft.h"

int main(void)
{
    char *str1 = "Hola Mundo";
    char *str2 = "Hola Mundo";
    char *str3 = "Hola Mundo!";
    size_t num;

    // Comparar cadenas iguales
    num = 11;
    printf("Comparar '%s' con '%s' hasta %zu caracteres: %d\n", str1, str2, num, ft_strncmp(str1, str2, num));

    // Comparar cadenas con el mismo comienzo pero diferente longitud
    num = 11;
    printf("Comparar '%s' con '%s' hasta %zu caracteres: %d\n", str1, str3, num, ft_strncmp(str1, str3, num));

    // Comparar cadenas con un número de caracteres menor que la diferencia
    num = 5;
    printf("Comparar '%s' con '%s' hasta %zu caracteres: %d\n", str1, str3, num, ft_strncmp(str1, str3, num));

    return 0;
}