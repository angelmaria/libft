/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:48:07 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:10 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_cnt(char const *s, char c) // La función get_cnt cuenta el número de palabras en la cadena s que están separadas por el carácter c.
{
	size_t		cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c) // mueve el puntero s hacia adelante hasta que encuentra el siguiente carácter delimitador o el final de la cadena. Esto efectivamente salta sobre la palabra que acaba de comenzar.
				s++;
		}
	}
	return (cnt);
}

char	**free_machine(char **s, size_t idx) // La función free_machine que toma dos parámetros: un puntero doble char **s, que apunta a un array de cadenas de caracteres (ojo, no a un caracter individual), y un size_t idx, que es el índice hasta el cual se liberará la memoria. La función retorna un puntero doble a char, que en este caso siempre será NULL.
{
	while (s[idx] != NULL && idx >= 0) // Se inicia un bucle while que se ejecutará mientras el elemento en el índice idx del array s no sea NULL y idx sea mayor o igual a cero. Esto asegura que no se intentará liberar memoria más allá de los límites del array y que todos los elementos hasta el índice especificado serán procesados.
	{
		free(s[idx]); // Se llama a la función free para liberar la memoria asignada al elemento en el índice idx del array s
		s[idx] = NULL; // Después de liberar la memoria, se asigna NULL al elemento actual para indicar que ya no está asignado y evitar posibles errores de punteros colgantes.

		idx--; // Se decrementa el valor de idx para moverse al elemento anterior en el array y prepararse para la próxima iteración del bucle.
	}
	free(s); // Una vez que se han liberado todos los elementos individuales, se libera la memoria asignada al propio array s.
	s = NULL; // Se asigna NULL al puntero s para evitar errores de punteros colgantes, aunque esta asignación es local a la función y no afectará al puntero original fuera de la función.
	return (NULL); // Finalmente, la función retorna NULL. Esto es útil para asignar el resultado de free_machine al puntero original en la función llamante, asegurando que no se intente acceder a un arreglo que ya ha sido liberado.
}

char	**ft_split(char const *s, char c) // ft_split crea un arreglo de cadenas words, donde cada elemento es una palabra de la cadena original s que no contiene el carácter delimitador c. Si no puede asignar memoria o si hay un error al obtener las subcadenas, libera la memoria y devuelve NULL.
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words; // Aquí se declaran cuatro variables: idx para el índice actual en el arreglo de palabras, len para la longitud de la palabra actual, word_cnt para el número total de palabras, y words que es el puntero doble que eventualmente contendrá el array de palabras.

	words = NULL; // Se inicializa el puntero words a NULL.
	if (!s || !(words = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1)))) // Se verifica si el puntero s es NULL o si la asignación de memoria para words falla. Si alguna de estas condiciones es verdadera, la función retorna NULL. La memoria se asigna para contener un puntero a char por cada palabra más un espacio adicional para el puntero NULL final.
		return (NULL);
	word_cnt = get_cnt(s, c); // Se llama a la función get_cnt para determinar el número de palabras en la cadena s.
	idx = 0;
	while (*s) // Se inicia un bucle while que se ejecutará mientras el puntero s no apunte al carácter nulo \0.
	{
		if (*s == c) // Si el carácter actual al que apunta s es el delimitador c, se incrementa s para pasar al siguiente carácter.
			s++;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				len++; // Si el carácter actual no es el delimitador, se calcula la longitud de la palabra actual incrementando len hasta que se encuentre el delimitador o el final de la cadena.
			if (idx < word_cnt && !(words[idx++] = ft_substr(s, 0, len)))
				return (free_machine(words, idx)); // Se intenta asignar una subcadena de s a words[idx]. Si ft_substr falla en asignar memoria, se llama a free_machine para liberar la memoria asignada previamente y se retorna NULL.
			s += len; // Se incrementa s para pasar a la siguiente palabra.
		}
	} // El bucle continúa hasta que se hayan procesado todas las palabras.
	words[idx] = 0; // Se asigna el valor 0 (equivalente a NULL en este contexto) al elemento final del arreglo words para indicar el final del mismo.
	return (words); // Finalmente, la función retorna el puntero words, que ahora apunta a un array de cadenas que contiene todas las palabras de la cadena original s separadas por el carácter c.
}
// Esta función supera las 25 líneas. Habría que dividirla en funciones más pequeñas como:
// static char	**allocate_words(char const *s, char c, size_t *word_cnt)
// {
// 	char **words;

// 	*word_cnt = get_cnt(s, c);
// 	words = (char **)malloc(sizeof(char *) * (*word_cnt + 1));
// 	return (words);
// }

// static char	*get_next_word(char const **s, char c, size_t *len)
// {
// 	*len = 0;
// 	while (**s && **s == c)
// 		(*s)++;
// 	while (*(*s + *len) && *(*s + *len) != c)
// 		(*len)++;
// 	return (ft_substr(*s, 0, *len));
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	idx;
// 	size_t	len;
// 	size_t	word_cnt;
// 	char	**words;

// 	if (!s)
// 		return (NULL);
// 	words = allocate_words(s, c, &word_cnt);
// 	if (!words)
// 		return (NULL);
// 	idx = 0;
// 	while (idx < word_cnt)
// 	{
// 		words[idx] = get_next_word(&s, c, &len);
// 		if (!words[idx])
// 			return (free_machine(words, idx));
// 		s += len;
// 		idx++;
// 	}
// 	words[idx] = NULL;
// 	return (words);
// }
// Testing ----------------------------------------------------------------
/* 
int main(int argc, char **argv)
{	
	(void)argc;
	char **words;
	
	words = ft_split(argv[1], argv[2][0]);

	int i = 0;
	for(; words[i]; i++)
		printf("words[%d] = \'%s\'\n", i, words[i]);
	printf("words[%d] = NULL\n", i);

	ft_delete_matrix(words);
}
 */
