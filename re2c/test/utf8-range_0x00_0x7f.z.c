/* Generated by re2c */
#line 1 "utf8-range_0x00_0x7f.z.re"

#line 5 "<stdout>"
{
	YYCTYPE yych;

	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x7F) goto yy3;
yy3:
	++YYCURSOR;
#line 2 "utf8-range_0x00_0x7f.z.re"
	{ return 0; }
#line 16 "<stdout>"
}
#line 3 "utf8-range_0x00_0x7f.z.re"
