#include <iostream>
#include <stack>

using namespace std;

bool balanced(const string& s) 
{
    stack<char> stack;
    for (char c : s) 
    {
        switch (c) 
        {

        case '(': stack.push(')'); break;
        case '[': stack.push(']'); break;
        case '{': stack.push('}'); break;
        case '<': stack.push('>'); break;

        case ')':
        case ']':
        case '}':
        case '>':
            if (stack.empty() || stack.top() != c) 
                throw "стэк либо пуст либо скобки не соответствует";
            stack.pop();
            break;
        default:
            break;
        }
    }
    return stack.empty();
}

void test(const string& s)
{
    cout << '"' << s << "\" " << (balanced(s) ? "yes" : "no") << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        test("({x-y-z}*[x+2y]-(z+4x))");
        test("([x-y-z}*[x+2y)-{z+4x)]");
    }
    catch (const char *exception)
    {
        cout<< "Error: " << exception << std::endl;
    }
   
   
}
/*Задание 1.
Добавьте в класс двусвязного списка механизм обработ-
ки исключений. На ваш выбор генерируйте исключения
в случае ошибок. Например, нехватка памяти, попытка
удаления из пустого списка и т.д.*/