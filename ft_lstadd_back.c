#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last; // Declara un puntero para el último nodo de la lista.

	if (!new || !lst) // Comprueba si el nuevo nodo o la lista son nulos. Si alguno lo es, termina la función.
		return ;
	if (!(*lst)) // Si la lista está vacía (el puntero al primer nodo es nulo),
		*lst = new; // establece el nuevo nodo como el primer nodo de la lista.
    else // Si la lista no está vacía,
	{
		last = ft_lstlast(*lst); // encuentra el último nodo actual de la lista.
		last->next = new; // Establece el campo 'next' del último nodo para que apunte al nuevo nodo.
	}
}
// Test (borrar)
int main(void)
{
    t_list *head; // Este será el comienzo de nuestra lista.
    t_list *new; // Este será el nuevo nodo que queremos añadir.

    head = NULL; // Inicialmente, la lista está vacía.

    // Aquí creamos un nuevo nodo. En un caso real, deberías asignar valores reales.
    new = ft_lstnew("Este es el primer nodo");
    ft_lstadd_back(&head, new); // Añadimos el nuevo nodo al final de la lista.

    // Creamos otro nodo para añadir a la lista.
    new = ft_lstnew("Este es el segundo nodo");
    ft_lstadd_back(&head, new); // Añadimos el segundo nodo al final de la lista.

    // Ahora vamos a imprimir la lista para verificar que los nodos se añadieron correctamente.
    while (head != NULL)
    {
        printf("%s\n", (char *)head->content); // Imprime el contenido del nodo actual.
        head = head->next; // Avanza al siguiente nodo.
    }

    return (0);
}
