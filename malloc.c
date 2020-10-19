void *malloc(size_t size){
	if(_crtheap == 0){
		if(!_core_crt_dll_init()){
			return NULL;
		}
	}
	if(size > 0xFFFFFFE0){
		_callnewh(size);
		errno = 0xC;
		return 0;
	}
	void *block;
	do{
		if(_crtheap == 0){
			_FF_MSGBANNER();
			_NMSG_WRITE(0x1E);
			__crtExitProcess(0xFF);
		}
		if(__active_heap == 1){
			block = RtlAllocateHeap(_crtheap, 0, size ? size : 1);
		} else {
			if(__active_heap == 3 || __active_heap == 2){
				if(__active_heap == 3){
					block = V6_HeapAlloc(size);
				} else {
					block = V5_HeapAlloc(size);
				}
				if(block == NULL){
					block = RtlAllocateHeap(_crtheap, 0, ((size ? size : 1) + 0xF) & ~0xF);
				}
			} else {
				block = call RtlAllocateHeap(_crtheap, 0, ((size ? size : 1) + 0xF) & ~0xF);
			}
		}
		if(block != NULL) return block;
		if(_newmode == 0){
			errno = ENOMEM;
			errno = ENOMEM;
			return NULL;
		}
	} while(_callnewh(size));
	errno = ENOMEM;
	return NULL;
}
