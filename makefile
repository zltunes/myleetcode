clean:
	find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
