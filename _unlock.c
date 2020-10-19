void _unlock(int locknum){
	LeaveCriticalSection(*(LPCRITICAL_SECTION *) (_CrtLock_Stderr_DEBUG + 0x24 + locknum * 8));
}
