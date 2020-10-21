int printf_s(const char *format, ...){
	va_list args;
	va_start(args, format);
	int retval = _vprintf_s_l(format, NULL, args);
	va_end(args);
	return retval;
}
