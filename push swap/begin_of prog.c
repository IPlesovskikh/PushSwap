//
// Created by Peggie Donnie on 2019-09-20.
//

#include "push_swap.h"

int				*ft_get_arguments(int nb, char **argv)
{
	int 	i;
	int		y;
	int		*array;

	array = (int *)malloc(sizeof(int) * nb);
	i = 0;
	y = 1;
	while(nb-- > 0)
		array[i++] = ft_atoi(argv[y++]);
	return (array);
}

int				ft_check_stack_sorted(const int *sorted, int lenght)
{
	int 	i;

	i = 1;
	while (lenght-- > 1)
	{
		if (sorted[i] < sorted[i - 1])
			return(1);
		i++;
	}
	return (0);
}

static void		ft_fill_list_created(t_num	*lst, char **argv, int *sorted)
{
	static int 	i;
	int 		y;

	lst->moving = 0;
	i = (i == 0) ? 1 : i;
	lst->num = ft_atoi(argv[i]);
	y = 0;
	while (sorted[y] != lst->num)
		y++;
	lst->order = y + 1;
	i++;
}

t_num			*ft_create_array_of_lists(int nb, char **argv, int *sorted)
{
	t_num	*lst;
	t_num	*temp;

	lst = NULL;
	temp = NULL;
	while (nb--)
	{
		temp = (lst == NULL) ? temp : lst;
		lst = (lst == NULL) ? lst : lst->next;
		if ((lst = (t_num*)malloc(sizeof(t_num))) == NULL)
			return (NULL);
		lst->prev = temp;
		if (lst->prev != NULL)
			lst->prev->next = lst;
		ft_fill_list_created(lst, argv, sorted);
	}
	lst->next = NULL;
	while(lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

void			ft_fill_info(t_status *info, const int *sorted, int lenght)
{
	info->moving = 0;
	info->mid = 0;
	info->max = sorted[lenght - 1];
	info->next = sorted[0];
}

