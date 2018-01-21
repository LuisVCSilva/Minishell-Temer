//NAO EDITE

int minishell_inicia (char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {

    if (execvp(args[0], args) == -1) {
      perror("Minishell Temer");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {

    perror("Minishell Temer");
  } else {

    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int minishell_execute(char **args) // Executa função passado com array de string com argumentos.
{
  int i;

  if (args[0] == NULL) {

    return 1;
  }

  for (i = 0; i < minishell_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return minishell_inicia(args);
}

#define minishell_RL_BUFSIZE 1024

char *minishell_read_linha(void) // Le linha do console
{
  int bufsize = minishell_RL_BUFSIZE;
  int posicao = 0;
  char *buffer = malloc(sizeof(char) * bufsize);//Aloca linha com comprimento = 1024
  int c;

  if (!buffer) {
    fprintf(stderr, "Minishell Temer: erro de alocação\n");
    exit(EXIT_FAILURE);
  }

  while (1) {

    c = getchar();


    if (c == EOF || c == '\n') {
      buffer[posicao] = '\0';//Se EOF ou \n entao fim da linha, retorne-a
      return buffer;
    } else {
      buffer[posicao] = c;//senao, continue lendo...
    }
    posicao++;

    if (posicao >= bufsize) {//Se a posicao excede o tamanho do buffer, dobre o tamanho do buffer e realoque.
      bufsize += minishell_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "Minishell Temer: erro de alocação\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


/*
Função que separa a linha, delimitador de separação é definido em #minishell_TOK_DELIM
*/
char **minishell_split_linha(char *linha)
{
  int bufsize = minishell_TOK_BUFSIZE, posicao = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "Minishell Temer: erro de alocação\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(linha, minishell_TOK_DELIM);
  while (token != NULL) {
    tokens[posicao] = token;
    posicao++;

    if (posicao >= bufsize) {
      bufsize += minishell_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "Minishell Temer: erro de alocação\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, minishell_TOK_DELIM);
  }
  tokens[posicao] = NULL;
  return tokens;/*Retorna array de strings que contem cada substring a direita delimitada pelo separador definido em #minishell_TOK_DELIM*/
}


void minishell_loop(void)
{
  char *linha;//String que armazena comando
  
  /*Array de string que armazena os argumentos do comando, cada string de argumento fica em uma posição do array.*/
  char **args;
  
  /*Recebe um inteiro, se inteiro é 0 continua a execução, se 1 então execução bem sucedida, outros inteiros
  especificam outros erros, que devem ser implementados de acordo com a necessidade*/
  int status;

  do {
  char dirAtual[minishell_RL_BUFSIZE] = "";
  if(getcwd(dirAtual, sizeof(dirAtual))==NULL)//Tenta recuperar o diretorio atual e armazena na string dirAtual
  {
  strcpy(dirAtual,"Diretorio desconhecido");
  }
    printf("\nmini-sh[%s]$ ",dirAtual);//Imprime o prefixo do shell como especificado
    linha = minishell_read_linha();//Le a linha com o comando mais argumentos
    args = minishell_split_linha(linha);//Separa argumentos de comandos, comandos são armazenados em args
    status = minishell_execute(args);//executa o comando com os argumentos passados

    free(linha);
    free(args);
  } while (status);
}

