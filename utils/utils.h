/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 10:32:16 by rcappend      #+#    #+#                 */
/*   Updated: 2021/12/05 12:56:28 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strchr(const char *s, int c);

size_t		ft_strlen(const char *str);

void		ft_bzero(void *s, size_t n);

int			ft_atoi(const char *str);

void		*ft_memcpy(void *dst, void *src, size_t n);

void		*ft_memset(void *b, int c, size_t len);

void		*ft_calloc(size_t count, size_t size);

void		ft_strcpy(char *dst, const char *src, size_t dstsize);

int			ft_isspace(int c);

int			ft_isdigit(int c);

int			create_trgb(int t, int r, int g, int b);

char		*ft_strtrim(char *s1, char const *set);

#endif
