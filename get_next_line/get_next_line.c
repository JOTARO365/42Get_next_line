/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:28 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/21 19:39:29 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd1 = open("empty.txt",O_RDONLY);
	int fd2 = open("alternate_line_nl_no_nl",O_RDONLY);
	char buffer[50];
	printf("fd =  %d\n",fd1);
	printf("fd =  %d\n",fd2);
	if (fd1 != -1 || fd2 != -1)
	{
		read(fd1, buffer,sizeof(buffer));
		printf(" read result = %s\n",buffer); 
		read(fd2, buffer,sizeof(buffer));
		printf(" read result = %s\n",buffer);
	}
	close(fd1);
	close(fd2);
	return (0);
}
