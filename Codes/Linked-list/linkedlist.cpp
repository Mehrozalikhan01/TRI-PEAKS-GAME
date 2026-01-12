#include <iostream>
#include <ctime>
#include <string>
#include "raylib.h"
using namespace std;

class node {
public:
    string data;
    int level;
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
    node() {
        data = "";
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

    linkedList() {
        head = nullptr;
    }

    void insertAtEnd(string value) {
        node* newNode = new node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(int level) {
        int count2 = 0;
        int count3 = 0;
        if (level == 1) cout << "          ";
        else if (level == 2) cout << "       ";
        else if (level == 3) cout << "   ";
        node* temp = head;
        while (temp != nullptr) {
            if (temp->removed) {
                cout << "__";
            }
            else if (temp->revealed) {
                cout << temp->data;
            }
            else {
                cout << "**";
            }
            if (level == 1) cout << "    ";
            else if (level == 2) cout << "    ";
            else if (level == 3) cout << "    ";
            else if (level == 4) cout << "    ";
            count2++;
            count3++;
            if (level == 1) {
                cout << "           ";
            }
            else if (level == 2 && (count2 == 2 || count2 == 4 || count2 == 6)) {
                cout << "     ";
            }
            else if (level == 3 && (count3 == 3 || count3 == 6 || count3 == 9)) {
                cout << "";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void displayHiddenStack() {
        cout << "****";
    }
    void displayFaceUpStack() {
        if (head == nullptr) {
            cout << "    ";
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << temp->data;
    }


};

class setup {
public:
    string input;
    linkedList stack1;
    linkedList stack2;
    linkedList array1;
    linkedList array2;
    linkedList array3;
    linkedList array4;

    string cards[52] = {
        "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
        "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
        "DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
        "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
    };


    void shuffle() {
        int shuffleTimes = 5;

        if (difficulty == 1) {
            shuffleTimes = 5;
        }
        else if (difficulty == 2) {
            shuffleTimes = 10;
        }
        else if (difficulty == 3) {
            shuffleTimes = 20;
        }

        int startIndex = 51;
        int endIndex = 51 - shuffleTimes;

        for (int i = startIndex; i > endIndex; i--) {
            int j = rand() % (i + 1);
            string temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
    }
    void makeStacks() {
        for (int i = 0;i < 23;i++) {
            stack1.insertAtEnd(cards[i]);
        }
        stack2.insertAtEnd(cards[23]);
    }
    void makeLevels() {
        for (int i = 24;i < 27;i++) {
            array1.insertAtEnd(cards[i]);
        }
        for (int i = 27;i < 33;i++) {
            array2.insertAtEnd(cards[i]);
        }
        for (int i = 33;i < 42;i++) {
            array3.insertAtEnd(cards[i]);
        }
        for (int i = 42;i < 52;i++) {
            array4.insertAtEnd(cards[i]);
        }
    }
    void initializeLevels() {
        node* temp = array1.head;
        while (temp != nullptr) {
            temp->level = 1;
            temp = temp->next;
        }
        temp = array2.head;
        while (temp != nullptr) {
            temp->level = 2;
            temp = temp->next;
        }
        temp = array3.head;
        while (temp != nullptr) {
            temp->level = 3;
            temp = temp->next;
        }
        temp = array4.head;
        while (temp != nullptr) {
            temp->level = 4;
            temp = temp->next;
        }
    }
    void makeLevel4Reveal() {
        node* temp = array4.head;
        while (temp != nullptr) {
            temp->revealed = true;
            temp = temp->next;
        }
    }
    void stack2Reveal() {
        node* temp = stack2.head;
        while (temp != nullptr) {
            temp->revealed = true;
            temp = temp->next;
        }
    }
    void initializeChildren() {
        node* temp3 = array3.head;
        node* temp4 = array4.head;
        int index4 = 0;
        while (temp3 != nullptr) {
            if (temp4 != nullptr) {
                temp3->child1 = temp4;
                if (temp4->next != nullptr) {
                    temp3->child2 = temp4->next;
                }
                temp4 = temp4->next;
            }
            temp3 = temp3->next;
            index4++;
        }
        node* temp2 = array2.head;
        temp3 = array3.head;
        int count2 = 0;
        while (temp2 != nullptr && temp3 != nullptr) {
            temp2->child1 = temp3;
            if (temp3->next != nullptr) {
                temp2->child2 = temp3->next;
            }
            if (count2 == 1 || count2 == 3) {
                if (temp3->next != nullptr) {
                    temp3 = temp3->next->next;
                }
            }
            else {
                temp3 = temp3->next;
            }
            temp2 = temp2->next;
            count2++;
        }
        node* temp1 = array1.head;
        temp2 = array2.head;
        while (temp1 != nullptr && temp2 != nullptr) {
            temp1->child1 = temp2;
            if (temp2->next != nullptr) {
                temp1->child2 = temp2->next;
            }
            if (temp2->next != nullptr && temp2->next->next != nullptr) {
                temp2 = temp2->next->next;
            }
            else {
                break;
            }
            temp1 = temp1->next;
        }
    }
    void reveal() {
        node* temp = array1.head;
        while (temp != nullptr) {
            if (!temp->revealed) {
                if (temp->child1 != nullptr && temp->child2 != nullptr) {
                    if (temp->child1->removed && temp->child2->removed) {
                        temp->revealed = true;
                    }
                }
            }
            temp = temp->next;
        }
        temp = array2.head;
        while (temp != nullptr) {
            if (!temp->revealed) {
                if (temp->child1 != nullptr && temp->child2 != nullptr) {
                    if (temp->child1->removed && temp->child2->removed) {
                        temp->revealed = true;
                    }
                }
            }
            temp = temp->next;
        }
        temp = array3.head;
        while (temp != nullptr) {
            if (!temp->revealed) {
                if (temp->child1 != nullptr && temp->child2 != nullptr) {
                    if (temp->child1->removed && temp->child2->removed) {
                        temp->revealed = true;
                    }
                }
            }
            temp = temp->next;
        }
    }
    bool validMove() {
        node* temp = array1.head;
        bool allRemoved = true;
        while (temp != nullptr) {
            if (!temp->removed) {
                allRemoved = false;
                break;
            }
            temp = temp->next;
        }
        if (allRemoved) {
            temp = array2.head;
            while (temp != nullptr) {
                if (!temp->removed) {
                    allRemoved = false;
                    break;
                }
                temp = temp->next;
            }
        }
        if (allRemoved) {
            temp = array3.head;
            while (temp != nullptr) {
                if (!temp->removed) {
                    allRemoved = false;
                    break;
                }
                temp = temp->next;
            }
        }
        if (allRemoved) {
            temp = array4.head;
            while (temp != nullptr) {
                if (!temp->removed) {
                    allRemoved = false;
                    break;
                }
                temp = temp->next;
            }
        }
        if (allRemoved) {
            return false;
        }
        if (stack1.head != nullptr) {
            return true;
        }
        node* stk2Temp = stack2.head;
        while (stk2Temp->next != nullptr) {
            stk2Temp = stk2Temp->next;
        }
        string t = stk2Temp->data;
        char stkSecond = t[1];
        temp = array1.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed) {
                char cardSecond = temp->data[1];
                if (isValid(cardSecond, stkSecond)) {
                    return true;
                }
            }
            temp = temp->next;
        }
        temp = array2.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed) {
                char cardSecond = temp->data[1];
                if (isValid(cardSecond, stkSecond)) {
                    return true;
                }
            }
            temp = temp->next;
        }
        temp = array3.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed) {
                char cardSecond = temp->data[1];
                if (isValid(cardSecond, stkSecond)) {
                    return true;
                }
            }
            temp = temp->next;
        }
        temp = array4.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed) {
                char cardSecond = temp->data[1];
                if (isValid(cardSecond, stkSecond)) {
                    return true;
                }
            }
            temp = temp->next;
        }
        return false;
    }
    bool isValid(char card, char stack) {
        if (card >= '2' && card <= '9') {
            int cardVal = card - '0';
            if (stack >= '2' && stack <= '9') {
                int stackVal = stack - '0';
                if (cardVal == stackVal + 1 || cardVal == stackVal - 1) {
                    return true;
                }
            }
            else if (stack == 'A') {
                if (cardVal == 2) {
                    return true;
                }
            }
            else if (stack == 'T') {
                if (cardVal == 9) {
                    return true;
                }
            }
        }
        else if (card == 'A') {
            if (stack == '2' || stack == 'K') {
                return true;
            }
        }
        else if (card == 'T') {
            if (stack == '9' || stack == 'J') {
                return true;
            }
        }
        else if (card == 'J') {
            if (stack == 'T' || stack == 'Q') {
                return true;
            }
        }
        else if (card == 'Q') {
            if (stack == 'J' || stack == 'K') {
                return true;
            }
        }
        else if (card == 'K') {
            if (stack == 'Q' || stack == 'A') {
                return true;
            }
        }
        return false;
    }


    bool gameOver = false;
    bool gameWon = false;
    int score = 0;
    int difficulty = 1;
    bool difficultySelected = false;


    bool isCardClicked(int cardX, int cardY, int mouseX, int mouseY) {
        int cardWidth = 70;
        int cardHeight = 90;

        if (mouseX >= cardX && mouseX <= cardX + cardWidth &&
            mouseY >= cardY && mouseY <= cardY + cardHeight) {
            return true;
        }
        return false;
    }
    bool validateInput(string& in) {
        if (in == "99") {
            if (stack1.head != nullptr) {
                node* temp = stack1.head;
                stack1.head = stack1.head->next;
                stack2.insertAtEnd(temp->data);
                delete temp;
            }
            return true;
        }

        // Check if the card exists and is valid
        node* stk2Temp = stack2.head;
        while (stk2Temp->next != nullptr) {
            stk2Temp = stk2Temp->next;
        }
        string t = stk2Temp->data;
        char stkSecond = t[1];

        // Check all levels
        node* temp = array1.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed && in == temp->data) {
                char inSecond = in[1];
                return isValid(inSecond, stkSecond);
            }
            temp = temp->next;
        }

        temp = array2.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed && in == temp->data) {
                char inSecond = in[1];
                return isValid(inSecond, stkSecond);
            }
            temp = temp->next;
        }

        temp = array3.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed && in == temp->data) {
                char inSecond = in[1];
                return isValid(inSecond, stkSecond);
            }
            temp = temp->next;
        }

        temp = array4.head;
        while (temp != nullptr) {
            if (temp->revealed && !temp->removed && in == temp->data) {
                char inSecond = in[1];
                return isValid(inSecond, stkSecond);
            }
            temp = temp->next;
        }

        return false; // Invalid move
    }
    bool checkWin() const {
        node* temp = array1.head;
        while (temp != nullptr) {
            if (!temp->removed) return false;
            temp = temp->next;
        }
        temp = array2.head;
        while (temp != nullptr) {
            if (!temp->removed) return false;
            temp = temp->next;
        }
        temp = array3.head;
        while (temp != nullptr) {
            if (!temp->removed) return false;
            temp = temp->next;
        }
        temp = array4.head;
        while (temp != nullptr) {
            if (!temp->removed) return false;
            temp = temp->next;
        }
        return true;
    }
    void drawDifficultyScreen() {
        DrawRectangle(0, 0, 1400, 900, Color{ 34, 139, 34, 255 }); // Forest green background

        // Title
        DrawText("TRIPEAKS SOLITAIRE", 380, 100, 60, WHITE);
        DrawRectangle(350, 170, 700, 5, GOLD);

        // Instructions
        DrawText("Select Difficulty Level", 480, 220, 30, YELLOW);

        // Easy Button
        DrawRectangleRounded({ 450.0f, 320.0f, 500.0f, 80.0f }, 0.2f, 10, Fade(GREEN, 0.8f));
        DrawRectangleRoundedLines({ 450.0f, 320.0f, 500.0f, 80.0f }, 0.2f, 10, WHITE);
        DrawText("EASY", 650, 345, 30, WHITE);
        DrawText("(5 shuffles)", 630, 375, 16, LIGHTGRAY);

        // Medium Button
        DrawRectangleRounded({ 450.0f, 430.0f, 500.0f, 80.0f }, 0.2f, 10, Fade(ORANGE, 0.8f));
        DrawRectangleRoundedLines({ 450.0f, 430.0f, 500.0f, 80.0f }, 0.2f, 10, WHITE);
        DrawText("MEDIUM", 620, 455, 30, WHITE);
        DrawText("(10 shuffles)", 625, 485, 16, LIGHTGRAY);

        // Hard Button
        DrawRectangleRounded({ 450.0f, 540.0f, 500.0f, 80.0f }, 0.2f, 10, Fade(RED, 0.8f));
        DrawRectangleRoundedLines({ 450.0f, 540.0f, 500.0f, 80.0f }, 0.2f, 10, WHITE);
        DrawText("HARD", 650, 565, 30, WHITE);
        DrawText("(20 shuffles)", 625, 595, 16, LIGHTGRAY);

        // Footer
        DrawText("Click to select your difficulty", 500, 750, 20, RAYWHITE);
    }
    void handleDifficultyClick(int mouseX, int mouseY) {
        // Check Easy button (450, 320, 500x80)
        if (mouseX >= 450 && mouseX <= 950 && mouseY >= 320 && mouseY <= 400) {
            difficulty = 1;
            difficultySelected = true;
        }
        // Check Medium button (450, 430, 500x80)
        else if (mouseX >= 450 && mouseX <= 950 && mouseY >= 430 && mouseY <= 510) {
            difficulty = 2;
            difficultySelected = true;
        }
        // Check Hard button (450, 540, 500x80)
        else if (mouseX >= 450 && mouseX <= 950 && mouseY >= 540 && mouseY <= 620) {
            difficulty = 3;
            difficultySelected = true;
        }
    }
    void drawCard(string cardData, int x, int y, bool isRevealed, bool isRemoved) {
        int cardWidth = 90;  // Bigger cards
        int cardHeight = 120;
        float roundness = 0.12f;

        if (isRemoved) {
            // Empty space
            DrawRectangleRounded({ (float)x, (float)y, (float)cardWidth, (float)cardHeight }, roundness, 10, Fade(DARKGREEN, 0.2f));
            DrawRectangleRoundedLines({ (float)x, (float)y, (float)cardWidth, (float)cardHeight }, roundness, 10, Fade(WHITE, 0.15f));
        }
        else if (isRevealed) {
            // Shadow
            DrawRectangleRounded({ (float)x + 4, (float)y + 4, (float)cardWidth, (float)cardHeight }, roundness, 10, Fade(BLACK, 0.5f));

            // Card background with slight gradient effect
            DrawRectangleRounded({ (float)x, (float)y, (float)cardWidth, (float)cardHeight }, roundness, 10, Color{ 250, 250, 250, 255 });
            DrawRectangleRounded({ (float)x + 2, (float)y + 2, (float)cardWidth - 4, (float)cardHeight - 4 }, roundness, 10, WHITE);
            DrawRectangleRoundedLines({ (float)x, (float)y, (float)cardWidth, (float)cardHeight }, roundness, 10, Color{ 180, 180, 180, 255 });

            // Determine card color
            Color textColor = BLACK;
            Color suitColor = BLACK;
            if (cardData[0] == 'H' || cardData[0] == 'D') {
                textColor = Color{ 220, 20, 60, 255 }; // Crimson red
                suitColor = Color{ 220, 20, 60, 255 };
            }

            // Draw rank (larger)
            DrawText(cardData.c_str(), x + 28, y + 45, 32, textColor);

            // Draw small suit indicators in corners
            string rank(1, cardData[0]);
            DrawText(rank.c_str(), x + 8, y + 8, 16, suitColor);
            DrawText(rank.c_str(), x + cardWidth - 20, y + cardHeight - 24, 16, suitColor);
        }
        else {
            // Shadow for hidden card
            DrawRectangleRounded({ (float)x + 4, (float)y + 4, (float)cardWidth, (float)cardHeight }, roundness, 10, Fade(BLACK, 0.5f));

            // Card back with pattern
            DrawRectangleRounded({ (float)x, (float)y, (float)cardWidth, (float)cardHeight }, roundness, 10, Color{ 30, 60, 140, 255 }); // Royal blue
            DrawRectangleRounded({ (float)x + 3, (float)y + 3, (float)cardWidth - 6, (float)cardHeight - 6 }, roundness, 10, Color{ 40, 80, 180, 255 });
            DrawRectangleRoundedLines({ (float)x, (float)y, (float)cardWidth, (float)cardHeight }, roundness, 10, Color{ 20, 40, 100, 255 });

            // Decorative pattern
            for (int i = 0; i < 3; i++) {
                DrawCircle(x + 30 + i * 15, y + 40, 8, Fade(SKYBLUE, 0.3f));
                DrawCircle(x + 30 + i * 15, y + 80, 8, Fade(SKYBLUE, 0.3f));
            }
        }
    }
    void drawGame() {
        // Background
        DrawRectangle(0, 0, 1400, 900, Color{ 34, 139, 34, 255 }); // Forest green

        // Score Panel (left side)
        DrawRectangleRounded({ 20.0f, 20.0f, 200.0f, 120.0f }, 0.15f, 10, Fade(BLACK, 0.8f));
        DrawRectangleRoundedLines({ 20.0f, 20.0f, 200.0f, 120.0f }, 0.15f, 10, GOLD);
        DrawText("SCORE", 75, 35, 24, YELLOW);
        DrawText(TextFormat("%d", score), 90, 70, 40, WHITE);

        // Difficulty Display
        DrawText("Difficulty:", 30, 110, 16, LIGHTGRAY);
        string diffText = (difficulty == 1) ? "Easy" : (difficulty == 2) ? "Medium" : "Hard";
        Color diffColor = (difficulty == 1) ? GREEN : (difficulty == 2) ? ORANGE : RED;
        DrawText(diffText.c_str(), 120, 110, 16, diffColor);

        // Draw Level 1 (3 cards) - THREE PEAKS
        node* temp = array1.head;
        int y = 160;
        int index = 0;
        int xPositions1[3] = { 300, 650, 1000 };
        while (temp != nullptr) {
            drawCard(temp->data, xPositions1[index], y, temp->revealed, temp->removed);
            temp = temp->next;
            index++;
        }

        // Draw Level 2 (6 cards)
        temp = array2.head;
        y = 300;
        index = 0;
        int xPositions2[6] = { 230, 350, 580, 700, 930, 1050 };
        while (temp != nullptr) {
            drawCard(temp->data, xPositions2[index], y, temp->revealed, temp->removed);
            temp = temp->next;
            index++;
        }

        // Draw Level 3 (9 cards)
        temp = array3.head;
        y = 440;
        index = 0;
        int xPositions3[9] = { 165, 285, 405, 525, 645, 765, 885, 1005, 1125 };
        while (temp != nullptr) {
            drawCard(temp->data, xPositions3[index], y, temp->revealed, temp->removed);
            temp = temp->next;
            index++;
        }

        // Draw Level 4 (10 cards) - BASE
        temp = array4.head;
        y = 580;
        index = 0;
        int xPositions4[10] = { 110, 230, 350, 470, 590, 710, 830, 950, 1070, 1190 };
        while (temp != nullptr) {
            drawCard(temp->data, xPositions4[index], y, temp->revealed, temp->removed);
            temp = temp->next;
            index++;
        }

        // Draw stock pile (face down) - Bottom left
        if (stack1.head != nullptr) {
            DrawRectangleRounded({ 120.0f, 750.0f, 90.0f, 120.0f }, 0.12f, 10, Color{ 30, 60, 140, 255 });
            DrawRectangleRoundedLines({ 120.0f, 750.0f, 90.0f, 120.0f }, 0.12f, 10, Color{ 20, 40, 100, 255 });
            DrawText("STOCK", 130, 795, 18, WHITE);
        }
        else {
            DrawRectangleRounded({ 120.0f, 750.0f, 90.0f, 120.0f }, 0.12f, 10, Fade(DARKGREEN, 0.3f));
            DrawRectangleRoundedLines({ 120.0f, 750.0f, 90.0f, 120.0f }, 0.12f, 10, Fade(WHITE, 0.2f));
        }

        // Draw waste pile (top card face up) - Next to stock
        if (stack2.head != nullptr) {
            temp = stack2.head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            drawCard(temp->data, 250, 750, true, false);
        }
    }
    void handleClick(int mouseX, int mouseY) {
        // Handle stock pile click (new position)
        if (mouseX >= 120 && mouseX <= 210 && mouseY >= 750 && mouseY <= 870) {
            if (stack1.head != nullptr) {
                node* temp = stack1.head;
                stack1.head = stack1.head->next;
                stack2.insertAtEnd(temp->data);
                delete temp;
            }
            return;
        }

        // Level 4
        node* temp = array4.head;
        int xPositions4[10] = { 110, 230, 350, 470, 590, 710, 830, 950, 1070, 1190 };
        int y = 580;
        int index = 0;
        while (temp != nullptr) {
            if (mouseX >= xPositions4[index] && mouseX <= xPositions4[index] + 90 &&
                mouseY >= y && mouseY <= y + 120) {
                if (temp->revealed && !temp->removed) {
                    input = temp->data;
                    if (validateInput(input)) {
                        temp->removed = true;
                        score++;
                        stack2.insertAtEnd(temp->data);
                        reveal();
                    }
                }
                return;
            }
            temp = temp->next;
            index++;
        }

        // Level 3
        temp = array3.head;
        int xPositions3[9] = { 165, 285, 405, 525, 645, 765, 885, 1005, 1125 };
        y = 440;
        index = 0;
        while (temp != nullptr) {
            if (mouseX >= xPositions3[index] && mouseX <= xPositions3[index] + 90 &&
                mouseY >= y && mouseY <= y + 120) {
                if (temp->revealed && !temp->removed) {
                    input = temp->data;
                    if (validateInput(input)) {
                        temp->removed = true;
                        score++;
                        stack2.insertAtEnd(temp->data);
                        reveal();
                    }
                }
                return;
            }
            temp = temp->next;
            index++;
        }

        // Level 2
        temp = array2.head;
        int xPositions2[6] = { 230, 350, 580, 700, 930, 1050 };
        y = 300;
        index = 0;
        while (temp != nullptr) {
            if (mouseX >= xPositions2[index] && mouseX <= xPositions2[index] + 90 &&
                mouseY >= y && mouseY <= y + 120) {
                if (temp->revealed && !temp->removed) {
                    input = temp->data;
                    if (validateInput(input)) {
                        temp->removed = true;
                        score++;
                        stack2.insertAtEnd(temp->data);
                        reveal();
                    }
                }
                return;
            }
            temp = temp->next;
            index++;
        }

        // Level 1
        temp = array1.head;
        int xPositions1[3] = { 300, 650, 1000 };
        y = 160;
        index = 0;
        while (temp != nullptr) {
            if (mouseX >= xPositions1[index] && mouseX <= xPositions1[index] + 90 &&
                mouseY >= y && mouseY <= y + 120) {
                if (temp->revealed && !temp->removed) {
                    input = temp->data;
                    if (validateInput(input)) {
                        temp->removed = true;
                        score++;
                        stack2.insertAtEnd(temp->data);
                        reveal();
                    }
                }
                return;
            }
            temp = temp->next;
            index++;
        }
    }
    void drawGameOver() {
        DrawRectangle(0, 0, 1400, 900, Fade(BLACK, 0.85f));

        if (gameWon) {
            DrawText("YOU WIN!", 500, 300, 80, GOLD);
            DrawText("Congratulations!", 520, 410, 35, WHITE);
            DrawText(TextFormat("Final Score: %d", score), 550, 470, 30, YELLOW);
        }
        else {
            DrawText("GAME OVER", 470, 300, 80, RED);
            DrawText("No valid moves left!", 520, 410, 30, WHITE);
            DrawText(TextFormat("Final Score: %d", score), 550, 460, 28, YELLOW);
        }

        DrawText("Press R to Restart or ESC to Quit", 460, 580, 26, RAYWHITE);
    }

};

int main() {
    // Initialize window with larger size (7 inches wide, 5 inches tall at 96 DPI ≈ 1400x900)
    InitWindow(1400, 900, "TriPeaks Solitaire");
    SetTargetFPS(60);

    srand(time(0));
    setup Setup;

    // Main game loop
    while (!WindowShouldClose()) {

        // PHASE 1: Difficulty Selection
        if (!Setup.difficultySelected) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                Setup.handleDifficultyClick((int)mousePos.x, (int)mousePos.y);

                // If difficulty was selected, initialize the game
                if (Setup.difficultySelected) {
                    Setup.shuffle();
                    Setup.makeStacks();
                    Setup.makeLevels();
                    Setup.initializeLevels();
                    Setup.initializeChildren();
                    Setup.makeLevel4Reveal();
                    Setup.stack2Reveal();
                }
            }

            // Draw difficulty selection screen
            BeginDrawing();
            Setup.drawDifficultyScreen();
            EndDrawing();
        }

        // PHASE 2: Game Play
        else if (!Setup.gameOver) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                Setup.handleClick((int)mousePos.x, (int)mousePos.y);
                Setup.stack2Reveal();

                // Check win condition
                if (Setup.checkWin()) {
                    Setup.gameOver = true;
                    Setup.gameWon = true;
                }
                // Check lose condition
                else if (!Setup.validMove()) {
                    Setup.gameOver = true;
                    Setup.gameWon = false;
                }
            }

            // Draw game
            BeginDrawing();
            Setup.drawGame();
            EndDrawing();
        }

        // PHASE 3: Game Over
        else {
            if (IsKeyPressed(KEY_R)) {
                // Restart game - go back to difficulty selection
                Setup = setup();
                Setup.difficultySelected = false;
                Setup.gameOver = false;
                Setup.gameWon = false;
                Setup.score = 0;
            }

            // Draw game with game over overlay
            BeginDrawing();
            Setup.drawGame();
            Setup.drawGameOver();
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}
