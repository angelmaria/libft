#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content); // Aquí se llama a la función f pasando el contenido (content) del nodo actual de la lista. Esto aplicará la función f al contenido del nodo.
		lst = lst->next; // Después de aplicar la función, el puntero de la lista se mueve al siguiente nodo (next). El bucle continúa hasta que se alcanza el final de la lista (cuando lst es NULL).
	}
}
// En resumen, ft_lstiter es una función que aplica otra función a cada elemento de una lista enlazada. Es útil para realizar operaciones como modificar, imprimir o acumular valores de los nodos de la lista en una sola pasada.
// Test (borrar)
// Definición de la función que aplicaremos a los contenidos de los nodos
void print_content(void *content)
{
    // Supongamos que los contenidos son cadenas de caracteres
    char *str = (char *)content;
    printf("Contenido del nodo: %s\n", str);
}

int main(void)
{
    // Crear una lista enlazada con algunos nodos
    t_list *node1 = ft_lstnew("Hola, mundo!");
    t_list *node2 = ft_lstnew("¡Hola desde la lista enlazada!");
    t_list *node3 = ft_lstnew("42 es la respuesta a todo.");

    // Enlazar los nodos
    node1->next = node2;
    node2->next = node3;

    // Llamar a ft_lstiter para aplicar la función print_content a cada nodo
    ft_lstiter(node1, print_content);

    // Liberar la memoria de la lista (esto debe hacerse en tu implementación)
    ft_lstclear(&node1, free);

    return 0;
}