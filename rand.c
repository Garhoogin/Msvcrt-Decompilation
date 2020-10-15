int rand(void){
	int *seed = _getptd() + 5;
	int r = *seed * 0x343FD + 0x269EC3;
	*seed = r;
	return (r >> 5) & 0x7FFF;
}
