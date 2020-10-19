void __crtCorExitProcess(int status){
	HMODULE hModule = NULL;
	//I think this string is supposed to get overwritten.
	if(GetModuleHandleExW(0, "string", &hModule) == NULL) hModule = NULL;
	if(hModule == NULL) return;
	//and this one.
	void (*ptr) (int) = GetProcAddress(hModule, "string");
	if(ptr == NULL) return;
	ptr(status);
}
