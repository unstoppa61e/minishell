#include "minishell.h"
int g_last_exit_status = 0;

void	test_split_command_line(char *str)
{
	char	**strs;

	t_list	*envp;

	envp = get_env_list();
	strs = split_command_line(str);
	put_strs(strs);
}

// void	test_remove_undefined_env(char *str)
// {
// 	t_list	*envp;

// 	envp = get_env_list();
// 	DS(remove_undefined_env(str, envp));
// }

// bool	is_continuous_quotes(char *str, size_t index)
// {
// 	return ((ft_strnequal(&str[index], "\'\'", 2)
// 				|| ft_strnequal(&str[index], "\"\"", 2))
// 				&& !is_escaped(str, index));
// }

// char	*get_continuous_quotes_trimmed_str(char *str)
// {
// 	const size_t	len = ft_strlen(str);
// 	size_t			index;
// 	size_t			start;
// 	char			*ret_s;

// 	ret_s = ft_strdup("");
// 	if (!ret_s)
// 		return (NULL);
// 	index = 0;
// 	while (index < len)
// 	{
// 		while (index < len && is_continuous_quotes(str, index))
// 			index += 2;
// 		start = index;
// 		while (index < len && !is_continuous_quotes(str, index))
// 			index++;
// 		ret_s = ft_strnjoin_free(ret_s, &str[start], index - start);
// 	}
// 	// TODO: free とか
// 	return (ret_s);
// }

// char	**get_continuous_quotes_trimmed_strs(char **src_strs)
// void	**get_continuous_quotes_trimmed_strs(char **src_strs)
// {
// 	const size_t	strs_num = ft_count_strs((const char **)src_strs);
// 	size_t			index;
// 	char			**dst_strs;

// 	dst_strs = malloc((strs_num + 1) * sizeof(char *));
// 	if (!dst_strs)
// 		return (NULL);
// 	index = 0;
// 	while (index < strs_num)
// 	{
// 		dst_strs[index] = get_continuous_quotes_trimmed_str(src_strs[index]);
// 		index++;
// 	}
// 	dst_strs[index] = NULL;
// 	ft_free_split(src_strs);
// 	src_strs = dst_strs;
// 	// return (dst_strs);
// }

int main(int argc, char *argv[])
{
/*
** trim_continuous_quotes test
*/
	// DS(trim_continuous_quotes("hoge\"hoge\"\"hoge\"\"\"fuga\'fuga\'\'fuga\'\'\'"));
	// printf("%s\n", trim_continuous_quotes("\"\"hoge\"\""));

	t_list		*envp;

	envp = get_env_list();

	DS(dollar("     \"   $USER   \" ", envp));


/*
** is_quoted_wrongly test
*/
	// char	*str1 = "\"\\\"\"";
	// char	*str2 = " \" hoge \" ";
	// char	*str3 = "   \\\"   \"  \"        ";
	// char	*str4 = "   \\\"   \"  \"  \"      ";

	// char	**strs1 = split_command_line(str1);
	// char	**strs2 = split_command_line(str2);
	// char	**strs3 = split_command_line(str3);
	// char	**strs4 = split_command_line(str4);

	// DS(str1);
	// DI(is_quoted_wrongly(str1));
	// DS(str2);
	// DI(is_quoted_wrongly(str2));
	// DS(str3);
	// DI(is_quoted_wrongly(str3));
	// DS(str4);
	// DI(is_quoted_wrongly(str4));

/*
** split_command_line test
*/
// char	*str1 = "\"\\\"\"";
	// char	*str2 = " \" hoge \" ";
	// char	*str3 = "   \\\"   \"  \"        ";
	// char	*str4 = "   \\\"   \"  \"  \"      ";
	char	*str5 = "ls hoge 2> file1";
	// char	*str6 = " \'  \\\"   \" $  \"   \' hoge    ";
	// char	*str7 = "echo \"hoge\"hoge\"hoge\">a>b";
	(void)argc;
	(void)argv;
	// char *str8 = "echo \'$hoge\'";
	test_split_command_line(str5);
	// test_remove_undefined_env("$US\ER");
	// test_remove_undefined_env("$US$ER hoge");

	// char	**strs1 = split_command_line(str1);
	// char	**strs2 = split_command_line(str2);
	// char	**strs3 = split_command_line(str3);
	// char	**strs4 = split_command_line(str4);
	// char	**strs5 = split_command_line(str5);
	// char	**strs6 = split_command_line(str6);
	// char	**strs7 = split_command_line(str7);

	// if (argc > 1)
	// {
	// 	char	**strs_input = split_command_line(argv[1]);
	// 	// char	**strs_input = ft_split_skipping_quotes(argv[1], '|');
	// 	DS(argv[1]);
	// 	print_strs(strs_input);
	// }
	// char	**strs4 = split_command_line(str4);
	// DS(str1);
	// print_strs(strs1);
	// DS(str2);
	// print_strs(strs2);
	// DS(str3);
	// print_strs(strs3);
	// DS(str4);
	// print_strs(strs4);
	// DS(str5);
	// print_strs(strs5);
	// DS(str6);
	// print_strs(strs6);
	// DS(str7);
	// print_strs(strs7);
	// DI(is_quote_char('\''));
	// DI(is_quote_char('\"'));
/*
** remove_quotes
*/
	// DS(remove_quotes("hoge \"hoge \'hoge hoge\' hoge\""));
	// DS(remove_quotes("'hoge''hoge'"));
	// printf("%s\n", remove_quotes("hoge \"hoge \'hoge hoge\' hoge\""));
	// printf("%s\n", remove_quotes("hoge\"  hoge  \"hoge"));

}
