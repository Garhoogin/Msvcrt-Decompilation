void doexit(int status, int skipcleanup, int exitflag){
	if(!exitflag && check_managed_app()){
		__crtCorExitProcess(arg1);
	}
	_lock(8);
	var4 = 0;
	if(_C_Exit_Done != 1){
		_C_Termination_Done = 1;
		_exitflag = exitflag & 0xFF;
		if(!skipcleanup){
			var28 = _decode_pointer(__onexitbegin);
			void **var0 = var28;
			if(var28){
				var20 = _decode_pointer(__onexitend);
				var1C = var28
				void **var24 = var20;
				void **varesi, **vareax;
				while(1){
					do {
						var24--;
						if(var24 < var0) goto lb1;
						if(*var24 == _encoded_null()) continue;
						if(var24 < var0) goto lb1;
						*var24 = _encoded_null();
						((void (*) ()) _decode_pointer(*var24))();
						varesi = _decode_pointer(__onexitbegin);
						vareax = _decode_pointer(__onexitend)
						if(var1C != varesi) break;
					} while(var20 == vareax)
					var1C = varesi;
					var0 = var1C;
					var28 = var0;
					var20 = vareax;
					var24 = vareax;
				}
				lb1:
			}
		}
	}
	var4 = 0xFFFFFFFE;
	if(exitflag){
		_unlock(8);
	} else {
		_C_Exit_Done = 1;
		_unlockexit();
		__crtExitProcess(arg1);
	}
}
