#include <stdio.h>
#include <stdlib.h>
#include <string.h> //string library

void strcp1(char *dst, const char *src)
{
	// if dst is the same as source, just return
	if(dst != src){
		// copy source characters to dst until we hit a null character
		while(*src){
			*dst++ = *src++;
		}
		//we have found the null src character, no copy that to the dst to end dst
		*dst = *src;
	}
}
int main()
{
	char name[] = "genevieve";
	printf("<0x%08x> name: %s, length: %ld, sizeof: %ld\n",&name, name, strlen(name), sizeof(name));
	
	char name2[sizeof name];
	printf("<0x%08x> name2 : %s, length: %ld, sizeof: %ld\n",&name2, name2, strlen(name2),sizeof name2);
	
	strcp1(name2, name);
        printf("<0x%08x> name2 : %s, length: %ld, sizeof: %ld\n",&name2, name2, strlen(name2),sizeof name2);

	int i;
	for( i=0; i<sizeof(name2); i++){
		name2[i] = '*';
	}
	printf("<0x%08x> name2 : %s, length: %ld, sizeof: %ld\n",&name2, name2, strlen(name2),sizeof name2);

        strcp1(name2, name);
        printf("<0x%08x> name2 : %s, length: %ld, sizeof: %ld\n",&name2, name2, strlen(name2),sizeof name2);

	char *name3 = malloc(sizeof name);
        printf("<0x%08x> name3 : %s, length: %ld, sizeof: %ld\n",&name3, name3, strlen(name3),sizeof name3);

	strcp1(name3,name);
        printf("<0x%08x> name3 : %s, length: %ld, sizeof: %ld\n",&name3, name3, strlen(name3),sizeof name3);

	free(name3);
        printf("<0x%08x> name3 : %s, length: %ld, sizeof: %ld\n",&name3, name3, strlen(name3),sizeof name3);

	return 0;
}
