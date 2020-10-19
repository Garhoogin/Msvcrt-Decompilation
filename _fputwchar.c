int _fputwchar(int c){
	return _fputwc(c, &_iob[1]);
}
