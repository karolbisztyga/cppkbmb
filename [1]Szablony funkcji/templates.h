template<class T> double suma(T tab, int length) {
	double result = 0;
	for( int i=0 ; i<length ; ++i ) {
		cout << tab[i];
		if( i<length-1 ) {
			cout << "+" ;
		}
		result += (int)tab[i];
	}
	cout << "=" << result << endl ;
	return result;
}
/*
char * addC(char *tab, char c) {
	int length = 0;
	while( tab[length] != '\0' ) {
		++length;
	}
	char *newTab = new char[++length];
	for( int i=0 ; i<length-1 ; ++i ) {
		newTab[i] = tab[i];
	}
	newTab[length-1] = c;
	return newTab ;
}
*/
double suma(char **tab, int length) {
	double result = 0;
	for( short i=0 ; i<length ; ++i ) {
		int k=0;
		while( tab[i][k] != '\0' ) {
			cout << tab[i][k];
			++k;
			++result;
		}
		if( i<length-1 ) {
			cout << "+";
		} else {
			cout << "=" << result;
		}
	}
	return result;
}
