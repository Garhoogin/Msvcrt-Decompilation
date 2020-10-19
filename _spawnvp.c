intptr_t _spawnvp(int mode, const char *cmdname, const char *argv, const char *envp){
	return _spawnvpe(mode, cmdname, argv, NULL);
}
