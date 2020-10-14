long atol(const char *str){
	if(str == NULL){
		return 0;
	}
	return strtolX(str, NULL, 10, 1);
}
