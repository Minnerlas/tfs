all:
	gcc `pkg-config fuse --cflags --libs` *.c -o tfs
