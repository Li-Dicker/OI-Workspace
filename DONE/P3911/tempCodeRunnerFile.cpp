int i=2;i<=n;i++)
	{
		if (!vis[i])
			prime[++tot]=i,miu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			vis[i*prime[j]]=1;
			if (i%prime[j]==0)
			{
				miu[i*prime[j]]=0;
				break ;
			}
			else
				miu[i*prime[j]]=-miu[i];
		}
	}