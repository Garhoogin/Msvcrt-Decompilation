unsigned long strtoul(const char *strSource, char **endptr, int base){
	return strtoxlX(__locale_changed ? NULL : &__initiallocalestructinfo, strSource, endptr, base, 1, 0);
}
