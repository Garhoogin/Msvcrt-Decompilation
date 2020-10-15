__time32_t _time32(__time32_t *destTime){
	long long fileTime;
	GetSystemTimeAsFileTime((FILETIME *) &fileTime);
	fileTime -= 116444736 * 1000 * 1000 * 1000;
	fileTime /= 10000000;
	
	__time32_t tm = fileTime & 0xFFFFFFFF;
	if(fileTime > 0x7FFFD27F){
		tm = -1;
	}
	if(destTime != NULL) *destTime = tm;
	return tm;
}
