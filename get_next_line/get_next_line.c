/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:28 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/27 01:00:12 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	last_node = find_last_node(*list);
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		(*list)->next = new_node;
	(*list)->memo = buf;
	(*list)->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int	read_line;
	char	*buf;

	while (!get_new_line(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		read_line = read(fd, buf, BUFFER_SIZE);
		if (!read_line)
		{
			free(buf);
			return ;
		}
		buf[read_line] = '\0';
		ft_append(list, buf);
	}
}

char	get_next_line(int fd)
{
	static t_list *list;
	char	*next_line;

	
}
/*
int	main(void)
{
	int fd1 = open("empty.txt",O_RDONLY);
	int fd2 = open("alternate_line_nl_no_nl",O_RDONLY);
	int fd3 = open("test.txt",O_RDONLY);
	char *a = "kuy";
	
	t_list *list = NULL;

	list->memo = a;
	printf("fd =  %d\n",fd1);
	printf("fd =  %d\n",fd2);
	printf("fd =  %d\n",fd3);
	if (fd1 != -1 || fd2 != -1)
	{
		//read(fd1, buffer,sizeof(buffer));
		create_list(&list, fd2);
		printf(" read result = %s\n", list->memo);
		printf(" read result by create_list = %s\n", list->memo);
	}
	close(fd1);
	close(fd2);

	return (0);
}*/
/*
int	main(void)
{
	t_list *node = NULL;

	char str[] = NULL;
	ft_append(&node,str);
	printf("result ft_append : %s\n",str);
	return (0);
}
*/
int main(void)
{
    int fd = open("test.txt", O_RDONLY); // เปิดไฟล์ "test.txt" สำหรับอ่านเท่านั้น
    if (fd == -1)
    {
        perror("Failed to open file");
        return 1;
    }

    t_list *list = NULL; // สร้าง pointer ชื่อ list และกำหนดค่าเริ่มต้นให้เป็น NULL

    create_list(&list, fd); // เรียกใช้ฟังก์ชัน create_list เพื่อสร้างรายการและอ่านข้อมูลจากไฟล์
    
    // พิมพ์ข้อมูลที่ถูกอ่านจากไฟล์
    t_list *current = list;
    while (current != NULL)
    {
        printf("%s\n", current->memo);
        current = current->next;
    }

    close(fd); // ปิดไฟล์ที่เปิด
    return 0;
}
