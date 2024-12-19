
int ds[];

int find(int i)
{
	while (i != ds[i])
		i = ds[i] = ds[ds[i]];
	return i;
}

void join(int i, int j)
{
	i = find(i);
	j = find(j);
	if (i != j)
		ds[i] = j;
}
