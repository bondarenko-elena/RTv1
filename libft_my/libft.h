/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:05 by olbondar          #+#    #+#             */
/*   Updated: 2017/12/02 15:24:08 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define BUFF_SIZE 8

# define SETNULL(x, y, z) (free(x), y = NULL, z = 0)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct s_list_my
{
	void 			*content;
	size_t 			content_size;
	struct 			s_list_my *next;
	int 			fd;
}					t_list_my;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
double				ft_clamp(double x, double min, double max);
size_t				ft_countwords(char const *str, char c);
int					ft_isalnum(int c);
int					ft_isalnumstr(char *str);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdigitstr(char *str);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void 				*ft_memccpy(void *dst, const void *src, int c, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t size);
void				*ft_memset(void *ptr, int value, size_t num);
int					ft_min(int a, int b);
void				ft_putchar(char	c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strlen_ch(const char *s, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr (const char *big,
												const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *str, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);
t_vector			*vector_add(t_vector *v1, t_vector *v2);
void				vector_clamp(t_vector *v, double v1, double v2);
t_vector			*vector_cross(t_vector *v1, t_vector *v2);
double				vector_distance(t_vector *v1, t_vector *v2);
t_vector			*vector_divide(t_vector *v1, t_vector *v2);
double				vector_length(t_vector *v);
t_vector			*vector_multiply(t_vector *v1, t_vector *v2);
void				vector_normalization(t_vector *v);
t_vector			*vector_op_add(t_vector *v, double x);
t_vector			*vector_op_divide(t_vector *v, double x);
t_vector			*vector_op_multiply(t_vector *a, double x);
t_vector			*vector_reflect(t_vector *i, t_vector *n);
double				vector_scalar_multiply(t_vector *a, t_vector *b);
t_vector			*vector_substract(t_vector *v1, t_vector *v2);

#endif
