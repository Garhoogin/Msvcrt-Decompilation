long strtolX(const char *str, void *arg2, int base, int arg4){
	return strtoxlX(__locale_changed ? NULL : &__initiallocalestructinfo, str, arg2, base, 0, arg4);
}
