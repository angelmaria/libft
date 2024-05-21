#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst != NULL)
	{
		curr = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(curr, del);
	}
}
// Test (borra)
// Función auxiliar para liberar el contenido de un nodo
void del(void *content)
{
    free(content);
}

// Función auxiliar para imprimir el contenido de un nodo
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}

int main(void)
{
    t_list *head;
    t_list *node1;
    t_list *node2;

    // Crear y asignar valores a los nodos
    node1 = ft_lstnew(strdup("Hola"));
    node2 = ft_lstnew(strdup("Mundo"));

    // Enlazar los nodos
    head = node1;
    node1->next = node2;

    // Imprimir la lista antes de limpiarla
    printf("Lista antes de ft_lstclear:\n");
    print_list(head);

    // Limpiar y liberar la lista
    ft_lstclear(&head, del);

    // Intentar imprimir la lista después de limpiarla
    printf("Lista después de ft_lstclear:\n");
    if (head == NULL)
        printf("La lista ha sido eliminada correctamente.\n");

    return 0;
}