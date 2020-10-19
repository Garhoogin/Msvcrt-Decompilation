long ftell(FILE *stream){
	if(stream == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return -1;
	} else {
		_lock_file(stream);
		int var4 = 0;
		long pos = _ftell_nolock(stream);
		var4 = 0xFFFFFFFE;
		_unlock_file(stream);
		return pos;
	}
}
