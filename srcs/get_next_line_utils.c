#include "../headers/get_next_line.h"

int	sl(char *str)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*gnl_clean(char *to_free, char **to_null)
{
	free(to_free);
	*to_null = NULL;
	return (NULL);
}

char	*gnl_line(char *str)
{
	char	*new_str;
	int		i;

	if (!str || *str == '\0')
		return (NULL);
	new_str = malloc(sl(str) + (str[sl(str) - 1] == '\n'));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[++i] != '\0' && str[i] != '\n')
		new_str[i - 1] = str[i];
	if (i <= sl(str) && str[i] == '\n')
	{
		new_str[i - 1] = str[i];
		i++;
	}
	new_str[i - 1] = '\0';
	return (new_str);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		s1_len;
	int		s2_len;

	if (s1 && *s1 == 127)
		s1++;
	s1_len = sl(s1) + 1;
	s2_len = sl(s2);
	i = 0;
	newstr = malloc((s1_len + s2_len + 1));
	if (newstr)
		newstr[0] = 127;
	while (newstr && ++i < s1_len && s1)
		newstr[i] = s1[i - 1];
	i = -1;
	while (newstr && ++i < s2_len && s2)
		newstr[s1_len + i] = s2[i];
	if (newstr)
		newstr[s1_len + i] = '\0';
	free(s2);
	while (s1 && *s1 != 127)
		s1--;
	free(s1);
	return (newstr);
}

char	*gnl_alloc(size_t num, size_t size)
{
	char	*arr;
	int		n;

	if (num != 0 && size > ULONG_MAX / num)
		return (NULL);
	n = num * size;
	arr = malloc(n);
	while (arr && n-- > 0)
		arr[n] = '\0';
	return (arr);
}
