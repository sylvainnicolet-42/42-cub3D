
#include "cub3d.h"

t_list_map	*ft_lst_new_map(char *str)
{
	t_list_map	*nw;

	nw = malloc(sizeof(t_list_map));
	if (!nw)
		ft_print_error(MSG_MALLOC_ERR);
	nw->str = ft_strdup(str);
	nw->next = NULL;
	return (nw);
}

void	ft_lst_addback_map(t_list_map **lst, t_list_map *nw)
{
	t_list_map	*node;

	node = *lst;
	if (node == NULL)
		*lst = nw;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = nw;
	}
}

void	ft_free_list_map(t_list_map *lst)
{
	t_list_map	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->str);
		free(tmp);
	}
}

void	ft_print_list_map(t_list_map **lst)
{
	t_list_map	*node;

	node = *lst;
	while (node != NULL)
	{
		printf("[%s]\n", node->str);
		node = node->next;
	}
}

size_t	ft_lst_len_map(t_list_map *lst)
{
	size_t		len;
	t_list_map	*node;

	len = 0;
	node = lst;
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	return (len);
}
