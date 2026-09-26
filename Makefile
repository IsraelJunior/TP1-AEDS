compile: TAD_Centro_de_Pesquisa.c TAD_Coordenadas.c TAD_Pokelista.c TAD_Pokemon.c TAD_Treinador.c main.c
	gcc -o bin/main TAD_Centro_de_Pesquisa.c TAD_Coordenadas.c TAD_Pokelista.c TAD_Pokemon.c TAD_Treinador.c main.c -g -Wall -lm

#Para rodar o programa, digite no terminal "make compile" e logo em seguida "./bin/main".