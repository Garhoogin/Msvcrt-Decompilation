int memcmp(const void *buffer1, const void *buffer2, size_t count){
	while(count >= 4){
		if(*(int *) buffer1 != *(int *) buffer2){
			count = 4;
			break;
		}
		buffer1 += 4;
		buffer2 += 4;
		count -= 4;
	}
	if(count == 0) return 0;
	size_t diff = buffer2 - buffer1;
	while(count){
		char c = *(char *) buffer1;
		if(c < ((char *) buffer1)[diff]) return -1;
		if(c > ((char *) buffer1)[diff]) 1;
		buffer1++;
		count--;
	}
	return 0;
}
