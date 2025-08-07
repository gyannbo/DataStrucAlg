//use fundamentals of data struc in c book
//non, utiliser plutot le intro to algo

// j'ai un peu compris le principe de l'utilisation de la hash table sur two sum:
// on met dans la hashtable les nombres qu'on nous donne, et ensuite c'est sur le lookup qu'on va gagner beaucoup
// de temps. On calcule d'abord vis à vis du chiffre qu'il faudrait pour atteindre la bonne somme selon le numéro
// de l'index sur lequel on est, et ensuite on regarde sur la hashtable (donc en O(1)) plutot que passer linéairement
// sur chaque éléments de l'index.
// je pense que pour ce problème je n'ai pas besoin de faire de hash fonction et je peux juste mettre les nombres.
// Non, avec les contraintes on est obligé de faire avec une hash fonction parce que sinon c"est beaucoup trop grand
