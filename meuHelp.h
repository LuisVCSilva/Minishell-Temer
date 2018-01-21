//NAO EDITE
#include "listaComandos.h"

int minishell_help(char **args)
{
  printf("Minishell Temer - SO2 - Exemplo de shell\n");
  printf("Digite os nomes de programas e seus argumentos aqui\n");
  printf("Os comandos disponíveis são:\n");

  for (int i = 0; i < minishell_num_builtins(); i++) {
    printf(" >> %s\n", builtin_str[i]);
  }

  printf("Use man para acessar mais documentação\nNão existe mais esperança após essa linha...\n\n");
  return 1;
}

