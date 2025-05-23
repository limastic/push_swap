/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:14:40 by nfaust            #+#    #+#             */
/*   Updated: 2023/01/10 16:18:42 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dblist
{
	void			*content;
	struct s_dblist	*prev;
	struct s_dblist	*next;
}	t_dblist;

int			ft_isalpha(int i);
int			ft_isdigit(int i);
int			ft_isalnum(int i);
int			ft_isascii(int i);
int			ft_isprint(int i);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isempty(char *str);
size_t		ft_lstsize(t_list *lst);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_dblstsize(t_dblist *lst);
char		*ft_strdup(const char *s1);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
void		ft_bzero(void *s, size_t n);
void		ft_dblstdelone(t_dblist *lst, void (*del)(void*));
void		ft_dblstadd_front(t_dblist **lst, t_dblist *new);
void		ft_dblstadd_back(t_dblist **lst, t_dblist *new);
void		ft_dblstclear(t_dblist **lst, void (*del)(void*));
void		ft_dblstdelone(t_dblist *lst, void (*del)(void*));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_putnbr_fd(int n, int fd);
void		ft_free_twodimarr(char **twodimarr);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_dblist	*ft_dblstlast(t_dblist *lst);
t_dblist	*ft_dblstfirst(t_dblist *list);
t_dblist	*ft_dblstnew(void *content);
t_dblist	*ft_dblstmap(t_dblist *lst, void *(*f)(void *),
				void (*del)(void *));

#endif
