//#include <cstdio>
//#include "List.h"
//
//int main() {
//#ifndef _OJ_
//	if (freopen("E:\\homework\\dataStructure\\02_zuma\\debug\\in.txt", "r", stdin) == NULL)  fprintf(stderr, "error redirecting stdin\n");
//	if (freopen("E:\\homework\\dataStructure\\02_zuma\\debug\\out.txt", "w", stdout) == NULL)  fprintf(stderr, "error redirecting stdout\n");
//#endif
//	setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
//	setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
//	List<char> ZumaList;  char c; int zumaLen = 0;
//	for (zumaLen = 0; (scanf("%c", &c) != EOF) && (c != '\n'); zumaLen++)  ZumaList.insertAsLast(c);
//	int oprNum = 0;  scanf("%d", &oprNum);
//	Rank *pos = new Rank[oprNum];
//	char *op = new char[oprNum];
//	for (int i = 0; i < oprNum; i++) {
//		scanf("%d", &pos[i]);
//		scanf("%c", &op[i]);
//		scanf("%c", &op[i]);
//	}
//	ListNodePos(char) p = NULL;
//	for (int i = 0; i < oprNum; i++) {
//		p = ZumaList.insertByRank(pos[i], op[i]);
//		ZumaList.zumaClear(p);
//		ZumaList.display();
//	}
//	delete[] pos;  delete[] op;
//	fclose(stdin);  fclose(stdout);
//	return 0;
//}