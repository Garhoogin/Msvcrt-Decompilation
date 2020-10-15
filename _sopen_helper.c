errno_t _sopen_helper(char *filename, int oflag, int shflag, int pmode, int *pfh, int arg6){
	int var1C = 0;
	if(pfh == NULL){
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return EINVAL;
	}
	*pfh = -1;
	if(filename != NULL){
		if(pmode & 0xFFFFFE7F){
			errno = EINVAL;
			_invalid_parameter(0, 0, 0, 0, 0);
			return EINVAL;
		}
	}
	int var4 = 0;
	errno_t retval = _tsopen_nolock(&var1C, pfh, filename, oflag, shflag, pmode, arg6);
	var4 = -2;
	if(retval){
		*pfh = -1
	}
	return retval;
}
