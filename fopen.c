FILE *fopen(const char *filename, const char *mode){
	return _fsopen(filename, mode, SH_DENYNO);
}
