/* Esercitazione su iteratori validi e invalidi */

void foo(const std::vector<std::string>& v) {
	
	// using Iter = std::vector<std::string>::iterator;
	
	// I valori i e i_end prendo il tipo dal risultato della find.
	auto i = std::find(v.begin(); v.end(), "cioccolato");
	auto i_end = std::find(v.begin, v.end(), "menta");
	
	for( ; i!=i_end; ++i)
		std::cout << *i << std::endl;
}

void bar(std::vector<std::string>& v) {
	
	auto i = v.begin();
	auto i_end = v.end();
	
	if(i != v.end())
		*i = "cacao"; // UB se il vettore è vuoto: aggiungo l'if per questo
	
	i = v.insert(i, "vaniglia"); // Potrebbe invalidare i_end
	
	// Devo ricalcolare gli iteratori: uso v.end() nel for
	for( ; i!=v.end(); ++i) 
		std::cout << *i << std::endl;
}

/* 
Bisogna stare attenti quando si usa gli iteratori a prendere una 
coppia di iteratori che non invalidi la sequenza
*/