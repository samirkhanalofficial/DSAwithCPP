#include "iostream"
#define MAXSIZE 5
using namespace std;
int i, stackbox[MAXSIZE], bottom;
void push(int number)
{
    if (bottom >= MAXSIZE)
    {
        cout << "Stack overflow" << endl;
        cin >> number;
    }
    else
    {
        for (i = bottom; i >= 0; i--)
        {
            stackbox[i] = stackbox[i - 1];
        }
        stackbox[0] = number;
        bottom++;
    }
}
void showStack()
{
    cout << "stack = [";
    for (i = 0; i < bottom; i++)
    {
        cout << stackbox[i] << " , ";
    }
    cout << " ] " << endl;
}
int showMenu()
{
    system("clear");
    showStack();
    int operation = 0;
    cout << "Please choose your operation:" << endl
         << "0) exit" << endl
         << "1) push" << endl
         << "2) pop" << endl;
    cin >> operation;
    return operation;
}
void pop()
{
    system("clear");
    if (bottom <= 0)
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        for (i = 0; i < bottom; i++)
        {
            stackbox[i] = stackbox[i + 1];
        }
        bottom--;
        cout << "First item poped" << endl;
    }
}
int main()
{
    int operation = 1, input;
    while (operation != 0)
    {
        operation = showMenu();
        switch (operation)
        {
        case 0:
            exit;
            break;
        case 1:
            cout << "enter the value to push : ";
            cin >> input;
            push(input);
            showStack();
            break;
        case 2:
            pop();
            showStack();
            cin >> input;
            break; // getch not working for g++ compiler on Ubuntu
        default:
            cout << "invalid operation";
            cin >> input;
            showMenu();
            break;
        }
    }
    return 0;
}