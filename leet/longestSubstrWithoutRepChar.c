



initable


int lengthOfLongestSubstring(char* s)
{
	char table[256];
	unsigned int i = 0;	   
	unsigned int length = 0;

	initTable()  // faire de l'adressage direct avec les valeurs ascii en indice avec true ou false dedans	

	while(s[i])
	{ 
		if (!checktable())
			length++;
		i++;
	}
	return (length);	
}


int	main()
{
	char s = "abcabcabc"

	
	lengthOfLongestSubstring(s)
	return (0);
}


ah ouai mais en fait il faudrait avoir un curseur sur le début de la table et, non ya pas besoin des quon a deux char qui sont pareil on peut reinit la table je pense.
