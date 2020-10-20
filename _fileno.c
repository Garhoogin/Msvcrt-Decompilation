int _fileno(FILE *stream){
	if(arg1 == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	return arg1->_file;
}
