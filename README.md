#Minishell-Temer

Um trabalho de Sistemas operacionais, o objetivo era implementar um shell que permitisse a criação de funções customizadas pelo usuário.

COMO CRIAR NOVO COMANDO:

Etapa 1 -> Crie um arquivo .h com o nome do comando. Exemplo:
"meuComando.h"

Etapa 2 -> Adicione o protótipo do comando em "prototipoComandos.h"

Etapa 3 -> Adicione o include do arquivo .h criado na Etapa 1

Etapa 4 -> Adicione o comando que chama sua função no array de strings "builtin_str" de "listaComandos.h"

Etapa 5 -> Compile normalmente
gcc MinishellTemer.c -lm [...] -o MinishellTemer

Etapa 6 -> Execute & Teste
./MinishellTemer

Observações:
-> Funções implementadas:
	CALCULA (Parser aritmético fornecido por terceiro)
	CD
	CLEAR
	EXIT
	HELP
	LS

-> As outras funções do SO são chamadas através de um fork() e execvp()
