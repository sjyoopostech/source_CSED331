#include <stdio.h>

int main() {
	int i, n, t, c;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		c = 0;
		scanf("%d", &n);
		c += n/50000;
		n -= (n/50000)*50000;
		c += n/10000;
		n -= (n/10000)*10000;
		c += n/5000;
		n -= (n/5000)*5000;
		c += n/1000;
		n -= (n/1000)*1000;
		printf("%d\n", c);		

	}
	return 0;
}