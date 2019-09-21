#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	int 			*sorted;
	t_num			*astack;
	t_num			*bstack;
	t_status		status;
	t_instruction	instructions;
	int 		i;

	sorted = ft_get_arguments(argc - 1, argv);
	if ((i = ft_check_stack_sorted(sorted, argc -1)) == 1)
		write(1, "\n", 1);
	ft_bubble_sort(sorted, argc - 1);
	//i = argc - 2;
	//while (i >= 0)
	//{
	//	printf("%d", sorted[i]);
	//	i--;
	//}
	astack = ft_create_array_of_lists(argc - 1, argv, sorted);
	ft_fill_info(&status, sorted, argc - 1);
	bstack = NULL;
	instructions.next = NULL;
	instructions.instruction = -1;
	ft_first_search_mid_and_split(astack, bstack, &instructions);
	return (0);
}