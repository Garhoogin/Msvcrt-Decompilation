int _fputchar(int c){
	return fputc(c, &_iob[1]);
}
