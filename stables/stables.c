/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stables.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:02:48 by rgaia             #+#    #+#             */
/*   Updated: 2019/03/29 21:14:25 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

//OK
typedef struct 			s_unrolled
{
	int					values[8];
	unsigned			count;
	struct s_unrolled	*next;
} 						t_unrolled;

t_unrolled				*new_unrolled(void)
{
	t_unrolled			*new = malloc(sizeof(t_unrolled));
	new->next = NULL;
	new->count = 0;
	return (new);
}

long					sum_unrolled(t_unrolled *list)
{
	int					size;
	long				sum;

	sum = 0;
	while (list)
	{
		size = list->count;
		do
		{
			sum += list->values[--size];
		} while (size != 0);
		list = list->next;
	}
	return (sum);
}

void					del_unrolled(t_unrolled *list)
{
	t_unrolled			*tmp;

	if (!(list))
		return ;
	do
	{
		tmp = list;
		list = list->next;
		free(tmp);
	} while (list->next);
}

int						main(void) 
{
	int					val;
	unsigned			i;
	long long			magic;
	t_unrolled			*list;
	t_unrolled			*tmp;

	magic = 753057078882375803;
	val = 0;
	i = 0;
	list = NULL;
	while (i < 42)
	{
		if (!(tmp = new_unrolled()))
		{
			if (list)
				del_unrolled(list);
			return (0);
		}
		while (tmp->count < 8)
		{
			tmp->values[tmp->count] = val++;
			++tmp->count;
		}
		++i;
		if (!list)
			list = tmp;
		else
		{
			tmp->next = list;
			list = tmp;
		}			
	}
	magic += sum_unrolled(list);
	write(1, &magic, 8);
	del_unrolled(list);
	return(0);
}
