
#include "push_swap.h"


static void	ft_save_instruction(int num_instruction, t_instruction *instructions)
{
	while (instructions->next != NULL)
		instructions = instructions->next;
	instructions->next = (t_instruction*)malloc(sizeof(t_instruction));
	instructions->next->instruction = num_instruction;
	instructions->next->prev = instructions;
	instructions->next->next = NULL;
}

void		sa(t_num *a, t_instruction *instructions)
{
	int		int_temp;
	int 	order_temp;
	int 	moving_temp;

	int_temp = a->num;
	a->num = a->next->num;
	a->next->num = int_temp;
	order_temp = a->order;
	a->order = a->next->order;
	a->next->order = order_temp;
	moving_temp = a->moving;
	a->moving = a->next->moving;
	a->next->moving = moving_temp;
	ft_save_instruction(0, instructions);
}

void		sb(t_num *b, t_instruction *instructions)
{
	int		int_temp;
	int 	order_temp;
	int 	moving_temp;

	int_temp = b->num;
	b->num = b->next->num;
	b->next->num = int_temp;
	order_temp = b->order;
	b->order = b->next->order;
	b->next->order = order_temp;
	moving_temp = b->moving;
	b->moving = b->next->moving;
	b->next->moving = moving_temp;
	ft_save_instruction(1, instructions);
}

void		sab(t_num *a, t_num *b, t_instruction *instructions)
{
	int		int_temp;
	int 	order_temp;
	int 	moving_temp;

	int_temp = a->num;
	a->num = a->next->num;
	a->next->num = int_temp;
	order_temp = a->order;
	a->order = a->next->order;
	a->next->order = order_temp;
	moving_temp = a->moving;
	a->moving = a->next->moving;
	a->next->moving = moving_temp;
	int_temp = b->num;
	b->num = b->next->num;
	b->next->num = int_temp;
	order_temp = b->order;
	b->order = b->next->order;
	b->next->order = order_temp;
	moving_temp = b->moving;
	b->moving = b->next->moving;
	b->next->moving = moving_temp;
	ft_save_instruction(2, instructions);
}

void		pb(t_num **a, t_num **b, t_instruction *instructions)
{
	t_num		*lst_temp;

	lst_temp = *a;
	if ((*a)->next != NULL)
	{
		(*a) = (*a)->next;
		(*a)->prev = NULL;
	}
	else
		(*a) = NULL;
	if ((*b) != NULL)
	{
		(*b)->prev = lst_temp;
		lst_temp->next = (*b);
		(*b) = lst_temp;
	}
	else
	{
		(*b) = lst_temp;
		(*b)->next = NULL;
	}
	ft_save_instruction(3, instructions);
}

void		pa(t_num **a, t_num **b, t_instruction *instructions)
{
	t_num		*lst_temp;

	lst_temp = *b;
	(*b) = (*b)->next;
	(*b)->prev = NULL;
	if ((*a) != NULL)
	{
		(*a)->prev = lst_temp;
		(*a) = (*a)->prev;
	}
	else
		(*a) = lst_temp;
	ft_save_instruction(4, instructions);
}


/*
void	ra(t_pile *a)
{
	int 	temp;
	int 	i;
	int 	len;

	temp = a->pile[0];
	len = a->size - 1;
	i = 0;
	while (i < len)
	{
		a->pile[i] = a->pile[i + 1];
		i++;
	}
	a->pile[i] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_pile *b)
{
	int 	temp;
	int 	i;
	int 	len;

	temp = b->pile[0];
	len = b->size - 1;
	i = 0;
	while (i < len)
	{
		b->pile[i] = b->pile[i + 1];
		i++;
	}
	b->pile[i] = temp;
	write(1, "rb\n", 3);
}

void	rab(t_pile *a, t_pile *b)
{
	int 	temp;
	int 	i;
	int 	len;

	temp = a->pile[0];
	len = a->size - 1;
	i = 0;
	while (i < len)
	{
		a->pile[i] = a->pile[i + 1];
		i++;
	}
	a->pile[i] = temp;
	temp = b->pile[0];
	len = b->size - 1;
	i = 0;
	while (i < len)
	{
		b->pile[i] = b->pile[i + 1];
		i++;
	}
	b->pile[i] = temp;
	write(1, "rab\n", 4);
}

void	rra(t_pile *a)
{
	int 	temp;
	int 	i;

	temp = a->pile[(a->size - 1)];
	i = a->size - 1;
	while (i > 0)
	{
		a->pile[i] = a->pile[i - 1];
		i--;
	}
	a->pile[i] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_pile *b)
{
	int 	temp;
	int 	i;

	temp = b->pile[(b->size - 1)];
	i = b->size - 1;
	while (i > 0)
	{
		b->pile[i] = b->pile[i - 1];
		i--;
	}
	b->pile[i] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_pile *a, t_pile *b)
{
	int 	temp;
	int 	i;

	temp = a->pile[(a->size - 1)];
	i = a->size - 1;
	while (i > 0)
	{
		a->pile[i] = a->pile[i - 1];
		i--;
	}
	a->pile[i] = temp;
	temp = b->pile[(b->size - 1)];
	temp = b->pile[(b->size - 1)];
	i = b->size - 1;
	while (i > 0)
	{
		b->pile[i] = b->pile[i - 1];
		i--;
	}
	b->pile[i] = temp;
	write(1, "rrr\n", 4);
}
 */