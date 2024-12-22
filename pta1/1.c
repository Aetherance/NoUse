#include <stdio.h>
int main() {
	int _1[10000] = {}, _2[10000] = {}, _3[10000] = {}, _4[10000] = {};
	int p, q, i, j, flag__ = 1;

	scanf("%d", &p);

	for (i = 0; i < p; i++) 
		scanf("%d", &_1[i]);

	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &_2[i]);


	for (i = 0; i < p; i++) {
		for (j = 0; j < q; j++) {
			if (_1[i] == _2[j]) {
				_3[i] = 1;
				break;
			}
		}
	}


    int flag;
	for (i = 0; i < q; i++) {
		for (j = 0; j < p; j++) {
			if (_2[i] == _1[j]) {
				_4[i] = 1;
				break;
			}
		}
	}


	for (i = 0; i < p; i++) {
		int flag = 1;
		if (_3[i] == 0) {
			for (j = 0; j < i; j++) {
				if (_1[i] == _1[j]) {
					flag = 0;
				}
			}
			if (flag) {
				if (flag__) {
					printf("%d", _1[i]);
					flag__ = 0;
				}
				else {
					printf(" %d", _1[i]);
				}
			}
		}
	}


for (i = 0; i < q; i++) {
int flag = 1;
if (_4[i] == 0) {
for (j = 0; j < i; j++) {
        if (_2[i] == _2[j]) {
            flag = 0;
        }
    }
    
    if (flag) {
        if (flag__) {
            printf("%d", _2[i]);
        }
    else {
        printf(" %d", _2[i]);
        }
    }
}
}


	return 0;
}