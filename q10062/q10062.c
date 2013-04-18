#include <stdio.h>
#include <stdlib.h>

int c[128+1][2];

int cmp(const void *a,const void *b) {
	if (((int *)a)[1] == ((int *)b)[1]) {
          return ((int *)b)[0]-((int *)a)[0];
        } else {
	  return ((int *)a)[1]-((int *)b)[1];
        }
}

int main() {
	char a;
	int i;
	
	/*freopen("test.in","r",stdin);*/
	
	for (i=1;i<=128;i++) {
		c[i][0] = i;
	}
	
	while (scanf("%c",&a)!=EOF) {
		if (a=='\n') {
			qsort(c,128+1,sizeof(c[0]),cmp);

			for (i=1;i<=128;i++) {
				if (c[i][1] != 0) {
					printf("%d %d\n",c[i][0],c[i][1]);
					c[i][1] =0;
				}
				c[i][0] = i;
			}
			printf("\n");
			continue;
		}
		
		c[a][1]++;
	}

	return 0;
}
