#include<iostream>
#include<string>
using namespace std;

int n;

class pizza {
    string name, add;
    int qt,price;
    int front = -1, rear = -1;
public:
    void acceptorder();
    void serveorder();
    void display();
} q[100];

void pizza::display() {
    if (front == -1 && rear == -1) {
        cout << "\nNo orders are available!\n";
    } 
    else {
        cout<<"\n***Orders Available***\n";
        int i = front;
        while (i != rear) {
            cout << q[i].name << "\t" << q[i].add << "\t";
            cout << q[i].qt << "\t" <<q[i].price << "\n";
            i = (i + 1) % n;
        }
        cout << q[rear].name << "\t" << q[rear].add << "\t" << q[rear].qt << "\t" << q[rear].price << "\n"; 
    }
}

void pizza::acceptorder() {
    if ((rear + 1) % n == front) {
        cout << "\nMaximum Orders are reached!\nNo more orders can be taken!\n";
    } 
    else {
        if (rear == -1 && front == -1) {
            front = 0;
        }
        rear = (rear + 1) % n;

        cout << "\nEnter your name: ";
        cin>>q[rear].name;  
        cout << "Enter your address: ";
        cin>>q[rear].add;   
        cout << "Enter the quantity of pizzas: ";
        cin >> q[rear].qt;
        q[rear].price = (q[rear].qt * 100);
        
    }
}

void pizza::serveorder() {
    if (rear == -1 && front == -1) {
        cout << "\nNo orders are available!\n";
    } 
    else if (rear == front) {
        
        cout<<"\n Order Served : \n";
        cout << q[front].name << "\t" << q[front].add << "\t"<<q[front].qt << "\n";
        cout<<"\n Total Price :"<< q[front].price <<"\n";
        front = rear = -1;
    } 
    else {
        cout<<"\n Order Served : \n";
        cout << q[front].name << "\t" << q[front].add << "\t"<<q[front].qt << "\n";
        cout<<"\n Total Price :"<< q[front].price <<"\n";
        front = rear = -1;
        front = (front + 1) % n;
    }
}

int main() {
    int choice;
    cout << "Enter the maximum number of orders: ";
    cin >> n;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit";
        cout << "\nEnter Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: q[0].acceptorder(); break;
        case 2: q[0].serveorder(); break;
        case 3: q[0].display(); break;
        }
    } while (choice != 0);

    return 0;
}
