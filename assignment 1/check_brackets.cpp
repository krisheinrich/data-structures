#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::stack;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if ((type == '[' && c == ']') ||
            (type == '{' && c == '}') ||
            (type == '(' && c == ')')
           )
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b = Bracket(next, position);
            opening_brackets_stack.push(b);
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()
            || !opening_brackets_stack.top().Matchc(next)) {
                printf("%d", 1+position);
                return 0;
            } else {
                opening_brackets_stack.pop();
            }
        }
    }

    if (opening_brackets_stack.empty()) {
        cout << "Success";
    } else {
        printf("%d", 1+opening_brackets_stack.top().position);
    }

    return 0;
}
