#include "calculator.h"

static bool charIsSeparator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		++i;
	}
	if (!c)
		return (true);
	return (false);
}

static int  countWords(const char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (charIsSeparator(str[i + 1], charset)
			&& !charIsSeparator(str[i], charset))
			++words;
		++i;
	}
	return (words);
}

static void	writeWord(char *dest, const char *from, char *charset)
{
	int	i;

	i = 0;
	while (charIsSeparator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		++i;
	}
	dest[i] = '\0';
}

static void writeSplit(char **split, const char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (charIsSeparator(str[i], charset) == 1)
			++i;
		else
		{
			j = 0;
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
	int		words;

	words = countWords(str, charset);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	split[words] = NULL;
	writeSplit(split, str, charset);
	return (split);
}