//
// Created by Peggie Donnie on 2019-09-20.
//

#ifndef UNTITLED_PUSH_SWAP_H
#define UNTITLED_PUSH_SWAP_H

#include 			<stdlib.h>
#include 			<unistd.h>

#include 			<stdio.h> ///!!!!!

typedef	struct		s_num {
	int 			num;
	int 			order;
	int 			moving;
	struct s_num	*next;
	struct s_num	*prev;

}					t_num;

typedef	struct		s_status {
	int 			next;
	int 			mid;
	int 			max;
	int 			moving;
}					t_status;

typedef	struct		s_instruction {
	int 					instruction;
	struct s_instruction	*next;
	struct s_instruction	*prev;

}					t_instruction;

void				ft_bubble_sort(int *array, int lenght);
int					*ft_get_arguments(int argc, char **argv);
t_num				*ft_create_array_of_lists(int nb, char **argv, int *sorted);
int					ft_check_stack_sorted(const int *sorted, int lenght);
void				ft_fill_info(t_status *info, const int *sorted, int lenght);
void				ft_first_search_mid_and_split(t_num *astack, t_num *bstack, t_instruction *instructions);
void				sa(t_num *a, t_instruction *instructions);
void				sb(t_num *b, t_instruction *instructions);
void				sab(t_num *a, t_num *b, t_instruction *instructions);
void				pb(t_num **a, t_num **b, t_instruction *instructions);
void				pa(t_num **a, t_num **b, t_instruction *instructions);

int					ft_atoi(const char *str);


#endif //UNTITLED_PUSH_SWAP_H
