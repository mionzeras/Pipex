/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:12:12 by gcampos-          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:47 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	printf("\n------ func: ft_isalpha ------\n");
	printf("%i\n", ft_isalpha('d'));
	printf("%i\n", ft_isalpha('8'));

	printf("\n------ func: ft_isdigit ------\n");
	printf("%i\n", ft_isdigit('4'));
	printf("%i\n", ft_isdigit('0'));
	printf("%i\n", ft_isdigit('B'));

	printf("\n------ func: ft_isalnum ------\n");
	printf("%i\n", ft_isalnum('a'));
	printf("%i\n", ft_isalnum('0'));
	printf("%i\n", ft_isalnum('/'));
	
	printf("\n------ func: ft_isascii ------\n");
	printf("%i\n", ft_isascii('a'));
	printf("%i\n", ft_isascii(130));
	
	printf("\n------ func: ft_isprint ------\n");
	printf("%i\n", ft_isprint('a'));
	printf("%i\n", ft_isprint(10));
	
	printf("\n------ func: ft_strlen ------\n");
	char	c[]="Gabriel Augusto";
	printf("Size of s: %lu\n", ft_strlen(c));

	printf("\n------ func: ft_memset ------\n");
	char	c1[30] = "Olha la quem vem";
	printf("Str before memset: %s\n", c1);
	ft_memset(c1, 'x', 3);
	printf("Str after memset: %s\n", c1);

	printf("\n------ func: ft_bzero ------\n");
	char	c2[]= "Gabriel";
	for (size_t i = 0; i < 7; i++)
	{
		printf("[%c]", c2[i]);
	}
	printf("\n");
	ft_bzero(c2, 3);
	for (size_t i = 0; i < 7; i++)
	{
		printf("[%c]", c2[i]);
	}
	printf("\n");
	
	printf("\n------ func: ft_memcpy ------\n");
	char	c3[] = "Ola mundo";
	char	c4[15] = "";
	printf("%s\n", c4);
	ft_memcpy(c4, c3, 15);
	printf("%s\n", c4);
	
	printf("\n------ func: ft_memmove ------\n");
	char	c5[] = "Ola mundo";
	char	c6[15];
	ft_memcpy(c6, c5, 15);
	printf("%s\n", c6);

	printf("\n------ func: ft_strlcpy ------\n");
	char	frase[] = "Aqui vai jsfdgd\n";
	char	recebe[15];
	printf("%ld, %s\n", ft_strlcpy(recebe, frase, 3), recebe);

	printf("\n------ func: ft_strlcat ------\n");
	char	dest[14] = "123";
	char	src[] = "456";
	printf("%ld, %s\n", ft_strlcat(dest, src, 20), dest);

	printf("\n------ func: ft_toupper ------\n");
	printf("%c\nLibft", ft_tolower('G'));

	printf("\n------ func: ft_strchr ------\n");
	char	g[] = "If i had money";
	char	*ptr = ft_strchr(g, 'a');
	printf("A letra: %c, foi achada no indice: %ld\n", *ptr, ptr - g);
	printf("%s\n", ptr);
	
	printf("\n------ func: ft_strrchr ------\n");
	char	g1[] = "My name is Gabriel";
	char	*ptr1 = ft_strrchr(g1, '\0');
	printf("A letra: %c, foi achada no indice: %ld\n", *ptr1, ptr1 - g1);
	printf("%s\n", ptr1);

	printf("\n------ func: ft_strncmp ------\n");
	char *f1;
	char *f2;
	int	n = 6;

	f1 = "abcdefghij";
	f2 = "abcdefgxyz";
	printf("%s\n%s\nDiference : %d\n", f1, f2, ft_strncmp(f1, f2, n));

	printf("\n------ func: ft_memchr ------\n");
	char	f3[] = "Gabriel sou eu";
	char	*ptr2 = ft_memchr(f3, 's', 9);
	if (ptr2 == NULL)
	{
		printf("Caractere nao encontrado\n");
	}
	else
	{
		printf("A letra: %c, foi achada no indice: %ld\n", *ptr2, ptr2 - f3);
		printf("%s\n", ptr2);
	}

	printf("\n------ func: ft_memcmp ------\n");
	char	*f4;
	char	*f5;
	int		n1 = 6;

	f4 = "abcdef";
	f5 = "abcde";
	printf("%i\n", ft_memcmp(f4, f5, n1));

	printf("\n------ func: ft_strnstr ------\n");
	const char	small[] = "Campos ro";
	const char	big[] = "Gabriel Augusto Campos Rodrigues";
	char	*ptr3;

	ptr3 = ft_strnstr(big, small, 40);
	if (ptr3)
		printf("'%s' encontrado em '%s'\n", small, big);
	else
		printf("'%s' não encontrado em '%s'\n", small, big);

	printf("\n------ func: ft_atoi ------\n");
	char	f6[] = "\t\n\r\v\f  469 \n";
	printf("%d\n", ft_atoi(f6));

	printf("\n------ func: ft_calloc ------\n");
	int		*ptr4;
	
	ptr4 = (int *)ft_calloc(4, sizeof(int));
	printf("%p, %p\n", ptr4, &ptr4);
	
	printf("\n------ func: ft_strdup ------\n");
	char	*f7;
	char	*f8;
	
	f7 = "Gabriel Augusto";
	f8 = "";
	
	f8 = ft_strdup(f7);
	printf("%s\n", f8);

	printf("\n------ func: ft_substr ------\n");
	char *f9;
	char *f10;
	
	f9 = "Gabriel Augusto";
	f10 = ft_substr(f9, 3, 4);
	printf("%s\n", f10);

	printf("\n------ func: ft_strjoin ------\n");
	char	*f11;
	char	*f12;
	char	*f13;

	f11 = "Gabriel";
	f12 = " Augusto";
	f13 = ft_strjoin(f11, f12);
	printf("%s\n", f13);

	printf("\n------ func: ft_strtrim ------\n");
	char	*f14;
	char	*f15;

	f14 = "aaacaaGabrielaaaaba";
	f15 = ft_strtrim(f14, "abc");
	printf("%s\n", f15);

	printf("\n------ func: ft_split ------\n");
	char	*f16;

	f16 = "Gabriel Augusto Campos Rodrigues";
	ft_split(f16, ' ');
	printf("%s\n", f16);
	
	printf("\n------ func: ft_putchar_fd ------\n");
	ft_putchar_fd('H', 1);
	printf("\n");
	
	printf("\n------ func: ft_putstr_fd ------\n");
	char	*f17;

	f17 = "Helloooo";
	ft_putstr_fd(f17, 1);

	printf("\n------ func: ft_putendl_fd ------\n");
	char	*f18;

	f18 = "Helloooo";
	ft_putendl_fd(f18, 1);
	
	printf("\n------ func: ft_itoa ------\n");
	

	printf("\n------ func: ft_strmapi ------\n");
}
