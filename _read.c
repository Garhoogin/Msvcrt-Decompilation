int _read(int fd, const void *buffer, unsigned buffer_size){
	if(fd == -2){
		*__doserrno() = 0;
		errno = EBADF;
		return -1;
	}
	if(fd < 0 || fd >= _nhandle){
		*__doserrno() = 0;
		errno = EBADF;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	int var20 = (fd & 0x1F) * 0x24;
	if(__pioinfo[fd >> 5][var20 + 4] & 1 == 0){
		*__doserrno() = 0;
		errno = EBADF;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}	
	if(buffer_size > 0x7FFFFFFF){
		*__doserrno() = 0;
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	__lock_fhandle(fd);
	int nRead = 0;
	int var4 = 0;
	if(__pioinfo[fd >> 5][var20 + 4] & 1){
		nRead = _read_nolock(fd, buffer, buffer_size);
	} else {
		errno = EBADF;
		*__doserrno() = 0;
		nRead = -1;
	}
	var4 = -2;
	_unlock_fhandle(fd);
	return nRead;
}
