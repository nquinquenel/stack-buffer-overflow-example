#include <stdio.h>

void answer() {
	printf("It worked!\n");
}

void useless() {
	printf("It failed.\n");
}

int main() {
	void (*func)() = useless;
	char arr[10];
	fgets(arr, 15, stdin);
	func();
	return 0;
}
