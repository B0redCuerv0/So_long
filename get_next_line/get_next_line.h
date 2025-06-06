/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:53:44 by inandres          #+#    #+#             */
/*   Updated: 2025/04/22 10:31:39 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char **s1, char const *s2, int bytes);
int		ft_strlen(const char *c);
void	*ft_memcpy(void *dest, const void *src, size_t count);
char	*ft_clean(char **rem);
char	*ft_strchr(char *string, int c);
int		ft_check_null(int bytes, char **rem, char **buffer);
char	*ft_free_return(char **mem);
void	ft_sanity_buffer(char *buffer, int bytes);
char	*trim_newline(char **str1);

#endif
