long strtol(const char *string, char **end_ptr, int base){
	return strtoxlX(__locale_changed ? NULL : &__initiallocalestructinfo, string, end_ptr, base, 0, 0);
}
