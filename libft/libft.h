/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:51 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/25 14:34:05 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_atoi(const char *nptr, t_list **stack_a);
int		ft_isalpha(int c);
int		ft_isascii(int n);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isprint(int c);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t maxsize);
char	*ft_putaddress_base16(unsigned long long n);
char	*ft_putnbr_base16(unsigned int n);
int		ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *d, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, int (*f)(int));

int		arg_c(va_list args);
int		arg_s(va_list args);
int		arg_d(va_list args);
int		arg_u(va_list args);
int		arg_p(va_list args);
int		arg_x(va_list args, int upper);
int		arg_percent(void);
int		ft_printf(const char *format, ...);

char	*get_next_line(int fd);

#endif
