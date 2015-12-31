/* Generated by re2c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192


enum ScanContition {
	EStateNormal,
	EStateComment,
	EStateSkiptoeol,
	EStateString,
};


typedef struct Scanner
{
	FILE			    *fp;
	unsigned char	    *cur, *tok, *lim, *eof;
	unsigned char 	    buffer[BSIZE];
	unsigned char       yych;
	enum ScanContition  cond;
	int                 state;
} Scanner;

size_t fill(Scanner *s, size_t len)
{
	size_t got = ~0, cnt;

	if (!s->eof && s->lim - s->tok < len)
	{
		if (s->tok > s->buffer)
		{
			cnt = s->tok - s->buffer;
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
			cnt = &s->buffer[BSIZE] - s->lim;
		}
		else
		{
			cnt = BSIZE;
		}
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	if (s->eof && s->cur + len > s->eof)
	{
		return ~0; /* not enough input data */
	}
	return got;
}

size_t init(Scanner *s)
{
	s->cur = s->tok = s->lim = s->buffer;
	s->eof = 0;
	s->cond = EStateNormal;
	s->state = -1;

	return fill(s, 0);
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

void scan(Scanner *s)
{
	s->tok = s->cur;

	switch (s->state) {
	default: goto yy0;
	case 0: goto yyFillLabel0;
	case 1: goto yyFillLabel1;
	case 2: goto yyFillLabel2;
	case 3: goto yyFillLabel3;
	}
	for(;;)
	{
		s->tok = s->cur;


yy0:
		if (s->cond < 2) {
			if (s->cond < 1) {
				goto yyc_Normal;
			} else {
				goto yyc_Comment;
			}
		} else {
			if (s->cond < 3) {
				goto yyc_Skiptoeol;
			} else {
				goto yyc_String;
			}
		}
/* *********************************** */
yyc_Comment:
		s->state = 0;(0);
		if ((s->lim - s->cur) < 2) if(fill(s, 2) == ~0) break;
yyFillLabel0:
		s->yych = *s->cur;
		if (s->yych == '*') goto yy5;
		++s->cur;
yy4:
		{
				goto yyc_Comment;
			}
yy5:
		s->yych = *++s->cur;
		if (s->yych != '/') goto yy4;
		++s->cur;
		s->cond = EStateNormal;(EStateNormal);
		{
				continue;
			}
/* *********************************** */
yyc_Normal:
		s->state = 1;(1);
		if ((s->lim - s->cur) < 4) if(fill(s, 4) == ~0) break;
yyFillLabel1:
		s->yych = *s->cur;
		if (s->yych <= '\'') {
			if (s->yych == '"') goto yy12;
			if (s->yych >= '\'') goto yy14;
		} else {
			if (s->yych <= '/') {
				if (s->yych >= '/') goto yy15;
			} else {
				if (s->yych == '?') goto yy16;
			}
		}
		++s->cur;
yy11:
		{
				fputc(s->cur[-1], stdout);
				continue;
			}
yy12:
		++s->cur;
		s->cond = EStateString;(EStateString);
		{
				fputc(s->cur[-1], stdout);
				continue;
			}
yy14:
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '"') goto yy17;
		if (s->yych == '\\') goto yy19;
		goto yy11;
yy15:
		s->yych = *++s->cur;
		if (s->yych == '*') goto yy20;
		if (s->yych == '/') goto yy22;
		goto yy11;
yy16:
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '?') goto yy24;
		goto yy11;
yy17:
		s->yych = *++s->cur;
		if (s->yych == '\'') goto yy25;
yy18:
		s->cur = s->tok;
		goto yy11;
yy19:
		s->yych = *++s->cur;
		if (s->yych == '"') goto yy17;
		goto yy18;
yy20:
		++s->cur;
		s->cond = EStateComment;(EStateComment);
		{
				goto yyc_Comment;
			}
yy22:
		++s->cur;
		s->cond = EStateSkiptoeol;(EStateSkiptoeol);
		{
				goto yyc_Skiptoeol;
			}
yy24:
		s->yych = *++s->cur;
		switch (s->yych) {
		case '!':	goto yy27;
		case '\'':	goto yy29;
		case '(':	goto yy31;
		case ')':	goto yy33;
		case '-':	goto yy35;
		case '/':	goto yy37;
		case '<':	goto yy39;
		case '=':	goto yy41;
		case '>':	goto yy43;
		default:	goto yy18;
		}
yy25:
		++s->cur;
		{
				fputl("'\"'", 3, stdout);
				continue;
			}
yy27:
		++s->cur;
		{
				fputc('|', stdout);
				continue;
			}
yy29:
		++s->cur;
		{
				fputc('^', stdout);
				continue;
			}
yy31:
		++s->cur;
		{
				fputc('[', stdout);
				continue;
			}
yy33:
		++s->cur;
		{
				fputc(']', stdout);
				continue;
			}
yy35:
		++s->cur;
		{
				fputc('~', stdout);
				continue;
			}
yy37:
		++s->cur;
		{
				fputc('\\', stdout);
				continue;
			}
yy39:
		++s->cur;
		{
				fputc('{', stdout);
				continue;
			}
yy41:
		++s->cur;
		{
				fputc('#', stdout);
				continue;
			}
yy43:
		++s->cur;
		{
				fputc('}', stdout);
				continue;
			}
/* *********************************** */
yyc_Skiptoeol:
		s->state = 2;(2);
		if ((s->lim - s->cur) < 5) if(fill(s, 5) == ~0) break;
yyFillLabel2:
		s->yych = *s->cur;
		if (s->yych <= '\r') {
			if (s->yych == '\n') goto yy49;
			if (s->yych >= '\r') goto yy51;
		} else {
			if (s->yych <= '?') {
				if (s->yych >= '?') goto yy52;
			} else {
				if (s->yych == '\\') goto yy53;
			}
		}
		++s->cur;
yy48:
		{
				goto yyc_Skiptoeol;
			}
yy49:
		++s->cur;
		s->cond = EStateNormal;(EStateNormal);
		{
				fputc('\n', stdout);
				continue;
			}
yy51:
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy54;
		goto yy48;
yy52:
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '?') goto yy56;
		goto yy48;
yy53:
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '\n') goto yy58;
		if (s->yych == '\r') goto yy60;
		goto yy48;
yy54:
		++s->cur;
		s->cond = EStateNormal;(EStateNormal);
		{
				fputc('\r', stdout);
				fputc('\n', stdout);
				continue;
			}
yy56:
		s->yych = *++s->cur;
		if (s->yych == '/') goto yy61;
yy57:
		s->cur = s->tok;
		goto yy48;
yy58:
		++s->cur;
		{
				goto yyc_Skiptoeol;
			}
yy60:
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy58;
		goto yy57;
yy61:
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy62;
		if (s->yych == '\r') goto yy64;
		goto yy57;
yy62:
		++s->cur;
		{
				goto yyc_Skiptoeol;
			}
yy64:
		++s->cur;
		if ((s->yych = *s->cur) == '\n') goto yy62;
		goto yy57;
/* *********************************** */
yyc_String:
		s->state = 3;(3);
		if ((s->lim - s->cur) < 2) if(fill(s, 2) == ~0) break;
yyFillLabel3:
		s->yych = *s->cur;
		if (s->yych == '"') goto yy69;
		if (s->yych == '\\') goto yy71;
		++s->cur;
yy68:
		{
				fputc(s->cur[-1], stdout);
				continue;
			}
yy69:
		++s->cur;
		s->cond = EStateNormal;(EStateNormal);
		{
				fputc(s->cur[-1], stdout);
				continue;
			}
yy71:
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy68;
		++s->cur;
		{
				fputl((const char*)s->cur-2, 2, stdout);
				continue;
			}

	}
}

int main(int argc, char **argv)
{
	Scanner in;

	if (argc != 2)
	{
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;;
	}

	memset((char*) &in, 0, sizeof(in));

	if (!strcmp(argv[1], "-"))
	{
		in.fp = stdin;
	}
	else if ((in.fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file '%s'\n", argv[1]);
		return 1;
	}

	if (init(&in) > 0)
	{
 		scan(&in);
 	}

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
