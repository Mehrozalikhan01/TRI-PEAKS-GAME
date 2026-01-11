#include "raylib.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class node {
public:
    string data;
    bool revealed;
    bool removed;
    node* next;
    node* child1;
    node* child2;

    node(string value) {
        data = value;
        revealed = false;
        removed = false;
        next = nullptr;
        child1 = nullptr;
        child2 = nullptr;
    }
};

class linkedList {
public:
    node* head;

    linkedList() { head = nullptr; }

    ~linkedList() { clear(); }

    void clear() {
        node* t = head;
        while (t) {
            node* n = t->next;
            delete t;
            t = n;
        }
        head = nullptr;
    }

    void insertAtEnd(string value) {
        node* n = new node(value);
        if (!head) {
            head = n;
            return;
        }
        node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    node* getTail() {
        node* t = head;
        while (t && t->next) t = t->next;
        return t;
    }
};

class setup {
public:
    bool gameOver, gameWon, levelSelected;

    linkedList stack1, stack2;
    linkedList array1, array2, array3, array4;

    string cards[52];

    setup() {
        gameOver = gameWon = false;
        levelSelected = false;

        string deck[52] = {
            "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
            "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
            "DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
            "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
        };

        for (int i = 0; i < 52; i++) cards[i] = deck[i];
    }

    void shuffle() {
        for (int i = 51; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(cards[i], cards[j]);
        }
    }

    void initBaseGame(int stockCount) {
        stack1.clear(); stack2.clear();
        array1.clear(); array2.clear(); array3.clear(); array4.clear();

        gameOver = gameWon = false;

        shuffle();

        int c = 0;
        for (int i = 0; i < 3; i++) array1.insertAtEnd(cards[c++]);
        for (int i = 0; i < 6; i++) array2.insertAtEnd(cards[c++]);
        for (int i = 0; i < 9; i++) array3.insertAtEnd(cards[c++]);
        for (int i = 0; i < 10; i++) array4.insertAtEnd(cards[c++]);

        for (int i = 0; i < stockCount; i++) stack1.insertAtEnd(cards[c++]);
        stack2.insertAtEnd(cards[c++]);

        initializeChildren();
        updateReveals();
    }

    void easyGame()   { initBaseGame(28); }
    void mediumGame() { initBaseGame(23); }
    void hardGame()   { initBaseGame(18); }

    void initializeChildren() {
        node* t3 = array3.head;
        node* t4 = array4.head;
        while (t3 && t4) {
            t3->child1 = t4;
            t3->child2 = t4->next;
            t3 = t3->next;
            t4 = t4->next;
        }

        node* t2 = array2.head;
        t3 = array3.head;
        int i = 0;
        while (t2 && t3) {
            t2->child1 = t3;
            t2->child2 = t3->next;
            t3 = (i == 1 || i == 3) ? t3->next->next : t3->next;
            t2 = t2->next;
            i++;
        }

        node* t1 = array1.head;
        t2 = array2.head;
        while (t1 && t2) {
            t1->child1 = t2;
            t1->child2 = t2->next;
            t2 = t2->next->next;
            t1 = t1->next;
        }
    }

    void updateReveals() {
        auto reveal = [](linkedList& l) {
            node* t = l.head;
            while (t) {
                if ((!t->child1 || t->child1->removed) &&
                    (!t->child2 || t->child2->removed))
                    t->revealed = true;
                t = t->next;
            }
        };
        reveal(array4); reveal(array3); reveal(array2); reveal(array1);
    }

    void drawCard(string d, int x, int y, bool r, bool rem) {
        if (rem) return;
        Rectangle rec = {(float)x,(float)y,70,90};
        if (!r) {
            DrawRectangleRec(rec, BLUE);
            DrawText("?", x + 25, y + 30, 30, WHITE);
        } else {
            DrawRectangleRec(rec, WHITE);
            Color c = (d[0]=='H'||d[0]=='D')?RED:BLACK;
            DrawText(d.c_str(), x+15, y+30, 25, c);
        }
    }

    void drawLevelScreen() {
        DrawText("TRIPEAKS SOLITAIRE", 410, 180, 40, GOLD);
        DrawText("SELECT DIFFICULTY", 430, 260, 32, WHITE);
        DrawText("Press 1 for EASY",   470, 330, 25, LIGHTGRAY);
        DrawText("Press 2 for MEDIUM", 470, 370, 25, LIGHTGRAY);
        DrawText("Press 3 for HARD",   470, 410, 25, LIGHTGRAY);
    }

    void draw() {
        DrawText("TriPeaks Solitaire", 450, 20, 30, GOLD);
    }
};

int main() {
    InitWindow(1200, 800, "TriPeaks Solitaire");
    SetTargetFPS(60);
    srand(time(0));

    setup game;

    while (!WindowShouldClose()) {

        if (!game.levelSelected) {
            if (IsKeyPressed(KEY_ONE))   { game.levelSelected = true; game.easyGame(); }
            if (IsKeyPressed(KEY_TWO))   { game.levelSelected = true; game.mediumGame(); }
            if (IsKeyPressed(KEY_THREE)) { game.levelSelected = true; game.hardGame(); }
        }

        BeginDrawing();
        ClearBackground(DARKGREEN);

        if (!game.levelSelected)
            game.drawLevelScreen();
        else
            game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}