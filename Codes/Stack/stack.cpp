#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Card
{
public:
    int rank;
    string suit;
    Card(int r = 0, string s = "")
    {
        suit = s;
        rank = r;
    }
    void Display()
    {
        cout << rank << suit << " ";
    }
};

class Deck
{
public:
    Card cards[52];
    Deck()
    {
        string suits[4] = { "H", "D", "C", "S" };
        int k = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= 13; j++)
            {
                cards[k] = Card(j, suits[i]);
                k++;
            }
        }
    }


    void shuffle()
    {
        srand(time(0));
        for (int i = 51; i > 0; i--)
        {
            int j = rand() % (i + 1);
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
    }

    void displayDeck()
    {
        for (int i = 0; i < 52; i++)
        {
            cards[i].Display();
            if (i % 13 == 12)
                cout << endl;
        }
    }
};
int main()
{
    Deck d;

    cout << "Cards in the Dack:\n" << endl;
    d.displayDeck();

    d.shuffle();
    cout << "\nCards in the Deck After Shuffle:\n"<<endl;
    d.displayDeck();
    return 0;
}