#include<iostream>
using namespace std;

class Node {
public:
    char data; 
    Node* right, * left; 
    Node(char value) {
        data = value;
        right = left = NULL;
    }
};
class BT {
public:
    Node* root; 
    BT() {
        root = NULL; 
    }
    Node* Insert(Node* r, int item) {
        if (r == NULL) { 
            Node* newnode = new Node(item);
            r = newnode; 
        }
        else if (item < r->data) {
            r->left = Insert(r->left, item);
        }
        else if (item > r->data) {
            r->right = Insert(r->right, item);
        }
        return r;
    }
    void Insert(int item) {
        root = Insert(root, item); 
    }
};

//class for stack ADT using dynamic array 
class Stack {
private:
	char* arr;
	unsigned size;
	int capacity;
	int top;
public:
	Stack(int x) :capacity(x) {arr = new char[capacity];top = -1;size = top + 1;}
	int sizeOfStack() {return size;}
	bool isempty() {return size == 0;}
	void push(char item) {top += 1;arr[top] = item;size++;}
	void pop() {--top;--size;}
};


class evalMathExpress {
private:
	string express;
    Stack stack;
	int result;
    BT binarytree;
public:
    //class constructor for initializing the stack's capacity inserting the mathmatical expression as a string into epress variable
	evalMathExpress(string ex, int x): express(ex), stack(x) {}
    //Displaying the mathmatical expression
    void displayExpression() {
        cout << express << endl;
    }
    
    //Here i would check if the input string is a valid mathmatical 
    int evaluateExpression() { 
        for (char ch : express) {
            if (ch == '(') {
                stack.push(ch);
            }
            else if (ch == ')') {
                if (stack.isempty()) {
                    cout << "Error: Unbalanced parentheses." << endl;
                    return 0;
                }
                stack.pop();
            }
        }
        if (!stack.isempty()) {
            cout << "Error: Unbalanced parentheses." << endl;
            return 0;
        }
        int result = evaluateArithmetic(express);
        return result;
    }
    bool isOperand(char c) {
        return (c == '*' || c == '/' || c == '+' || c == '-');
    }
    bool isBrace(char c) {
        return c == '(' || c == ')';
    }
    int evaluateArithmetic(string exp) {
        for (char ch : exp) {
            if (isBrace(ch)) {
                binarytree.Insert(ch);
            }
        }
        return 0;
    }

};


int main() {
	string mathexp;
	cout << "Enter your expression: ";
	cin >> mathexp;
	evalMathExpress expression(mathexp, 1000);

    expression.displayExpression();

    int result = expression.evaluateExpression();
    cout << "Result: " << result << endl;

    return 0;
	
	
}
