int fgetc(FILE *stream){
	int chr = 0;
	if(stream == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	_lock_file(stream);
	int var4 = 0;
	if(!(stream->_flag & _IOSTRG)){
		int fd = _fileno(stream);
		int high, low;
		int *var20;
		if(fd != -1 && fd != -2){
			high = fd >> 5;
			low = fd & 0x1F;
			var20 = low * 0x24 + __pioinfo[high];
		} else {
			var20 = &__badioinfo;
			high = fd >> 5;
			low = fd & 0x1F;
		}
		int *ioinfo = &__badioinfo;
		if(!(*(char *) (var20 + 2) & 3)){
			if(fd != -1 && fd != -2){
				ioinfo = low * 0x24 + __pioinfo[high];
			}
			if(*(char *) (ioinfo + 2) & 8) {
				errno = EINVAL;
				_invalid_parameter(0, 0, 0, 0, 0);
				chr = -1;
			}
		} else {
			errno = EINVAL;
			_invalid_parameter(0, 0, 0, 0, 0);
			chr = -1;
		}
	}
	if(chr == 0){
		stream->_cnt--;
		chr = (stream->_cnt >= 0) ? *(stream->_ptr++) : _filbuf(stream);
	}
	var4 = -2;
	_unlock_file(stream);
	return chr;
}
