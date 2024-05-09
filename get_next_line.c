/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:39:08 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/02 08:07:04 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF 1
char *get_next_line(int fd)
{
	char buffer[BUF + 1];
	
	int bytesRead;
	bytesRead = read(fd, buffer, BUF);

    while (bytesRead > 0) {
        write(1, buffer, BUF);
		bytesRead = read(fd, buffer, BUF);
    }
    if (bytesRead == -1) {
        printf("\nError Reading File!!\n");
        return NULL;
    }
}

int	main(void)
{
	char fileName[] = "./test.txt";
	int fd = open(fileName, 2);
	if (fd == -1){
		printf("\nError Opening File!!\n");
		exit(1);
	}
	else{
		printf("\n%d Bytes from File %s opened sucessfully!\n", fd, fileName);
	}
	get_next_line(fd);
    return 0;

}