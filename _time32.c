__time32_t _time32(__time32_t *destTime){
	long long fileTime;
	GetSystemTimeAsFileTime((FILETIME *) &fileTime);
	fileTime -= 0x19DB1DED53E8000;
	fileTime /= 10000000;
	
	__time32_t tm = fileTime & 0xFFFFFFFF;
	if(var8 >= 0){
		if(var8 > 0x7FFFD27F){
			tm = -1;
		}
	}
	if(destTime != NULL) *destTime = tm;
	return tm;
}
