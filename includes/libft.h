/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	libft.h											:+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: ayafdel <ayafdel@student.42.fr>			+#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2019/10/23 16:12:23 by ayafdel			#+#	#+#			 */
/*	Updated: 2020/12/11 17:59:27 by ayafdel		  ###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_atoi(const char *str);
void	*ft_memmove(void *str1, const void *str2, size_t n);
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_calloc(size_t nitems, size_t size);
void	ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalnum(int n);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isalpha(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strrchr(const char *str, int c);
int		ft_isascii(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *str);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_isdigit(int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_isprint(int n);
char	*ft_strchr(char *str, char x);
int		ft_tolower(int n);
char	*ft_itoa(int m);
char	*ft_strdup(char *s);
int		ft_toupper(int n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_starjoin(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
void	ft_putnbr(int n);
void	ft_putchar(char c);

#endif
