#include "calculator.h"

static bool charIsSeparator(char c, char *charset)
{
	int	i = -1;

	while (charset[++i])
	{
		if (c == charset[i])
			return (true);
	}
	if (!c)
		return (true);
	return (false);
}

static int  countWords(const char *str, char *charset)
{
	int	i = -1;
	int	words = 0;

	while (str[++i] != '\0')
	{
		if (charIsSeparator(str[i + 1], charset)
			&& !charIsSeparator(str[i], charset))
			++words;
	}
	return (words);
}

static void	writeWord(char *dest, const char *from, char *charset)
{
	int	i = -1;

	while (!charIsSeparator(from[++i], charset)) dest[i] = from[i];
	dest[i] = '\0';
}

static void writeSplit(char **split, const char *str, char *charset)
{
	int		i = 0;
	int		word = 0;

	while (str[i])
	{
		if (charIsSeparator(str[i], charset) == 1)
			++i;
		else
		{
			int j = 0;
			while (!charIsSeparator(str[i + j], charset))
				++j;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			writeWord(split[word], str + i, charset);
			i += j;
			++word;
		}
	}
}

char	**split(const char *str, char *charset)
{
	char	**split;
	int		words = countWords(str, charset);

	split = (char **)malloc(sizeof(char *) * (words + 1));
	split[words] = NULL;
	writeSplit(split, str, charset);
	return (split);
}