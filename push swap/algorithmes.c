//
// Created by Peggie Donnie on 2019-09-20.
//

#include "push_swap.h"

void	ft_bubble_sort(int *array, int lenght)
{
	int 	i;
	int		temp;

	while (lenght > 1)
	{
		i = 1;
		while (i < lenght)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
			}
			i++;
		}
		lenght--;
	}
}
