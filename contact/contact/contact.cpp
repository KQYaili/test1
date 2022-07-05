#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(struct Contact* ps) {
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}
void AddContact(struct Contact* ps) {
	if (ps->size == MAX) {
		cout << "ͨѶ¼�������޷�������" << endl;
	}
	else {
		cout << "����������:>";
		scanf("%s", ps->date[ps->size].name);
		cout << "����������:>";
		scanf("%d", &(ps->date[ps->size].age));
		cout << "�������Ա�:>";
		scanf("%s", ps->date[ps->size].sex);
		cout << "������绰:>";
		scanf("%s", ps->date[ps->size].tele);
		cout << "�������ַ:>";
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		cout << "��ӳɹ�" << endl;
	}
}

void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		cout << "ͨѶ¼Ϊ�ո�" << endl;
	}
	else {
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰","��ַ");
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
	return -1;//�Ҳ��������
}

void DelContact(struct Contact* ps) {
	char name[MAX_NAME];
	cout << "������Ҫɾ���˵�����:>";
	cin >> name;
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ��˷����������ڵ����꣬�Ҳ�������-1
	int pos = FindBYName(ps, name);
	if (pos==-1) {
		cout<<"Ҫɾ�����˲�����"<<endl;
	}
	else {
		//2.ɾ��
		int j=0;
		for (j = pos; j < ps->size-1; j++) {
			ps->date[j] = ps->date[j];
		}
		ps->size--;
		cout << "ɾ���ɹ�" << endl;
	}
}

void SearchContact(const struct Contact* ps) {
	cout << "������Ҫ�����˵�����" << endl;
	char name[MAX_NAME];
	cin >> name;
	int pos = FindBYName(ps, name);
	if (pos == -1) {
		cout << "Ҫ���ҵ��˲�����" << endl;
	}
	else {
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");		
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
	cout << "������Ҫ�޸��˵�����" << endl;
	char name[MAX_NAME];
	cin >> name;
	int pos = FindBYName(ps, name);
	if (pos == -1) {
		cout << "Ҫ���ҵ��˲�����" << endl;
	}
	else {
		cout << "����������:>";
		scanf("%s", ps->date[ps->size].name);
		cout << "����������:>";
		scanf("%d", &(ps->date[ps->size].age));
		cout << "�������Ա�:>";
		scanf("%s", ps->date[ps->size].sex);
		cout << "������绰:>";
		scanf("%s", ps->date[ps->size].tele);
		cout << "�������ַ:>";
		scanf("%s", ps->date[ps->size].addr);
		cout << "�޸����"<<endl;
	}
}