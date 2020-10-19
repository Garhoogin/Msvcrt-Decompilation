char *strcpy(char *strDestination, const char *strSource){
	char *baseDestination = strDestination;
	
	while(strSource & 3){
		char c = *(strSource++);
		if(c == '\0'){
			*strDestination = c;
			return arg1;
		}
		*(strDestination++) = c;
	}
	while(1){
		unsigned int block = *(unsigned int *) strSource;
		strSource += 4;
		if((((~block) ^ (0x7EFEFEFF + block)) & 0x81010100) == 0){
			*(unsigned int *) strDestination = block;
			strDestination += 4;
			continue;
		}
		if((block & 0xFF) == 0){
			*strDestination = block & 0xFF;
			return baseDestination;
		}
		if(((block >> 8) & 0xFF) == 0){
			*(unsigned short *) strDestination = block & 0xFFFF;
			return baseDestination;
		}
		if((block & 0xFF0000) == 0){
			*(unsigned short *) strDestination = block & 0xFFFF;
			strDestination[2] = '\0';
			return baseDestination;
		}
		if((block & 0xFF000000) == 0){
			*(unsigned int *) strDestination = block;
			return baseDesstination;
		}
		*(unsigned int *) strDestination = block;
		strDestination += 4;
	}
}
