int _filbuf(FILE *stream){
	if(stream == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	if(stream->_flag & (_IOREAD | _IOWRT | _IORW) == 0) return -1;
	if(stream->_flag & _IOSTRG) return -1;
	if(stream->_flag & _IOWRT){
		stream->_flag |= _IOERR;
		return -1;
	}
	stream->_flag |= _IOREAD;
	if(stream->_flag & (0x100 | _IONBF | _IOMYBUF) == 0){
		_getbuf(stream);
	} else {
		stream->_ptr = stream->_base;
	}
	stream->_cnt = _read(_fileno(stream), stream->_base, stream->_bufsiz);
	if(stream->_cnt == 0 || stream->_cnt == -1){
		stream->_flag |= stream->_cnt ? _IOERR : _IOEOF;
		stream->_cnt = 0;
		return -1;
	}
	if(!(stream->_flag & (_IORW | _IOWRT))){
		int *p;
		if(_fileno(stream) != -1){
			if(_fileno(stream) != -2){
				p = __pioinfo[_fileno(stream) >> 5] + (_fileno(stream) & 0x1F) * 0x24;
			} else {
				p = __badioinfo;
			}
		} else {
			p = __badioinfo;
		}
		if(p[1] & 0x82 == 0x82){
			stream->_flag |= 0x2000;
		}
	}
	if(stream->_bufsiz == 512){
		if(stream->_flag & (0x400 | _IOMYBUF) == _IOMYBUF){
			stream->_bufsiz = 0x1000;
		}
	}
	stream->_cnt--;
	return *(stream->_ptr++);
}
