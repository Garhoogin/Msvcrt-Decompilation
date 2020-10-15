int _sopen(const char *filename, int oflag, int shflag, int pmode){
	int fd = -1;
	if(_sopen_helper(filename, oflag, shflag, pmode, &fd, 0)) return -1;
	return fd;
}
