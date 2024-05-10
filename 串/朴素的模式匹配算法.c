//string基本的数组

int Index(string s, string t, int pos)
{
	int i = pos;
	int j = 1;
	while (i <= strlen(s) && j <= strlen(t))
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		/*
指针后退重新开始匹配 */
		else
		{
			/* i退回到上次匹配首位的下一位 */
			i = i - j + 2;
			j = 1;
		}
	}
	if (j = strlen（t))
	{
	return i - j;
}
	else
		return 0;
}