/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:43:56 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/20 17:08:28 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int ft_count(const char s, const char c) { return (s == c); }

static char *ft_sep(char const *s1, char const set) {
  size_t i;
  size_t ls;
  size_t end;

  if (!s1)
    return NULL;

  i = 0;
  ls = ft_strlen(s1) - 1;

  while (s1[i] && ft_count(s1[i], set))
    i++;

  while (ls && ft_count(s1[ls], set))
    ls--;

  end = (ls >= i) ? (ls - i + 1) : 0;
  return ft_substr(s1, i, end);
}

static int ft_wcount(const char *s, char c) {
  int i = 0;
  int ls = 0;

  if (!s)
    return 0;

  while (s[i]) {
    while (s[i] && s[i] == c)
      i++;
    if (s[i] && s[i] != c) {
      ls++;
      while (s[i] && s[i] != c)
        i++;
    }
  }
  return ls;
}

char **ft_free_all(char **p) {
  size_t j = 0;

  if (!p)
    return NULL;

  while (p[j])
    free(p[j++]);

  free(p);
  return NULL;
}

char **ft_split(char const *s, char c) {
  char *str;
  char **p;
  int i;
  int start;
  int end;
  int wc;

  if (!s)
    return NULL;

  str = ft_sep(s, c);
  if (!str)
    return NULL;

  wc = ft_wcount(str, c);
  p = ft_calloc(wc + 1, sizeof(char *));
  if (!p)
    return (free(str), NULL);

  i = 0;
  start = 0;
  end = 0;
  while (str[end]) {
    while (str[end] && str[end] == c)
      end++;
    start = end;
    while (str[end] && str[end] != c)
      end++;
    if (end > start) {
      p[i] = ft_substr(str, start, end - start);
      if (!p[i])
        return (free(str), ft_free_all(p));
      i++;
    }
  }
  p[i] = NULL;
  free(str);
  return p;
}
