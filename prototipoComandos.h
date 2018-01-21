#define minishell_TOK_BUFSIZE 64
#define minishell_TOK_DELIM " \t\r\n\a"
#define minishell_RL_BUFSIZE 1024

#include "meuCd.h"
#include "meuHelp.h"
#include "meuExit.h"
#include "meuClear.h"
#include "meuLs.h"
#include "meuCalcula.h"

/*
Este arquivo contem os prototipos das funções embarcadas no shell, ou seja, aquelas que ele não executa um fork() -> execvp para rodar externamente. Além dos protótipos, um array de ponteiro de funções guarda as referências a cada função embarcada no shell.

Cada "include" inclui a implementação da função embarcada no shell. Isso facilita a modularização do código do shell.
*/

int minishell_cd(char **args);
int minishell_help(char **args);
int minishell_exit(char **args);
int minishell_clear(char **args);
int minishell_ls(char **args);
int minishell_calcula(char **args);

int (*builtin_func[]) (char **) = {
  &minishell_cd,
  &minishell_help,
  &minishell_exit,
  &minishell_clear,
  &minishell_ls,
  &minishell_calcula
};


