&&q<=1000)
	{
		for (int i=1;i<=n;i++)
			sum[0][i]=0;
		for (int i=1;i<=q;i++)
		{
			op=opt[i].op=input(),tmp1=opt[i].l=input(),opt[i].r=tmp2=input();
			if (op==1)
			{
				for (int j=1;j<tmp1;j++)
					sum[i][j]=sum[i-1][j];
				for (int j=tmp1;j<=tmp2;j++)
					sum[i][j]=(sum[i-1][j]+1)%MOD;
				for (int j=tmp2+1;j<=n;j++)
					sum[i][j]=sum[i-1][j];
			}
			else if (op==2)
			{
				for (int j=1;j<=n;j++)
					sum[i][j]=(sum[i-1][j]+sum[tmp2][j]-sum[tmp1-1][j])%MOD;
			}
		}
		for (int i=1;i<=n;i++)
			print(sum[q][i]%MOD,' ');
		puts("");
		return 0;
	}