FILE *_openfile(const char *filename, const char *mode, int shflag, FILE *fp){
	int openMode = _O_RDONLY;
	int hasNorC = 0;
	int isRandomOrSequential = 0;
	int flags = _commode;
	int specifiesEncoding = 0;
	while(*mode == ' ') mode++;
	if(*mode == 'a'){
		openMode = _O_CREAT | _O_APPEND | _O_WRONLY
		flags |= _IOWRT;
	} else if(*mode == 'r'){
		flags |= _IOREAD;
	} else if(*mode == 'w'){
		openMode = _O_TRUNC | _O_CREAT | _O_WRONLY
		flags |= _IOWRT;
	} else {
		*_errno() = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return NULL;
	}
	mode++;
	int hasNext = 1;
	char ch = *mode;
	if(ch){
		while(1){
			if(!hasNext) break;
			switch(ch){
				case 'w':
				case 'a':
				case ' ':
					break;
				case 'b': //if not in binary or text mode, set to binary mode.
					if(openMode & (_O_BINARY | _O_TEXT)){
						hasNext = 0;
					} else {
						openMode |= _O_BINARY;
					}
					break;
				case 'c': //seems to cancel 'n'
					if(!hasNorC){
						flags |= 0x4000;
						hasNorC = 1;
					} else hasNext = 0;
					break;
				case 'n': //seems  to cancel 'c'. They are both documented as 'none' on MSDN.
					if(!hasNorC){
						flags &= ~0x4000;
						hasNorC = 1;
					} else hasNext = 0;
					break;
				case 't': //if not in binary or text mode, set to text mode.
					if(!(openMode & (_O_BINARY | _O_TEXT))) openMode |= _O_TEXT;
					else  hasNext = 0;
					break;
				case 'T': //if not already short lived, make it short lived.
					if(!(openMode & _O_SHORT_LIVED)) openMode |= _O_SHORT_LIVED;
					else  hasNext = 0;
					break;
				case '+': //if not already in read/write mode, set to read/write mode.
					if(openMode & _O_RDWR){
						hasNext = 0;
					} else {
						openMode = (openMode & ~_O_WRONLY) | _O_RDWR;
						flags = (flags & ~(_IOWRT | _IOREAD)) | 0x80;
					}
					break;
				case ',': //following this should be ccs=xxx
					specifiesEncoding = 1;
					hasNext = 0;
					break;
				case 'D': //if not already temporary, set it to temporary.
					eax = openMode & _O_TEMPORARY
					if(!(openMode & _O_TEMPORARY)){
						openMode |= _O_TEMPORARY;
					}
					if(openMode & _O_TEMPORARY) hasNext = 0;
					break;
				case 'N': //set to no inherit
					openMode |= _O_NOINHERIT;
					break;
				case 'R': //if not already random or sequential, set it to random.
					if(!isRandomOrSequential){
						isRandomOrSequential = 1;
						openMode |= _O_RANDOM;
					} else hasNext = 0;
					break;
				case 'S': //if not already random or sequential, set it to sequential.
					if(!isRandomOrSequential){
						isRandomOrSequential = 1;
						openMode |= _O_SEQUENTIAL;
					} else hasNext = 0;
					break;
				default: //unknown character, report an error
					*_errno() = EINVAL;
					_invalid_parameter(0, 0, 0, 0, 0);
					return NULL;
			}
			mode++;
			ch = *mode;
			if(!ch) break;
		}
		if(specifiesEncoding){
			while(*mode == ' ') mode++;
			if(_mbsnbcmp("ccs", mode, 3)){
				*_errno() = EINVAL;
				_invalid_parameter(0, 0, 0, 0, 0);
				return NULL;
			}
			mode += 3;
			while(*mode == ' ') mode++;
			if(*mode != '='){
				*_errno() = EINVAL;
				_invalid_parameter(0, 0, 0, 0, 0);
				return NULL;
			}
			mode++;
			while(*mode == ' ') mode++;
			if(!_mbsnbicmp(mode, "UTF-8", 5)){
				mode += 5;
				openMode |= _O_U8TEXT;
			} else if(!_mbsnbicmp(mode, "UTF-16LE", 8)){
				mode += 8;
				openMode |= _O_U16TEXT;
			} else if(!_mbsnbicmp(mode, "UNICODE", 7)){
				mode += 7;
				openMode |= _O_WTEXT;
			} else {
				*_errno() = EINVAL;
				_invalid_parameter(0, 0, 0, 0, 0);
				return NULL;
			}
		}
	}
	while(*mode == ' ') mode++;
	if(*mode){
		*_errno() = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
		return NULL;
	}
	if(_sopen_s(&fd, filename, openMode, shflag, 0x180)) return NULL;
	fp->_ptr = NULL;
	fp->_cnt = 0;
	fp->_base = NULL;
	fp->_flag = flags;
	fp->_file = fd;
	fp->_tmpfname = NULL;
	return fp;
}
