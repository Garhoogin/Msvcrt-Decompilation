void __crtExitProcess(int status){
	__crtCorExitProcess(status);
	ExitProcess(status);
}
