/*
Esse arquivo de cabeçalho contém um array de comandos embarcados no shell, caso o comando digitado não se encontre no array, o comando é tido como um comando do SO, e um fork e execvp é executado no mesmo.
*/

char *builtin_str[] = {
  "cd",
  "help",
  "exit",
  "clear",
  "ls",
  "calcula"
};


/*
Esta função retorna o número de strings de comandos existe no array acima, esta implementação para contar o comprimento do array de strings foi preferida visto que usar uma macro #define para isso, tornaria a expansão do shell mais propensa a erros.
*/

int minishell_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}
