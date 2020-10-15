errno_t _sopen_s(int *pfh, const char *filename, int oflag, int shflag, int pmode){
	return _sopen_helper(filename, oflag, shflag, pmode, pfh, 1);
}
