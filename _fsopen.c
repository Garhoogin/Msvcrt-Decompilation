FILE *_fsopen(const char *filename, const char *mode, int shflag){
	int var1C = 0;
	if(filename == NULL){
		errno = EINVAL;
		return NULL;
	}
	if(mode == NULL || *mode == '\0'){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return NULL;
	}
	FILE *fp = _getstream();
	if(fp == NULL){
		errno = EMFILE;
		return NULL;
	}
	int var4 = 0;
	if(*filename == '\0'){
		errno = EINVAL;
		_local_unwind4(&__security_cookie, &var10, -2);
		return NULL;
	}
	FILE *retval = _openfile(filename, mode, shflag, fp);
	var1C = retval;
	var4 = -2;
	_unlock_file(fp);
	return retval;
}
