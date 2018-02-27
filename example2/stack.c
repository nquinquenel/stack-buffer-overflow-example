#include <stdio.h>

answer() {
	printf("It worked!\n");
}

useless() {
	printf("It failed.\n");
}

int main() {
	void (*func)() = useless();
	char arr[10];
	fgets(arr, 15, stdin);
	useless();
	return 0;
}
