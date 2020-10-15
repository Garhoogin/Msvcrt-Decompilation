void *calloc(size_t number, size_t size){
	errno_t err = 0;
	void *ptr = _calloc_impl(number, size, &err);
	if(ptr == NULL && err != 0)
		errno = err;
	return ptr;
}
