#include <stdio.h>
#include <string.h>
#include <math.h>

double distance[100][100];
double point[100][2];
char set[100];

int main() {
	int CaseN, N, i, j, k, casecount, count, minn[2];
	double dis,min,sum;
	
	scanf("%d",&CaseN);
	
	for (casecount=1;casecount<=CaseN;casecount++) {
		if (casecount!=1) {
			printf("\n");
		}
		
		scanf("%d",&N);
		
		memset(distance,0,sizeof(distance));
		memset(set,0,N);
		count = 1;
		sum = 0;
		
		for (j=0;j<N;j++) {
			scanf("%lf%lf",&point[j][0],&point[j][1]);
		}
		
		for (j=0;j<N;j++) {
			for (k=0;k<N;k++) {
				if (distance[j][k]==0 && j!=k) {
					dis = sqrt( (point[j][0]-point[k][0])*(point[j][0]-point[k][0]) + (point[j][1]-point[k][1])*(point[j][1]-point[k][1]) );
					distance[j][k] = dis;
					distance[k][j] = dis;
					//printf("dis:%f\n",dis);
				}
			}
		}
		set[0] = 1;
		while (count != N) {
			min = 2100000000;
			for (i=0;i<N;i++) {
				if (set[i]==1) {
					for (j=0;j<N;j++) {
						if (i!=j && set[j]==0 && distance[i][j]<min) {
							min = distance[i][j];
							minn[0] = i;
							minn[1] = j;
						}
					}
				}
			}
			//printf("x:%d y:%d\n",minn[0],minn[1]);
			sum += distance[minn[0]][minn[1]];
			set[minn[1]] = 1;
			count++;
		}

		printf("%.2lf\n",sum);
	}
	
//	system("pause");
	return 0;	
}
