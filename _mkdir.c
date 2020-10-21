int _mkdir(const char *dirname){
	DWORD dwErr = 0;
	if(!CreateDirectoryA(arg1, NULL)){
		dwErr = GetLastError();
	}
	if(dwErr == ERROR_SUCCESS) return 0;
	_dosmaperr(dwErr);
	return -1;
}
