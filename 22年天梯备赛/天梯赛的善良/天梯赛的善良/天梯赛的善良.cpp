#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n, a[20000], max = 0, min = 2000000, mi = 0, ma = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
			ma++;
		if (a[i] == min)
			mi++;
	}
	printf("%d %d\n", min, mi);
	printf("%d %d\n", max, ma);

	return 0;
}
