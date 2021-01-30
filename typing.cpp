#include <iostream>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <algorithm>
#define title SetConsoleTitle
using namespace std;
const vector<string> words{"deoxyribonucleic", "deinstitutionalization", "counterrevolutionaries", "internationalization", "pneumonoultramicroscopicsilicovolcanoconiosis", "Bababadalgharaghtakamminarronnkonnbronntonnerronntuonnthunntrovarrhounawnskawntoohoohoordenenthurnuk", "semihemidemisemihemidemisemihemidemisemiquaver", "sexmilliaquingentsexagintillion", "antidisestablishmentarianism", "supercalifragilisticexpialidocious", "Gammaracanthuskytodermogammarus loricatobaicalensis"};
static void setKeyBoard(int num)
{
    HWND window = GetConsoleWindow();
    DWORD layout = num; // Layout must be already loaded!
    PostMessage(window, WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)layout);
    PostMessage(window, WM_INPUTLANGCHANGE, 0, (LPARAM)layout);
}

void color(int color = 7)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void clear()
{
    system("cls");
}

void halt()
{
    cout << "Press any key to continue..." << endl;
    char val = getch();
}

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void scroll(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i] << flush;
    }
    cout << endl;
}

int main()
{
    LoadKeyboardLayout(_T("0x00000409"), KLF_ACTIVATE | KLF_SETFORPROCESS);
    setKeyBoard(0x00000409);
    clear();
    title(_T("TYPING METEORITE"));
    color(207);
    scroll("KEY METEORITE");
    color();
    clear();
    scroll("The world is in danger!");
    scroll("The \"typing meteorites\" approached the earth, and only you can destroy it!");
    scroll("Save the universe, quick!");
    halt();
    clear();
    scroll("Destroy a meteorite by typing the meteorite's content on the top! (Each occurence of the character will be destroyed)");
    scroll("Good luck!");
    halt();
    clear();
    int misses = 0;
    for (int i = 0; i < words.size(); i++)
    {
        halt();
        clear();
        for (int j = 0; j < misses; j++)
            cout << endl;
        color(143);
        string word = words[i];
        cout << word << endl;
        color();
        while (!word.empty())
        {
            string original = word;
            word.erase(std::remove(word.begin(), word.end(), getch()), word.end());
            if (word == original)
                misses++;
            if (misses >= 10)
            {
                color(47);
                cout << "Oh no! The asteroid hit earth!" << endl;
                color(44);
                cout << "GAME OVER                     " << endl;
                color();
                halt();
                clear();
                LoadKeyboardLayout(_T("0x00000404"), KLF_ACTIVATE | KLF_SETFORPROCESS);
                setKeyBoard(0x00000404);
                return 0;
            }
            clear();
            for (int j = 0; j < misses; j++)
                cout << endl;
            color(143);
            cout << word << endl;
            color();
        }
    }
    halt();
    clear();
    LoadKeyboardLayout(_T("0x00000404"), KLF_ACTIVATE | KLF_SETFORPROCESS);
    setKeyBoard(0x00000404);
    color(47);
    cout << "Yes! You saved the earth!" << endl;
    color();
    halt();
    clear();
    return 0;
}