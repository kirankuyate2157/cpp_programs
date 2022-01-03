#include <bits/stdc++.h>
#include<iostream>
using namespace std;
class node
{
	

public:
	int seat;
	string status;
	node *next;
	node *prev;
	node()
	{
		seat = 0;
		status = "🔴";

		next = NULL;
		prev = NULL;
	}
	node(int seat, int v)
	{
		this->seat = seat;
		if (v == 1)
		{
			status = "🟢";
		}
		else if (v == -1)
		{
			status = "🟡";
		}
		else
		{
			status = "🔴";
		}

		next = NULL;
		prev = NULL;
	}
};

class cinmax
{

	node *tab = new node(1, 0);
	int n = 50;

public:
	cinmax()
	{
		node *temp = tab;
		int i = 2;
		while (i <= n)
		{
			node *ptr = new node(i++, 0);
			temp->next = ptr;
			ptr->prev = temp;
			temp = temp->next;
		}
	}

	void Sbook(int x)
	{
		node *temp = tab;
		while (tab != NULL)
		{
			if (tab->seat == x && tab->status == "🟢")
			{
				cout << "\n\t\t  *Sorry !! \n"
					 << "\t  ------------  seat " << x << "is alraedy booked            ------------\n";
				break;
			}
			if (tab->seat == x && tab->status != "🟢")
			{
				tab->status = "🟢";

				cout << "\n\t  ------------  Your Seat " << x << " booked sucssesfully    ------------\n";

				break;
			}

			tab = tab->next;
		}
		tab = temp;
	}

	void display()
	{
		node *temp = tab;
		int t;cout<<"\t\t";
		while (temp != NULL)
		{
			if (t % 10 == 0)
			{
				t = 0;
				cout << "\n\t\t";
			}
			t++;

			if (temp->seat < 10)
			{
				cout << "  " << temp->seat << temp->status << " ";
			}
			else
			{
				cout << " " << temp->seat << temp->status << " ";
			}
			temp = temp->next;
		}
	}

	void cancel(int x)
	{
		node *temp = tab;
		while (temp != NULL)
		{
			if (temp->seat == x && temp->status == "🔴")
			{
				cout << "\n\t   ----------    Seat is already empty !! how can i cancel it  ----------\n";
			}
			else if (temp->seat == x && temp->status == "🟡")
			{
				cout << "\n\t   ----------   Seat is already canceled !! how can i cancel it  ----------\n";
			}
			if (temp->seat == x && temp->status == "🟢")
			{
				temp->status = "🟡";
			}
			temp = temp->next;
		}
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cinmax x;
	bool flag=true;
	while (flag)
	{
		cout << "*\n\t-----------         Welcome to KK_cinmax        -----------\n ";
		cout << "\t1.book ticket\n\t2.cancel ticket\n\t3.show seats\n\t4.exit\n";
		int op;cout<<"\t_ _ _ ";
		cin >> op;int z;
		switch (op)
		{
		case 1:
			
			cout << "\tenter seat no  _ _ _  ";
			cin >> z;
			x.Sbook(z);
			break;
		case 2:
			
			cout << "\tenter seat no  _ _ _  ";
			cin >> z;
			x.cancel(z);
			break;
		case 3:
			x.display();
			break;
		case 4:
			flag = false;
			cout<<"\n\tThank for coming to Cinmax ,I hope you will enjoy it..\n";
			cout<<"\t***********                             ***********\n";
			cout<<"\t********                                  *********\n";
			cout<<"\t*****                                        ******\n";
			cout<<"\t***                                             ***\n";
			cout<<"\t*                                                 *\n";
			
			break;
		default:
			cout << "\t please enter vallide input";
			break;
		}
	}

	
	return 0;
}