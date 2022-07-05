#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void menu() {
	printf("************************************************************************\n");
	printf("************************  1.add     2.del    ***************************\n");
	printf("************************  3.search  2.modify ***************************\n");
	printf("************************  5.show    6.sort   ***************************\n");
	printf("************************        0.exit       ***************************\n");
	printf("************************************************************************\n");

}
int main() {
	int input = 0;
	//创建通讯录
	struct Contact con;//con是通讯录,里面包含1000个元素的数和size
	//初始化通讯录
	InitContact(&con);
	do {
		menu();
		cout << "请选择:>";
		cin >> input;
		switch (input) {
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			break;
		default:
			cout << "选择错误" << endl;
			break;
		}
	} while (input);
	return 0;
}