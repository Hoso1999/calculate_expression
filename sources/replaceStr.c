#include "calculator.h"

int	findStr(char *str, char *needle, int n)
{
	int	h_index = 0;

	if (!needle || !*needle)
		return (-1);
	while (str[h_index])
	{
		int n_index = 0;
		if (str[h_index] == needle[n_index])
		{
			while (str[h_index + n_index] == needle[n_index])
			{
				if (needle[n_index + 1] == '\0' && h_index > n)
					return h_index;
				++n_index;
			}
		}
		++h_index;
	}
	return (-1);
}

static void strReplace(char **str, int start)
{
    if (start > 0 && (*str)[start + 1] && (*str)[start + 1] == '(')
    {
        char *rep = (char *)calloc(strlen(*str) + strlen(NEGARTHMSTR) + 1, sizeof(char));

        memmove(rep, *str, start);
        strcat(rep, NEGARTHMSTR);
        strcat(rep, *str + start + 1);
        *str = rep;
    }
}

void ReaplaceAll(char **str)
{
    int minus = findStr(*str, "-(", 0);

    while (minus != -1)
    {
        strReplace(str, minus);
        minus = findStr(*str, "-(", minus);
    }    
}