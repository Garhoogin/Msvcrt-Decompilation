long strtolX(const char *str, char **end, int base, int allowOverflow){
	return strtoxlX(__locale_changed ? NULL : &__initiallocalestructinfo, str, end, base, 0, allowOverflow);
}
