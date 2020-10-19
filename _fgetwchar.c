wint_t _fgetwchar(void){
	return fgetwc(&_iob[0]);
}
