void get_next(string t, int* next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < strlen(t))
	{
		if (j == 0 || t[i]== t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	} 
  }
int Index_KMP(string s, string t, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next(t, next);
	while (i <= strlen(s) && j <= strlen(t))
	{
		if (j == 0 || s[i] == t[j])
		{
			j++;
			i++;
		}
		else {
			j = next[j];
		}
	}
	if (j > strlen(t))
	return i - strlen(t);
	else
		return 0;
}

void get_nextval(string t, int* nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < strlen(t))
	{
		if (j == 0 || t[i] == t[j])
		{
			i++;
			j++;
			if (t[i] != t[j])
			{
				nextval[i] = j;
			}
			else 
/*如果与前缀字符相同，则将前缀 */
/*字符的nextval值赋值给nextval在i位置的值 */

				nextval[i] = nextval[j];
		}
		else
/*若字符不相同，则j值回溯 */
			j = nextval[j];
	}
}