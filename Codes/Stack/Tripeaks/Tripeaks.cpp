#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

class Card
{
public:
    string suit;
    string rank;
    int value;

    Card()
    {
        suit = "";
        rank = "";
        value = 0;
    }

    Card(string s, string r, int v)
    {
        suit = s;
        rank = r;
        value = v;
    }

    void display() {
        cout << "[" << rank << suit << "]";
    }
};

class Stack
{
private:
    int topIndex;
    Card arr[60];
public:
    Stack()
    {
        topIndex = -1;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    void push(Card c)
    {
        arr[++topIndex] = c;
    }

    Card pop()
    {
        return arr[topIndex--];
    }

    Card top()
    {
        return arr[topIndex];
    }

    
    void saveStack(ofstream &file)
    {
        file << topIndex + 1 << " ";
        for (int i = 0; i <= topIndex; i++)
            file << arr[i].rank << " " << arr[i].suit << " " << arr[i].value << " ";
        file << "\n";
    }

   
    void loadStack(ifstream &file)
    {
        int size;
        file >> size;
        topIndex = -1;
        for (int i = 0; i < size; i++)
        {
            string r, s;
            int v;
            file >> r >> s >> v;
            push(Card(s, r, v));
        }
    }
};

class TriPeaksGame
{
public:
    Card deck[52];
    bool faceUp[28];
    bool removed[28];
    Card tableau[28];
    Stack stock;
    Stack waste;

    TriPeaksGame()
    {
        createDeck();
        shuffleDeck();
        dealTriPeaks();
        initializeFaceUp();
    }

    void createDeck()
    {
        string suits[4] = { "H", "D", "C", "S" };
        string ranks[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

        int index = 0;
        for (int s = 0; s < 4; s++)
        {
            for (int r = 0; r < 13; r++)
            {
                deck[index] = Card(suits[s], ranks[r], r + 1);
                index++;
            }
        }
    }

    void shuffleDeck()
    {
        srand((unsigned)time(0));
        for (int i = 0; i < 52; i++)
        {
            int r = rand() % 52;
            Card temp = deck[i];
            deck[i] = deck[r];
            deck[r] = temp;
        }
    }

    void dealTriPeaks() {

        for (int i = 0; i < 28; i++)
        {
            tableau[i] = deck[i];
            removed[i] = false;
        }
        for (int i = 28; i < 52; i++)
        {
            stock.push(deck[i]);
        }
    }

    void initializeFaceUp()
    {
        for (int i = 0; i < 28; i++)
            faceUp[i] = false;


        for (int i = 18; i <= 27; i++)
            faceUp[i] = true;


        if (!stock.isEmpty())
            waste.push(stock.pop());


        updateFaceUpAll();
    }

    void displayLayout()
    {
        cout << "\n=========== TRI-PEAKS (REAL LAYOUT) ===========\n\n";

        cout << "             ";
        showCard(0);
        cout << "        ";
        showCard(1);
        cout << "        ";
        showCard(2);
        cout << "\n\n";

        cout << "           ";
        for (int i = 3; i <= 8; i++)
        {
            if (i == 5 || i == 7)
                cout << "   ";
            showCard(i);
            cout << " ";

        }
        cout << "\n\n";

        cout << "        ";
        for (int i = 9; i <= 17; i++)
        {
            showCard(i); cout << " ";
        }
        cout << "\n\n";

        for (int i = 18; i <= 27; i++)
        {
            showCard(i); cout << " ";
        }
        cout << "\n\n";

        cout << "Waste Top: ";
        if (!waste.isEmpty()) waste.top().display();
        else cout << "  ";
        cout << "\n";

        cout << "Stock Cards Remaining: (stack)\n";

        cout << "==============================================\n\n";
    }

    void showCard(int i)
    {
        if (removed[i])
        {
            cout << "   "; return;
        }
        if (faceUp[i])
            tableau[i].display();
        else
            cout << "[*]";
    }

    bool isAdjacent(Card a, Card b)
    {
        if (a.value == 1 && b.value == 13)
            return true;
        if (a.value == 13 && b.value == 1)
            return true;
        return abs(a.value - b.value) == 1;
    }


    bool isUnlocked(int i)
    {
        if (removed[i])
            return false;


        if (i >= 18 && i <= 27)
            return faceUp[i];


        int child1 = -1, child2 = -1;

        if (i >= 9 && i <= 17)
        {
            child1 = 18 + (i - 9);
            child2 = child1 + 1;
        }
        else if (i >= 3 && i <= 8)
        {
            child1 = 9 + (i - 3);
            child2 = child1 + 1;
        }
        else if (i >= 0 && i <= 2)
        {
            child1 = 3 + i * 2;
            child2 = 4 + i * 2;
        }

        if (child1 < 0 || child1 >= 28)
            return true;
        if (child2 < 0 || child2 >= 28)
            return true;

        return removed[child1] && removed[child2];
    }


    void updateFaceUpAll()
    {
        for (int i = 0; i < 28; i++)
        {
            if (!removed[i] && isUnlocked(i))
                faceUp[i] = true;

        }
    }


    bool playCard(int i)
    {
        if (!faceUp[i] || removed[i])
            return false;
        if (!isUnlocked(i))
            return false;

        if (waste.isEmpty())
            return false;
        Card top = waste.top();

        if (!isAdjacent(top, tableau[i]))
            return false;

        waste.push(tableau[i]);
        removed[i] = true;

        updateFaceUpAll();

        return true;
    }

    void drawStock()
    {
        if (!stock.isEmpty())
        {
            waste.push(stock.pop());

            updateFaceUpAll();
        }
    }

    bool allRemoved()
    {
        for (int i = 0; i < 28; i++)
            if (!removed[i])
                return false;
        return true;
    }

    int findCard(string r, string s)
    {
        for (int i = 0; i < 28; i++)
        {
            if (!removed[i] && faceUp[i] &&
                tableau[i].rank == r &&
                tableau[i].suit == s)
                return i;
        }
        return -1;
    }

   
    void saveGame()
    {
        ofstream file("TriPeaksSave.txt");
        for (int i = 0; i < 28; i++)
        {
            file << tableau[i].rank << " " << tableau[i].suit << " " << tableau[i].value << " "
                 << faceUp[i] << " " << removed[i] << "\n";
        }
        stock.saveStack(file);
        waste.saveStack(file);
        file.close();
        cout << "Game Saved Successfully!\n";
    }

    bool loadGame()
    {
        ifstream file("TriPeaksSave.txt");
        if (!file) return false;

        for (int i = 0; i < 28; i++)
        {
            file >> tableau[i].rank >> tableau[i].suit >> tableau[i].value
                 >> faceUp[i] >> removed[i];
        }
        stock.loadStack(file);
        waste.loadStack(file);
        file.close();
        return true;
    }

    void startGame()
    {
        int choice;

        cout << "Do you want to continue previous game? (1 = Yes, 0 = No): ";
        int cont;
        cin >> cont;
        if (cont == 1)
        {
            if (!loadGame())
            {
                cout << "No saved game found. Starting new game.\n";
            }
        }

        while (true)
        {
            system("cls");
            displayLayout();

            if (allRemoved()) {
                cout << " YOU CLEARED THE TRI-PEAKS! \n";
                break;
            }

            cout << "1. Play Card\n2. Draw Stock\n3. Save Game\n4. Exit\nChoice: ";
            cin >> choice;

            if (choice == 1)
            {
                string r, s;
                cout << "Enter Rank (A,2..10,J,Q,K): ";
                cin >> r;
                cout << "Enter Suit (H,D,C,S): ";
                cin >> s;

                int idx = findCard(r, s);

                if (idx == -1)
                {
                    cout << "Card not available or not face-up.\n";
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                    continue;
                }

                if (!playCard(idx))
                {
                    cout << "INVALID MOVE (Locked or not adjacent).\n";
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
            }
            else if (choice == 2)
            {
                drawStock();
            }
            else if (choice == 3)
            {
                saveGame();
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
            else if (choice == 4) break;
        }
    }
};

int main() {
    TriPeaksGame game;
    game.startGame();
    return 0;
}
