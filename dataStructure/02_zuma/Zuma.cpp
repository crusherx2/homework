#include <cstdio>





int main() {
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	char zuma[10000] = { 0 }; int zumaLen = 0;
	for (zumaLen = 0; (scanf("%c", &zuma[zumaLen]) != EOF) && (zuma[zumaLen] != '\n'); zumaLen++);
	int oprNum = 0;  scanf("%d", &oprNum);
	int *pos = new int[oprNum];
	char *op = new char[oprNum];
	for (int i = 0; i < oprNum; i++) {
		scanf("%d", &pos[oprNum]);
		scanf("%c", &op[oprNum]);
	}

	return 0;
}