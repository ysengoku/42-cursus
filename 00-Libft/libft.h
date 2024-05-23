/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:23:54 by yusengok          #+#    #+#             */
/*   Updated: 2024/05/23 13:34:11 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ----- libraies ----- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

/* ----- macro definition ----- */
/* ft_printf */
# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxX"
# endif

# ifndef BASE_HEX_LOWER
#  define BASE_HEX_LOWER "0123456789abcdef"
# endif

# ifndef BASE_HEX_UPPER
#  define BASE_HEX_UPPER "0123456789ABCDEF"
# endif

/* get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ----- type definition ----- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ----- Libft basic functions ----- */
int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* ----- list functions ----- */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void	*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/* ----- additional functions ----- */
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr_r(char *big, char *little);
long			ft_atol(const char *s);
long long		ft_atoll(const char *s);
unsigned int	ft_abs(int n);

/* ----- ft_printf ----- */
int				ft_printf(const char *format, ...);
int				ft_printf_char(char c);
int				ft_printf_str(char *str);
int				ft_printf_ptr(void *arg);
int				ft_printf_nbr(long n);
int				ft_printf_uint(int n);
int				ft_printf_hex(int n, char sp);

/* ----- get_next_line ----- */
char			*get_next_line(int fd);

#endif
