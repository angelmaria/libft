#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
// Test (borrar)
int	main(void)
{
	t_list	*element;
	char	*content = "Este es el contenido del elemento";
	int		fd = 1; // Descriptor de archivo para la salida estándar

	element = ft_lstnew(content);
	if (!element)
	{
		ft_putendl_fd("Error al crear el elemento.", fd);
		return (1);
	}
	ft_putstr_fd("El contenido del elemento es: ", fd);
	ft_putendl_fd((char *)element->content, fd);
	free(element); // No olvides liberar la memoria al final
	return (0);
}