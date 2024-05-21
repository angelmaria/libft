#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// Test (borrar)
int main(void)
{
    // Crear algunos nodos para una lista enlazada
    t_list *node1 = ft_lstnew("Hola, soy el primer nodo");
    t_list *node2 = ft_lstnew("¡Hola desde el segundo nodo!");
    t_list *node3 = ft_lstnew("Tercer nodo aquí");

    // Enlazar los nodos
    node1->next = node2;
    node2->next = node3;

    // Obtener el último nodo
    t_list *ultimoNodo = ft_lstlast(node1);

    // Imprimir el contenido del último nodo
    if (ultimoNodo)
        printf("Contenido del último nodo: %s\n", (char *)ultimoNodo->content);
    else
        printf("La lista está vacía.\n");

    // Liberar la memoria de los nodos (esto debería hacerse en una función separada)
    ft_lstclear(&node1, free);

    return 0;
}