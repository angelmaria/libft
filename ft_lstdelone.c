#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content); // Si las comprobaciones son exitosas, se llama a la función apuntada por del y se le pasa el contenido (content) del elemento de la lista. Esta función es responsable de liberar adecuadamente la memoria utilizada por el contenido del elemento.
	free(lst);
}
// Test (borrar)
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	// Crear y asignar valores a un nuevo elemento de lista
	t_list	*element = malloc(sizeof(t_list));
	if (!element)
		return (1);
	element->content = malloc(sizeof(char) * 10);
	if (!element->content)
	{
		free(element);
		return (1);
	}
	strcpy(element->content, "contenido");
	element->next = NULL;

	// Mostrar el contenido antes de eliminar
	printf("Contenido antes de ft_lstdelone: %s\n", (char *)element->content);

	// Usar 'ft_lstdelone' para eliminar el elemento
	ft_lstdelone(element, del);

	// El contenido después de 'ft_lstdelone' no debería ser accesible
	printf("Contenido después de ft_lstdelone: %s\n", (char *)element->content);

	return (0);
}