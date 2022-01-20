#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct item {
	char* pName;
	int quantity, write_off; //write_off: 0 if not expired yet, if expired
}ITEM;

ITEM* Exam(char* pInput, char* pItemName);

int main()
{
	char input[] =
		"[ Name: Mackerel   Quantity: 1000   Expires: 10-2018   ]   [ Quantity: 500   Name: Sardine   Expires: 12-2017   ]   [ Expires: 3-2021   Quantity: 10000    Name: Tuna   ] ";
	ITEM* item = Exam(input, (char*)("Tuna"));
	printf("Product name: %s\n\nIn stock: %d\n\nExpired: ", item->pName, item->quantity);
	if (item->write_off == 0)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}

ITEM* Exam(char* pInput, char* pItemName)
{
	if (!pInput || !pItemName || !*pItemName || !*pInput)
	{
		return 0;
	}
	ITEM* item = (ITEM*)malloc(sizeof(ITEM));
	char* begin = strstr(pInput, pItemName);
	char* end = strchr(begin, ' ');
	*end = 0;
	item->pName = (char*)malloc(strlen(begin) + 1);
	strcpy(item->pName, begin);
	*end = ' ';
	end = strchr(begin, ']');
	*end = 0;
	begin = strrchr(pInput, '[');
	char* found = strstr(begin, "Quantity");
	found = strpbrk(found, "0123456789");
	item->quantity = atoi(found);
	found = strstr(begin, "Expires");
	found = strpbrk(found, "0123456789");
	int month = atoi(found);
	found = strchr(found, '-');
	found = strpbrk(found, "0123456789");
	int year = atoi(found);
	if (year < 2021 || year == 2021 && month <= 1)
	{
		item->write_off = 1;
	}
	else
	{
		item->write_off = 0;
	}
	return item;
}
