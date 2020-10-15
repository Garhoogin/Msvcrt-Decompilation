long strtoxlX(void *locale, const char *str, char **end, int base, int initialFlag, int allowOverflow){
	_locale_t var24;
	_LocaleUpdate::_LocaleUpdate(&var24, locale);
	char *ptr = str;
	if(end != NULL) *end = str;
	if(str == NULL || (base != 0 && (base > 36 || base < 2))) {
		errno = EINVAL;
		_invalid_parameter(0, 0, 0, 0, 0);
	} else {
		errno = 0;
		long result = 0;
		char currentChar;
		int isDigit;
		do{
			currentChar = *(ptr++);
			if(*((*(unsigned long **) &var24) + 43) > 1){
				isDigit = _isctype_l(currentChar, 8, &var24);
			} else {
				isDigit = (*(unsigned short *) (*(unsigned long *) ((*(unsigned long *) &var24) + 0xC8) + currentChar * 2)) & 8;
			}
		} while(isDigit);
		flag = initialFlag;
		if(currentChar == '-') flag |= 0x2; //negative flag
		if(currentChar == '+' || currentChar == '-'){
			currentChar = *(ptr++);
		}
		if(base >= 0 && base != 1 && base <= 36) {
			if(base == 0){
				if(currentChar == '0') {
					if(*ptr == 'x' || *ptr == 'X'){
						base = 16;
						if(*ptr == 'x' || *ptr == 'X') {
							currentChar = *(ptr + 1);
							ptr += 2;
						}
					} else base = 8;
				} else base = 10;
			} else if(base == 16 && currentChar == '0') {
				if(*ptr == 'x' || *ptr == 'X') {
					currentChar = *(ptr + 1);
					ptr += 2;
				}
			}
			long maxValue = 0xFFFFFFFF / base;
			long maxLastDigit = 0xFFFFFFFF % base;
			unsigned short *var14 = *(unsigned short **) ((*(unsigned long *) &var24) + 0xC8);
			do {
				int digit;
				int characterFlags = *(var14 + currentChar);
				if(characterFlags & 4) {
					digit = currentChar - '0';
				} else {
					if(!(characterFlags & 0x103)) break;
					if((currentChar - 'a') <= 0x19)
						currentChar -= 0x20; //convert to upper-case
					digit = currentChar - 0x37;
				}
				if(digit >= base) break;
				flag |= 8;
				if(!allowOverflow && result >= maxValue && (result > maxValue || digit > maxLastDigit)) {
					flag |= 4; //overflow flag
					if(end == NULL) break;
				} else result = result * base + digit;
				currentChar = *(ptr++);
			} while(1);
			ptr--;
			if(!(flag & 8)) {
				if(end != NULL) ptr = str;
				result = 0;
			} else {
				if(flag & 4 || (!(flag & 1) && (flag & 2 || (result > 0x80000000)))){
					if(!arg6){
						errno = EINVAL;
						if(flag & 1) result = -1;
						else result = !!(flag & 2) + 0x7FFFFFFF;
					}
				}
			}
			if(end != NULL) *end = ptr;
			if(flag & 2) result = -result;
			if(var18b != 0) *(unsigned long *) ((*(unsigned long *) (((unsigned long *) var24) + 8)) + 0x70) &= 0xFFFFFFFD;
			return result;
		}
		if(end != NULL) *end = str;
	}
	if(var18b != 0) *(unsigned long *) ((*(unsigned long *) (((unsigned long *) var24) + 8)) + 0x70) &= 0xFFFFFFFD;
	return 0;
}
