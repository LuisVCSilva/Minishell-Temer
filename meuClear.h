//NAO EDITE

int minishell_clear (char **args) {
printf("\e[1;1H\e[2J");//Apenas para sistema com suporte posix
return 1;
}
