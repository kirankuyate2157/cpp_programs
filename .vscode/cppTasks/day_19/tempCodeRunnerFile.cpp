// 	{
// 		seat = data;
// 		next = NULL;
// 		prev = NULL;
// 	}
// };

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
		int t;
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