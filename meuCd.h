//NAO EDITE

int minishell_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "Minishell Temer: espera argumento para \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("Minishell Temer");
    }
  }
  return 1;
}

