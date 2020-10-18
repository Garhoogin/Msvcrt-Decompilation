int _open(const char *filename, int oflag, int pmode){
	int fd = -1;
	int var20 = 0;
	if(arg1 == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	int var4 = 0;
	int status = _tsopen_nolock(&var20, &fd, filename, oflag, 0x40, pmode, 0);
	var4 = -2;
	if(var20){
		if(esi){
			*(char *) (__pioinfo[fd >> 5] + (fd & 0x1F) * 0x24 + 4) &= 0xFE;
		}
		_unlock_fhandle(fd);
	}
	if(!status) return fd;
	errno = status;
	return -1;
}
