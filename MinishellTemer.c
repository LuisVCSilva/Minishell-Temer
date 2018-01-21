//NAO EDITE

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "prototipoComandos.h"
#include "funcoes.h"



int main(int argc, char **argv)
{
minishell_loop();//Chama função que lê comandos indefinidamente, vide comando exit ou interrupção (CTRL+C).
return EXIT_SUCCESS;
}
