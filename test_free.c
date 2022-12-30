void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

//eralnso
void	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		str = NULL;
		return (NULL);
	}
	return (NULL);
}



// Porque hay m[i] = 0?
static void	*ft_free(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
        //m[i] = 0;
		i++;
	}
	free(m);
    //m = 0;
	return (NULL);
}

static char	**ft_delete(char **split)
{
	int	i ;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = 0;
		i++;
	}
	free(split);
	split = 0;
	return (NULL);
}
