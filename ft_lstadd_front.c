#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst) // Primero, verifica si el nuevo elemento (new) o la lista (lst) son NULL. Si alguno de ellos lo es, la función termina inmediatamente, ya que no se puede añadir un elemento NULL a la lista. No hace nada y retornar. 
		return ;
	if (!(*lst)) // Si la lista está vacía (es decir, *lst es NULL), simplemente establece el nuevo elemento como el primer elemento de la lista.
		*lst = new;
	else // si la lista no está vacía, insertar 'new' al frente
	{
		new->next = *lst; // El siguiente de 'new' ahora será el antiguio primer elemento (imagina que tenemos la lista 4 -> 3 -> 2 -> 1 y el nuevo elemento (new) es el 5. Ahora new->next apunta a 4)
		*lst = new; // Actualiza el puntero de la lista para que apunte al nuevo elemento *lst = new. Ahora 'new' es el primer elemento y *lst apunta al 5 (5 -> 4 -> 3 -> 2 -> 1). 
	}	
}
// Test (borrar)
int main(void)
{
    t_list *head = NULL; // Inicialmente la lista está vacía

    // Crear nodos y añadirlos al frente de la lista
    int *content = malloc(sizeof(int)); // Asegúrate de verificar si malloc no retorna NULL.
    if (content == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    *content = 42;
    t_list *new_node = ft_lstnew(content);
    if (new_node == NULL)
    {
        free(content); // No olvides liberar la memoria si ft_lstnew falla.
        printf("Error al crear un nuevo nodo.\n");
        return 1;
    }
    ft_lstadd_front(&head, new_node); // Añadir el nodo al frente de la lista

    // Imprimir el contenido del primer nodo como prueba
    if (head != NULL)
        printf("El contenido del primer nodo es: %d\n", *(int *)(head->content));
    else
        printf("La lista está vacía.\n");

    // Liberar la memoria de la lista
    free(new_node); // Aquí deberías implementar una función para liberar toda la lista

    return 0;
}