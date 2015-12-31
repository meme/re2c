/* Generated by re2c */
#line 1 "unicode_group_Nl.x--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Nl:
	
#line 13 "unicode_group_Nl.x--encoding-policy(substitute).c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x3020) {
		if (yych <= 0x2182) {
			if (yych <= 0x16ED) goto yy2;
			if (yych <= 0x16F0) goto yy4;
			if (yych >= 0x2160) goto yy4;
		} else {
			if (yych <= 0x2188) {
				if (yych >= 0x2185) goto yy4;
			} else {
				if (yych == 0x3007) goto yy4;
			}
		}
	} else {
		if (yych <= 0xA6EF) {
			if (yych <= 0x3037) {
				if (yych <= 0x3029) goto yy4;
			} else {
				if (yych <= 0x303A) goto yy4;
				if (yych >= 0xA6E6) goto yy4;
			}
		} else {
			if (yych <= 0xD800) {
				if (yych >= 0xD800) goto yy6;
			} else {
				if (yych == 0xD809) goto yy7;
			}
		}
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "unicode_group_Nl.x--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 50 "unicode_group_Nl.x--encoding-policy(substitute).c"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_Nl.x--encoding-policy(substitute).re"
	{ goto Nl; }
#line 55 "unicode_group_Nl.x--encoding-policy(substitute).c"
yy6:
	yych = *++YYCURSOR;
	if (yych <= 0xDF41) {
		if (yych <= 0xDD3F) goto yy3;
		if (yych <= 0xDD74) goto yy4;
		if (yych <= 0xDF40) goto yy3;
		goto yy4;
	} else {
		if (yych <= 0xDF4A) {
			if (yych <= 0xDF49) goto yy3;
			goto yy4;
		} else {
			if (yych <= 0xDFD0) goto yy3;
			if (yych <= 0xDFD5) goto yy4;
			goto yy3;
		}
	}
yy7:
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= 0xDBFF) goto yy3;
	if (yych <= 0xDC62) goto yy4;
	goto yy3;
}
#line 14 "unicode_group_Nl.x--encoding-policy(substitute).re"

}
static const unsigned int chars_Nl [] = {0x16ee,0x16f0,  0x2160,0x2182,  0x2185,0x2188,  0x3007,0x3007,  0x3021,0x3029,  0x3038,0x303a,  0xa6e6,0xa6ef,  0x10140,0x10174,  0x10341,0x10341,  0x1034a,0x1034a,  0x103d1,0x103d5,  0x12400,0x12462,  0x0,0x0};
static unsigned int encode_utf16 (const unsigned int * ranges, unsigned int ranges_count, unsigned short * s)
{
	unsigned short * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
		{
			if (j <= re2c::utf16::MAX_1WORD_RUNE)
				*s++ = j;
			else
			{
				*s++ = re2c::utf16::lead_surr(j);
				*s++ = re2c::utf16::trail_surr(j);
			}
		}
	return s - s_start;
}

int main ()
{
	YYCTYPE * buffer_Nl = new YYCTYPE [450];
	unsigned int buffer_len = encode_utf16 (chars_Nl, sizeof (chars_Nl) / sizeof (unsigned int), buffer_Nl);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Nl), reinterpret_cast<const YYCTYPE *> (buffer_Nl + buffer_len)))
		printf("test 'Nl' failed\n");
	delete [] buffer_Nl;
	return 0;
}
