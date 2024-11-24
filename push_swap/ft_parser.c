#include"push_swap.h"

static int num_count(char *str, char separator)
{
    int count;
    int inside;

    count = 0;
    while (*str)
    {
        inside = 0;
        while (*str == separator && *str)
            str++;
        while (*str != separator && *str)
        {
            if (!inside)
            {
                ++count;
                inside = 1;
            }
            ++str;
        }
    }
    return (count);
}

static char *get_num(char *str, char separator)
{
    static int  cursor;
    char        *next_str;
    int         len;
    int         i;

    len = 0;
    i = 0;
    while(str[cursor] == separator)
        ++cursor;
    while ((str[cursor + len] != separator) && str[cursor + len])
        ++len;
    next_str = malloc((size_t)len * sizeof(char) + 1);
    if (next_str == NULL)
        return (NULL);
    while ((str[cursor] != separator) && str[cursor])
        next_str[i++] = str[cursor++];
    next_str[i] = '\0';
    return (next_str);
}

char    **ft_parser(char    *str, char separator)
{
    int     words;
    char    **array;
    int     i;

    i = 0;
    words = num_count(str, separator);
    array = malloc(sizeof(char *) * (words + 2));  
    if (array == NULL)
        return (NULL);
    array[0] = malloc(sizeof(char)); // placeholder program name
    if (array == NULL)
        return(NULL);
    array[0][0] = '\0';
    while (words-- > 0)
        array[++i] = get_num(str, separator);
    array[i] = NULL;
    return (array);
}
