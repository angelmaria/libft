#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// Test (borrar)
int main(void)
{
    t_list *head;
    t_list *temp;
    int size;

    // Crear el primer nodo (cabeza de la lista)
    head = ft_lstnew("Primer elemento");
    temp = head;

    // Añadir más nodos a la lista
    temp->next = ft_lstnew("Segundo elemento");
    temp = temp->next;
    temp->next = ft_lstnew("Tercer elemento");
    temp = temp->next;
    temp->next = ft_lstnew("Cuarto elemento");

    // Calcular el tamaño de la lista
    size = ft_lstsize(head);
    printf("El tamaño de la lista es: %d\n", size);

    // Liberar la memoria de la lista
    ft_lstclear(&head, &free);
    return (0);
}