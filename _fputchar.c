int _fputchar(int c){
	return _fputc(c, &_iob[1]);
}
