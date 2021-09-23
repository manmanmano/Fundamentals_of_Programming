#include "stdio.h"
#include "memory.h"

int removeName(char*, char*);

int main() {
	char buf[81], name[81];
	printf("Type a list of names separated by comma\n");
	scanf("%s", buf);
	printf("Type the name to remove\n");
	scanf("%s", name);
	if (removeName(buf, name)) {
		printf("New list: %s\n", buf);
	}
	else {
		printf("Failed\n");
	}
}


	
	int removeName(char* pNames, char* pNameToRemove) {
		if (!pNames || !*pNames) {  // checks input data
			return 0;
		}
		if (!pNameToRemove || !*pNameToRemove) { // checks input data
			return 0;
		}
		int nNames = 0, nNameToRemove = 0;
		for (int i = 0; 1; i++) { // calculates the number of characters in initial list
			if (*(pNames + i)) {
				nNames++;
			}
			else {
				break;
			}
		}
		for (int i = 0; 1; i++) { // calculates the number of characters in the name we have to remove
			if (*(pNameToRemove + i)) {
				nNameToRemove++;
			}
			else {
				break;
			}
		}
		int i;
		for (i = 0; i < nNames; i++) { // find the index from which the name to remove begins
			if (!memcmp(pNames + i, pNameToRemove, nNameToRemove)) {//if memcmp(...) == 0
				break;
			}
		}
		if (i == nNames) { // not found
			return 0;
		}
		if (*(pNames + i + nNameToRemove)) {//if *(...) != 0 
		 // the name to remove is not the last name in list
			memmove(pNames + i, pNames + i + nNameToRemove + 1, nNames - (i + nNameToRemove));
		}
		else { // the name to remove is the last: just put the terminating zero on the place of last comma
			*(pNames + i - 1) = 0;
		}
		return 1;
	}
