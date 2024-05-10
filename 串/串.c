#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 5
typedef struct string {
	ElemType data[MAXSIZE];
	struct string* next;
}string;
status Enstring(string* s,ElemType l)
{
	if (s == NULL )
	{
		return ERROR;
	}
	string* p = s;
	int i = 0;
	while (p->data[i] != '\0')
	{
		i++;
		if (i == MAXSIZE)
		{
			if (p->next == NULL)
			{
				string* new = (string*)malloc(sizeof(string));
				if (new == NULL)
					return ERROR;
				new->next = NULL;
				p->next = new;
			}
			
			i = 0;
			p = p->next;
		}
	}
	if (i == MAXSIZE - 1)
	{
		string* new = (string*)malloc(sizeof(string));
		if (new == NULL)
			return ERROR;
		new->next = NULL;
		p->next = new;
		p->data[i] = l;
		p = p->next;
		p->data[0] = '\0';
	}
	else {
		p->data[i] = l;
		p->data[i + 1] = '\0';
	}
	return OK;
}

status strCopy(string* t,string* s)
{
	if ( s== NULL || t ==NULL)
	{
		return ERROR;
	}
	string* tem = t;
	while (s)
	{
		int i;
		for (i = 0; i < MAXSIZE && s->data[i]!='\0'; i++)
		{
			tem->data[i] = s->data[i];
		}
		if (s->next)
		{
			string* temp = (string*)malloc(sizeof(string));
			if(temp == NULL)
			{
				return ERROR;
			}
			tem->next = temp;
			tem = temp;
		}
		else
		{
			tem->next = NULL;
		}
		s = s->next;
	}
	return OK;
}
int  strLength(const string* s)
{
	if (s == NULL)
		return 0;
	string* p=s;
	int count = 0;
	while (p)
	{
		for (int i = 0; i < MAXSIZE && p->data[i]!='\0'; i++)
		{
			count++;
		}
		p = p->next;
	}
	return count;
}
int  strCompare(const string* s, const string* t)
{
	int n = strLength(s);
	int m = strLength(t);
	if (n == m)
	{
		while (n)
		{
			for (int i = 0; i < MAXSIZE; i++)
			{
				n--;
				if (s->data[i] > t->data[i])
					return 1;
				if (s->data[i] < t->data[i])
					return -1;
			}
			s = s->next;
			t = t->next;
		}
		return 0;
	}
	else if (n > m)
	{
		return 1;
	}
	else
		return -1;
}
status Substring(string* sub, string* s, int pos, int length)
{
	if (s == NULL || sub == NULL || pos < 1 || length < 0)
		return ERROR;

	int L = strLength(s);
	if (pos > L || length > L - pos + 1) 
		return ERROR;
	int count = 0;
	int startNode = (pos - 1) / MAXSIZE;
	int startPos = (pos - 1) % MAXSIZE;
	string* p = s;
	for (int i = 0; i < startNode; i++)
	{
		if (p->next = NULL)
			return ERROR;
		p= p->next;
	}
	
	while (count<length)
	{

		s = s->next;
		for (int i = startPos; i < MAXSIZE && count<length; i++)
		{
			if (p->data[i] = '\0')
				return ERROR;
			Enstring(sub, s->data[i]);
			count++;		
		}	
		p = p->next;
		startPos = 0;
	}
	return OK;
}

status Index(string* s, string* t, int pos)
{
	int n, m, i;
	string* sub;
	if (pos > 0)
	{
		n = strLength(s);
		m = strLength(t);
		i = pos;
		while (i <= n - m + 1)
		{
			Substring(sub, s, i, m);
			if (strCompare(sub, t) != 0)
			{
				i++;
			}
			else
				return i;

		}
	}
	return 0;
}