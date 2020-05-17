all: tcp_app udp_app

tcp_app: tcp_client tcp_server

udp_app: udp_client udp_server

tcp_client: tcpclient.c
	gcc -o tcpclient.o tcpclient.c

udp_client: udpclient.c
	gcc -o udpclient.o udpclient.c

tcp_server: tcpserver.c
	gcc -o tcpserver.o tcpserver.c

udp_server: udpserver.c
	gcc -o udpserver.o udpserver.c

clean:
	rm *.out *.o -f
	clear