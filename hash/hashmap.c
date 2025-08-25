//use fundamentals of data struc in c book
//non, utiliser plutot le intro to algo

// j'ai un peu compris le principe de l'utilisation de la hash table sur two sum:
// on met dans la hashtable les nombres qu'on nous donne, et ensuite c'est sur le lookup qu'on va gagner beaucoup
// de temps. On calcule d'abord vis à vis du chiffre qu'il faudrait pour atteindre la bonne somme selon le numéro
// de l'index sur lequel on est, et ensuite on regarde sur la hashtable (donc en O(1)) plutot que passer linéairement
// sur chaque éléments de l'index.
// je pense que pour ce problème je n'ai pas besoin de faire de hash fonction et je peux juste mettre les nombres.
// Non, avec les contraintes on est obligé de faire avec une hash fonction parce que sinon c"est beaucoup trop grand


// faire chaque version de la hash function, division, multiplication, et la 3e, et aussi comprendre lhistoire des less significant
// bits sur la premiere version etc.. et ensuite faire twosum en version hachée


// do division method, multiplication method, and universal hashing avaec des keys statiques

// je sais pas si je vais réussir tout de suite à faire le universal hashing car faut vraiment bien comprendre les
// math pour pas se planter sur la deuxieme table de hachage, ça va me prendre du temps.
//
//
// Aussi noter la technique pour avoir ce qu'il y a après la virugule: mod 1, et comprendre pourquoi il y a les rounding
// error sur les float

// On va plutot essayer de faire avec la libc déjà, donc avec hcreate

#define _GNU_SOURCE
#include <search.h>
#include <stdlib.h>

// pour l'instant on va juste faire au plus simple, on additionne tous les chars de la string. On verra après pour faire des meilleures
// hash func.

#define NUMBOFKEYS 111

ENTRY *HashFunc(char *s)
{
	ENTRY *data = malloc(sizeof(ENTRY));
	int i = 0;
	unsigned int result = 0;

	while(s[i])
	{
		result += s[i];
		i++;
	}

	// on va utiliser sprintf pour voir, plutot que itoa, histoire d'utiliser des nouvelles fonctions
	data->key = itoa(result % NUMBOFKEYS);		
	data->data = s;
	return(data);
}

int main()
{
	int tab[] = {1234, 2222 ,44 ,3 ,554 ,66152, 4432 ,5};

	// pas du tout bon pour l'argument nel içi, il ne faut pas regarder le nombre d'éléments
	// mais plutot le nombre de clés possible. Donc pour le leetcode il faudrait plutot faire en fonction des bornes données dans le problème
//	size_t size = sizeof(tab) / sizeof(int);

	struct hsearch_data htab;
	hcreate_r(NUMBOFKEYS, &htab);
	
	int i = 0;
//	while (i < size)
//	{
//		hsearch(
	return (0);
}



// regarder pour le crc32 pour faire une hash fonction maison

// https://stackoverflow.com/questions/190229/where-is-the-itoa-function-in-linux
//  http://www.burtleburtle.net/bob/hash/doobs.html
// https://www.reddit.com/r/programminghorror/comments/uitjxl/hsearch_why_is_this_crap_in_libc/
