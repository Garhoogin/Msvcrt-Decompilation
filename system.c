int system(const char *command){
	char *comspec = NULL;
	char *argv[4];
	errno_t status = _dupenv_s(&comspec, NULL, "COMSPEC");
	if(status && status == EINVAL){
		_invoke_watson(0, 0, 0, 0, 0);
	}
	argv[0] = comspec;
	if(command == NULL){
		if(comspec == NULL){
			free(comspec);
			return 0;
		}
		status = _access_s(comspec, 0);
		free(comspec);
		return !status;
	}
	argv[1] = "/c";
	argv[2] = command;
	argv[3] = NULL;
	if(comspec != NULL){
		errno_t oldErrno = errno;
		errno = 0;
		status = _spawnve(0, argv[0], argv, NULL);
		if(status != -1){
			errno = oldErrno;
			free(comspec);
			return status;
		}
		if(errno != ENOENT && errno != EACCESS){
			free(comspec);
			return status;
		}
		errno = oldErrno;
	}
	argv[0] = "cmd.exe";
	status = _spawnvpe(0, "cmd.exe", argv, NULL);
	free(comspec);
	return status;
}
