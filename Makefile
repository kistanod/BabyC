CC = gcc
CWARN = -Wall -Wextra
DBGCFLAGS = -g -O0

all: Parser Scanner YourCode 
	$(CC) $(CWARN) BabyC.tab.o lex.yy.o driver.o your_code.o -o bcc

debug: BabyC.l BabyC.y driver.c your_code.c
	bison -d BabyC.y
	$(CC) $(DBGCFLAGS) -c BabyC.tab.c
	flex BabyC.l
	$(CC) $(DBGCFLAGS) -c lex.yy.c
	$(CC) $(CWARN) $(DBGCFLAGS) -c driver.c your_code.c
	$(CC) $(CWARN) $(DBGCFLAGS) BabyC.tab.o lex.yy.o driver.o your_code.o -o debug_bcc

YourCode: your_code.o driver.o 

Scanner: BabyC.l 
	flex BabyC.l
	$(CC) -c lex.yy.c

Parser: BabyC.y  
	bison -d BabyC.y
	$(CC) -c BabyC.tab.c

%.o: %.c 
	$(CC) $(CWARN) -c $<

clean:
	rm -f *.o 
	rm -f *.yy.* 
	rm -f *.tab.* 
	rm -f bcc
	rm -f debug_bcc
