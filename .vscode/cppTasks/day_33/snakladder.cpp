#include <bits/stdc++.h>
using namespace std;
#define m 10
int box[m][m];
struct node
{
    string playerName;
    int position;
};

vector<node> players;
char names;
int n = 2;

void print()
{
    int x = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << box[i][j] << " ";
        cout << "\n";
    }
}
int special(int x)
{
    switch (x)
    {
    case 18:
        return 7;
        break;
    case 11:
        return 9;
        break;
    case 22:
        return 17;
        break;

    case 39:
        return 15;
        break;
    case 54:
        return 44;
        break;
    case 63:
        return 55;
        break;
    case 99:
        return 56;
        break;
    case 95:
        return 63;
        break;
    case 91:
        return 75;
        break;
    case 86:
        return 52;
        break;
    // jump
    case 3:
        return 12;
        break;
    case m:
        return 24;
        break;
    case 36:
        return 59;
        break;
    case 64:
        return 82;
        break;
    case 78:
        return 96;
        break;
    default:
        return x;
        break;
    }
}

int size()
{
    return players.size();
}
void makeBox()
{
    int x = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            box[i][j] = x + j;
        x += m;
    }
    cout << "\nSelect the players size 🤼‍♀️: ";
    cin >> n;
    cout << "\nDo you want to add names ?(y/n):";
    cin >> names;
    for (int i = 0; i < n; i++)
    {
        if (names = 'y')
            cin >> players[i]->playerName;
        else
            players[i]->playerName = to_string(i + 1);
        players[i]->position = 0;
    }
}

int dice()
{
    return rand() % 6;
}

void move(int diceV, node *player)
{
    int i = player->position / m;
    int j = player->position % m;

    for (; i < m; i++)
        for (; j < m; j++)
        {
            if (box[i][j] == player->position + diceV)
            {
                if (player->position + diceV == 100 || player->position + diceV == 100)
                    player->position = special(box[i][j]);
            }
            if (diceV == 6)
            {
                cout << "Chance again..." << endl;
                diceV = dice();
                move(diceV, player);
            }
            else
            {
                break;
            }
        }
}

void playGround()
{
    cout << "welcome to playground 🌹🍃🍂🍁✌\n";
    makeBox();

    int i = 0;
    string online = "🟢", offline = "🔴";
    char decision = 'Y';
    for (i = 0; i < n; i++)
    {
        char thrown;
        cin >> thrown;
        if (thrown == 't' || thrown == '1' || thrown == 'm')
        {
            cout << online << " ";
            move(dice(), players[i]);
            if (players[i]->position = 100)
            {
                int rank = abs(size() % n - n);
                if (1)
                    cout << rank << "st winner 🌟 🎉🎉!!";
                else if (2)
                    cout << rank << "nd winner 🌟🌟 🎉🎉!!";
                else if (3)
                    cout << rank << "rd winner 🌟🌟🌟 🎉🎉!!";
                else
                    cout << rank << "th winner ✌ 🎉🎉!!";
                players.erase(players.begin() + i);
                char decision;
                cout << "Your playing crezy guys 🔥🔥,\n\tDo you want to continue play (y/n) 🧐🧐!!\n\t:";
                cin >> decision;
                if (decision == 'n' || decision == 'N')
                {
                    cout << "I hope you enjoyed the game 😍😍\n";
                    break;
                }
            }
        }
        if (i == n && (decision == 'y' || decision == 'Y'))
            i = 0;
    }
}
int main()
{

    playGround();
    return 0;
}
