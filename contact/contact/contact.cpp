#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(struct Contact* ps) {
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//设置通讯录最初只有0个元素
}
void AddContact(struct Contact* ps) {
	if (ps->size == MAX) {
		cout << "通讯录已满，无法再增加" << endl;
	}
	else {
		cout << "请输入名字:>";
		scanf("%s", ps->date[ps->size].name);
		cout << "请输入年龄:>";
		scanf("%d", &(ps->date[ps->size].age));
		cout << "请输入性别:>";
		scanf("%s", ps->date[ps->size].sex);
		cout << "请输入电话:>";
		scanf("%s", ps->date[ps->size].tele);
		cout << "请输入地址:>";
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		cout << "添加成功" << endl;
	}
}

void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		cout << "通讯录为空格" << endl;
	}
	else {
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话","地址");
		for (int i = 0; i < ps->size; i++) {
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr
			);
		}		
	}
}

static int FindBYName(const struct Contact* ps,char name[MAX_NAME]) {
	for (int i = 0; i < ps->size; i++)
		if (!strcmp(ps->date[i].name, name))
			return i;
	return -1;//找不到的情况
}

void DelContact(struct Contact* ps) {
	char name[MAX_NAME];
	cout << "请输入要删除人的名字:>";
	cin >> name;
	//1.查找要删除的人在什么位置
	//找到了返回名字所在的坐标，找不到返回-1
	int pos = FindBYName(ps, name);
	if (pos==-1) {
		cout<<"要删除的人不存在"<<endl;
	}
	else {
		//2.删除
		int j=0;
		for (j = pos; j < ps->size-1; j++) {
			ps->date[j] = ps->date[j];
		}
		ps->size--;
		cout << "删除成功" << endl;
	}
}

void SearchContact(const struct Contact* ps) {
	cout << "请输入要查找人的名字" << endl;
	char name[MAX_NAME];
	cin >> name;
	int pos = FindBYName(ps, name);
	if (pos == -1) {
		cout << "要查找的人不存在" << endl;
	}
	else {
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");		
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr
		);		
	}
}

void ModifyContact(struct Contact* ps) {
	cout << "请输入要修改人的名字" << endl;
	char name[MAX_NAME];
	cin >> name;
	int pos = FindBYName(ps, name);
	if (pos == -1) {
		cout << "要查找的人不存在" << endl;
	}
	else {
		cout << "请输入名字:>";
		scanf("%s", ps->date[ps->size].name);
		cout << "请输入年龄:>";
		scanf("%d", &(ps->date[ps->size].age));
		cout << "请输入性别:>";
		scanf("%s", ps->date[ps->size].sex);
		cout << "请输入电话:>";
		scanf("%s", ps->date[ps->size].tele);
		cout << "请输入地址:>";
		scanf("%s", ps->date[ps->size].addr);
		cout << "修改完成"<<endl;
	}
}