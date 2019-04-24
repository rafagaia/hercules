/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_horse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:19:34 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/20 22:23:56 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
** 1st exit(0): quit the main thread
** setsid(): become the session leader
** 2nd exit(0): quit the non-leader session
** closes(0-2): close stdin, stdout, stderr
** opens(0-2): open stdin, stderr, stdout to /dev/null (supress output)
*/
void	daemonize(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		exit(-1);
	else if (pid > 0)
		exit(0);
	if (setsid() < 0)
		exit(-1);
	if ((pid = fork()) < 0)
		exit(-1);
	else if (pid > 0)
		exit(0);
	close(0);
	close(1);
	close(2);
	open("/dev/null", O_RDONLY);
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
}

int		main(void)
{
	daemonize();
	while (1)
		fork();
	return (0);
}
