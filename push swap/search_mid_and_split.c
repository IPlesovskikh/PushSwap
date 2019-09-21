//
// Created by Peggie Donnie on 2019-09-20.
//

#include "push_swap.h"

void				ft_first_search_mid_and_split(t_num *astack, t_num *bstack, t_instruction *instructions)
{
	pb(&astack, &bstack, instructions);
	pb(&astack, &bstack, instructions);
	sb(bstack, instructions);
	printf("%d\n", astack->num);
	printf("%d\n", bstack->num);
	printf("%d\n", bstack->next->num);
	printf("%d\n", instructions->next->instruction);
}