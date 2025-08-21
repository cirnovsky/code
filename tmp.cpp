	if (a[0][1] == -1 && a[1][0] == -1)
	{
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 1; j <= k; ++j)
			{
				dp[0][max(0, j - i)]++;
			}
		}
	}
	else if (a[0][1] != -1 && a[1][0] != -1)
	{
		dp[0][max(0, a[1][0] - a[0][1])]++;
	}
	else if (a[0][1] == -1)
	{
		for (int i = 1; i <= k; ++i)
		{
			dp[0][max(0, a[1][0] - i)]++;
		}
	}
	else
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[0][max(0, j - a[0][1])]++;
		}
	}

		if (A == -1 && B == -1)
		{
			for (int u = 1; u <= k; ++u)
			{
				for (int v = 1; v <= u; ++v)
				{
					for (int j = -k; j + u - v <= 0; ++j)
					{
						inc(dp[i][-(j + u - v)], dp[i - 1][-j]);
					}
				}
				for (int v = u + 1; v <= k; ++v)
				{
					inc(dp[i][-(u - v)], 1);
				}
			}
		}
		else if (A == -1)
		{
			for (int u = 1; u <= k; ++u)
			{
				if (u < B)
				{
					inc(dp[i][-(u - B)], 1);
				}
				else
				{
					for (int j = -k; j + u - B <= 0; ++j)
					{
						inc(dp[i][-(j + u - B)], dp[i - 1][-j]);
					}
				}
			}
		}
		else if (B == -1)
		{
			for (int v = 1; v <= k; ++v)
			{
				if (A < v)
				{
					inc(dp[i][-(A - v)], 1);
				}
				else
				{
					for (int j = -k; j + A - v <= 0; ++j)
					{
						inc(dp[i][-(j + A - v)], dp[i - 1][-j]);
					}
				}
			}
		}
		else
		{
			if (A < B)
			{
				inc(dp[i][-(A - B)], 1);
			}
			else
			{
				for (int j = -k; j + A - B <= 0; ++j)
				{
					inc(dp[i][-(j + A - B)], dp[i - 1][-j]);
				}
			}
		}
