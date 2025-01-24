#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
  t_list *current = lst;
	int temp;

	if(!lst)
		return (NULL);
	while(current->next)
	{
		if(!cmp(current->data, current->next->data))
		{
			temp = current->data;
			current->data = current->next->data;
			current->next->data = temp;
			current = lst;
		}
		else
			current = current->next;
	}
	return(lst);
}
