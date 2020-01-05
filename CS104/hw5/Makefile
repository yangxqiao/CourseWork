all: twitter

twitter: twitter.cpp twiteng.o util.o user.o datetime.o tweet.o handler.o cmdhandler.o
	g++ -g -Wall -std=c++11 twitter.cpp twiteng.o user.o util.o handler.o cmdhandler.o datetime.o tweet.o -o twitter 

user.o: user.cpp user.h tweet.h hsort.h
	g++ -g -Wall -c user.cpp -o user.o

datetime.o: datetime.cpp datetime.h 
	g++ -g -Wall -c datetime.cpp -o datetime.o

tweet.o: tweet.cpp tweet.h util.h user.h datetime.h 
	g++ -g -Wall -c tweet.cpp -o tweet.o

twiteng.o: twiteng.cpp twiteng.h util.h user.h datetime.h tweet.h 
	g++ -g -Wall -c twiteng.cpp -o twiteng.o

util.o: util.cpp util.h tweet.h hsort.h 
	g++ -g -Wall -c util.cpp -o util.o

handler.o: handler.cpp handler.h twiteng.h
	g++ -g -Wall -c handler.cpp -o handler.o

cmdhandler.o: cmdhandler.cpp cmdhandler.h tweet.h datetime.h util.h
	g++ -g -Wall -c cmdhandler.cpp -o cmdhandler.o