#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Tree
{ 
	int *data;
	Tree **ptr;
}*Root=NULL;
int m;

Tree* Create()
{
	Tree* temp; int i = 0;
	temp = new Tree;
	temp->data =new int[m-1];
	temp->ptr=new Tree*[m];
	while (i < m)
	{
		temp->ptr[i] = NULL;
		if (i < m - 1)
			temp->data[i] = NULL;
		i++;
	}
	cout << "Enter the Data to Insert:";
	cin >> temp->data[0];
	return temp;
}

Tree* Insert(Tree* temp,Tree* New)
{
	if (Root == NULL)
		temp =New;
	else
	{
		for (int i = 0;i < m;i++)
		{
			if (i < m - 1 && temp->data[i] == NULL)
			{
				if (i + 1 < m - 1)
				{
					if (temp->data[i + 1] == NULL)
						temp->data[i] = New->data[0];
					else if (temp->data[i + 1] > New->data[0])
						temp->data[i] = New->data[0];
				}
				else
					temp->data[i] = New->data[0];
				break;
			}
			else if (i<m-1 && New->data[0] < temp->data[i])
			{
				if (temp->ptr[i] == NULL)
					temp->ptr[i] = New;
				else
					temp->ptr[i] = Insert(temp->ptr[i], New);
				break;
			}
			else if (temp->data[m - 2] != NULL)
			{
				if (temp->data[m - 2] < New->data[0])
				{
					if (temp->ptr[m - 1] == NULL)
						temp->ptr[m - 1] = New;
					else
						temp->ptr[m - 1] = Insert(temp->ptr[m - 1], New);
					break;
				}
			}
		}
	}
	return temp;
}

void Inorder(Tree* temp)
{
	if (temp != NULL)
	{
		for (int i = 0;i < m;i++)
		{
			Inorder(temp->ptr[i]);
			if(i<m-1 && temp->data[i]!=NULL)
				cout << temp->data[i]<<" ";
		}
	}
}

void Search(Tree* temp, int value)
{
	if (Root == NULL)
		cout << "Tree is Empty.";
	else if (temp != NULL)
	{
		for (int i = 0;i < m;i++)
		{
			if (i < m - 1 && temp->data[i] != NULL)
			{
				if (value < temp->data[i])
				{
					Search(temp->ptr[i], value);
					break;
				}
				else if (value == temp->data[i])
				{
					cout << "Element is Found.";
					break;
				}
			}
			else if (temp->data[i-1] != NULL)
			{
				if (temp->data[i - 1] < value)
				{
					Search(temp->ptr[m - 1], value);
					break;
				}
			}
		}
	}
	else
		cout << "Element is Not Found.";
}

Tree* findMax(Tree* temp)
{
	if (temp != NULL)
	{
		while (temp->ptr[m-1] != NULL)
			temp = temp->ptr[m-1];
	}
	return temp;
}

Tree* findMin(Tree* temp)
{
	if (temp != NULL)
	{
		while (temp->ptr[0] != NULL)
	    	temp = temp->ptr[0];
	}
	return temp;
}

Tree* Delete(Tree* temp, int value)
{
	if (Root == NULL)
		cout << "Tree is Empty.";
	else if (temp != NULL)
	{
		for (int i = 0;i < m;i++)
		{
			if (i < m - 1)
			{
				if (value < temp->data[i])
				{
					temp->ptr[i]=Delete(temp->ptr[i], value);
					break;
				}
				else if (value == temp->data[i])
				{
					Tree* n;

					if (temp->ptr[i] && temp->ptr[i + 1])
					{
						n = findMax(temp->ptr[i]);

						for (int j = m - 2;j >= 0;j--)
						{
							if (n->data[j])
							{
								temp->data[i] = n->data[j];
								temp->ptr[i] = Delete(temp->ptr[i], temp->data[i]);
								break;
							}
						}
					}
					else if(temp->ptr[i] || temp->ptr[i+1])
					{
						if (temp->ptr[i])
						{
							n = findMax(temp->ptr[i]);

							for (int j = m - 2;j >= 0;j--)
							{
								if (n->data[j])
								{
									temp->data[i] = n->data[j];
									temp->ptr[i] = Delete(temp->ptr[i], temp->data[i]);
									break;
								}
							} 
						}
						else
						{
							n = findMin(temp->ptr[i+1]);

							for(int j = 0;j < m - 1;j++)
							{
								if (n->data[j])
								{
									temp->data[i] = n->data[j];
									temp->ptr[i + 1] = Delete(temp->ptr[i + 1], temp->data[i]);
									break;
								}
							}
						}
					}
					else
					{
						int j, k;
						for (j = i-1;j >= 0;j--)
							if (temp->data[j] != NULL)
								break;
						for (k = i + 1;k < m - 1;k++)
							if (temp->data[k] != NULL)
								break;
						if (j == -1 && k == m - 1)
						{
							free(temp); 
							temp = NULL;
						}
						else
							temp->data[i] = NULL;
						
					}
					break;
				}
			}
			else if (temp->data[i - 1] != NULL)
			{
				if (temp->data[i - 1] < value)
				{
					temp->ptr[m-1]=Delete(temp->ptr[m - 1], value);
					break;
				}
			}
		}
	}
   return temp;
}

int main()
{
	int ch;
	cout << "Enter the value of M:";
	cin >> m;

	while (1)
	{
		system("cls");
		cout << "1] Insert\n2] Display\n3] Search\n4] Delete\n5] Exit";
		cout << "\n\nEnter your choice:";
		cin >> ch;

		switch (ch)
		{
		case 1:
			Root = Insert(Root, Create());
			break;
		case 2:
			if (Root != NULL)
			{
				cout << "Displaying Tree in Inorder Way..." << endl;
				Inorder(Root);	
			}
			else
				cout << "Tree is Empty.";
				_getch();
			break;
		case 3:
			cout << "Enter the Element to Search:";
			cin >> ch;
			Search(Root, ch);
			_getch();
			break;
		case 4:
			cout << "Enter the Element to Delete:";
			cin >> ch;
			Root=Delete(Root, ch);
			break;
		case 5:
			exit(0);
		default:
			cout << "Invalid Choice.";
			_getch();
		}
	}
	return 0;
}

