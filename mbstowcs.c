size_t mbstowcs(whar_t *wcstr, const char *mbstr, size_t count){
	return _mbstowcs_l_helper(wcstr, mbstr, count, __locale_changed ? NULL : &__initiallocalestructinfo);
}
