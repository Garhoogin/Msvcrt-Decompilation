int _unlock_file(FILE *file){
	if(file >= _iob && file <= &_iob[19]){
		file->_flag &= ~0x8000;
		return _unlock((file - _iob) + 0x10);
	}
	//not exactly sure what this is for
	return LeaveCriticalSection((LPCRITICAL_SECTION) (file + 1));
}
