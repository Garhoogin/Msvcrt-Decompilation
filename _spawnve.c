intptr_t _spawnve(int mode, const char *cmdname, const char *argv, const char *envp){
	return _spawnvpe(mode, cmdname, argv, NULL);
}
