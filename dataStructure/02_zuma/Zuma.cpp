#include <cstdio>

int main() {
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	int lenNum, lenRange = 0;
	scanf("%d %d\n", &lenNum, &lenRange);

	return 0;
}