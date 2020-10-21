void _dosmaperr(DWORD dwDosErr){
	*_doserrno() = dwDosErr;
	errno = _get_errno_from_oserr(dwDosErr);
}
