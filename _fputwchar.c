int _fputwchar(int c){
	return fputwc(c, &_iob[1]);
}
