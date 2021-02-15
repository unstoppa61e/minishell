#include "minishell.h"
int g_last_exit_status = 0;

void	test_split_command_line(char *str)
{
	char	**strs;

	strs = split_command_line(str);
	put_strs(strs);
}

void	test_remove_undefined_env(char *str)
{
	t_list	*envp;

	envp = get_env_list();
	DS(remove_undefined_env(str, envp));
}

int main(int argc, char *argv[])
{
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
	// char	*str5 = " \'  \\\"   \" $yay  \"   \'hoge    ";
	// char	*str6 = " \'  \\\"   \" $  \"   \' hoge    ";
	// char	*str7 = "echo \"hoge\"hoge\"hoge\">a>b";
	(void)argc;
	(void)argv;
	// char *str8 = "echo \'$hoge\'";
	// test_split_command_line(str8);
	// test_remove_undefined_env("$US\ER");
	test_remove_undefined_env("$US$ER hoge");

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
