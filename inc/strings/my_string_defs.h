#pragma once 


#define fmt_str "%.*s"
#define arg_str(str) get_str_len(str), (str)

#define fmt_sv "%.*s"
#define arg_sv(sv) get_sv_len(sv), get_sv_str(sv)