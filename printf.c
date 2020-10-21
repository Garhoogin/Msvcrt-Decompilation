int printf(const char *format, ...){
	if(arg1 == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	}
	va_list args;
	va_start(args, format);
	_lock_file2(1, &_iob[0]);
	int var4 = 0;
	int var0 = _stbuf(&_iob[0]);
	int retval = _output_l(&_iob[0], format, NULL, args);
	_ftbuf(var0, &_iob[0]);
	var4 = -2;
	_unlock_file2(1, &_iob[0]);
	va_end(args);
	return retval;
}
