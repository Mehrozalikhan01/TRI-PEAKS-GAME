#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Card {
public:
    string suit;
    string rank;
    int value;

    Card() {
        suit = "";
        rank = "";
        value = 0;
    }

    Card(string s, string r, int v) {
        suit = s;
        rank = r;
        value = v;
    }

    void display() {
        cout << "["<<rank << suit<<"]";
    }
};
  class Stack {
private:
    int topIndex;
    Card arr[60];
public:
    Stack() { topIndex = -1; }

    bool isEmpty() { return topIndex == -1; }

    void push(Card c) { arr[++topIndex] = c; }

    Card pop() { return arr[topIndex--]; }

    Card top() { return arr[topIndex]; }
};

class TriPeaksDisplay {
public:
    Card deck[52];
 bool faceUp[28];
 bool removed[28];
 Card tableau[28];
 Stack stock;
 Stack waste;

    TriPeaksGame() {
    createDeck();
    shuffleDeck();
    dealTriPeaks();
    initializeFaceUp();
    }

    void createDeck() {
        string suits[4] = { "H", "D", "C", "S" };
        string ranks[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

        int index = 0;
        for (int s = 0; s < 4; s++) {
            for (int r = 0; r < 13; r++) {
                deck[index] = Card(suits[s], ranks[r]);
                index++;
            }
        }
    }

    void shuffleDeck() {
        srand((unsigned)time(0));
        for (int i = 0; i < 52; i++) {
            int r = rand() % 52;
            Card temp = deck[i];
            deck[i] = deck[r];
            deck[r] = temp;
        }
    }

    void dealTriPeaks() {
        for (int i = 0; i < 28; i++) {
            tableau[i] = deck[i];
            removed[i] = false;
        }
    for (int i = 28; i < 52; i++) {
    stock.push(deck[i]);
    }
   void initializeFaceUp() {
        for (int i = 0; i < 28; i++)
     Stack   {
            faceUp[i] = false;
        }

        for (int i = 18; i <= 27; i++)
        {
             faceUp[i] = true;
        }
           

       if (!stock.isEmpty())
       {
           waste.push(stock.pop());
       }      
        updateFaceUpAll(); 
    }

    void updateFaceUpAll()
    {
        for (int i = 0; i < 28; i++)
        {
            if (!removed[i] && isUnlocked(i))
            {
                faceUp[i] = true;
            }
        }
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
        {
           if (!removed[i]) 
           {
              return false;
           }    
        }        
        return true;
    }
    void showCard(int i)
    {
        if (removed[i])
         {
             cout << "   "; return; 
         }
        if (faceUp[i]) 
        {
            tableau[i].display();
        }
        else 
        {
            cout << "[*]";
        }
    }
        
    void displayLayout() {
        cout << "\n=========== TRI-PEAKS Game ===========\n\n";

        cout << "              ";
        showCard(0);
        cout << "          ";
        showCard(1);
        cout << "           ";
        showCard(2);
        cout << "\n\n";

        cout << "           ";
        for (int i = 3; i <= 8; i++) {
            if (i == 5 || i == 7)
                cout << "     ";
            showCard(i);
            cout << " ";
        }
        cout << "\n\n";

        cout << "         ";
        for (int i = 9; i <= 17; i++) {
            showCard(i);
            cout << " ";
        }
        cout << "\n\n    ";

        for (int i = 18; i <= 27; i++) {
            showCard(i);
            cout << " ";
        }
        cout << "\n\n";

        cout << "==============================================\n\n";
    }
};

int main() {
    TriPeaksDisplay game;

    game.displayLayout();

    return 0;
}
