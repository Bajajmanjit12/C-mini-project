#include <iostream>
using namespace std;

class MLS
{
    int track_no, year; // data fields
    string album, artist;

    // address field
    MLS *next, *prev;

public:
    void accept();
    void display();
    void search();
    void update();
    void remove();
    void count();
};

MLS *start = NULL;
MLS *newnode, *temp;
void MLS ::accept() // accept the track
{
    newnode = new MLS;
    cout << "Enter the details\n:";
    cout << "\nT_no\tAlbum\tArtist\tYear\n";
    cin >> newnode->track_no >> newnode->album >> newnode->artist >> newnode->year;
    newnode->prev = newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        //end = temp;
    }
}

void MLS ::display() // display the track record
{
    if (start == NULL)
    {
        cout << "\nNo Tracks are avialable!";
    }
    else
    {
        temp = start;
        cout << "\nT_no\tAlbum\tArtist\tYear\n";
        while (temp != NULL)
        {
            cout << temp->track_no << "\t" << temp->album << "\t" << temp->artist << "\t" << temp->year << endl;
            temp = temp->next;
        }
    }
}

void MLS::count() // count the track record
{
    int count = 0;
    if (start == NULL)
    {
        cout << "\nNo Tracks are avialable!";
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        cout << "\nNumber of Tracks availablle:" << count << endl;
    }
}

void MLS::remove() // delete the track
{
    MLS *q, *p;s
    int i, flag = 0;

    if (start == NULL)
    {
        cout << "\nTracks are not available";
    }
    else
    {
        cout << "\nEnter the Track id to be delete: ";
        cin >> i;

        if (start->track_no == i)
        {
            temp = start;
            start = start->next;
            start->prev = NULL;
            cout << "\n First Track deleted\n";
            delete temp;
        }

        temp = start;
        while (temp->next->next != NULL)
        {
            if (temp->track_no == i)
            {
                flag = 1;
                p = temp;
                break;
            }
            q = temp;
            temp = temp->next;
        }
    }
    cout<<"\n Temmmmmm:::"<<temp->track_no<<"\t"<<flag;
    if (flag == 1)
    {
        cout << p << endl;
        cout << "\nTrack deleted";
        q->next = p->next;
        p->next->prev = q;
        delete p;
    }
    
    else if(flag==0)
    {
        MLS *qq;
        qq=temp;
        temp=temp->next;
        if(temp->track_no==i)
        {
            temp->prev->prev=NULL;
            qq->next=NULL;
            delete temp;

        }
        else
        cout << "\nTrack not found";
    }
}

void MLS::search() // search the track
{
    int i, flag = 0;
    if (start == NULL)
    {
        cout << "\nNo Track are available";
    }
    else
    {
        cout << "\nEnter the Track id to be search : ";
        cin >> i;
        temp = start;
        while (temp != NULL)
        {
            if (temp->track_no == i)
            {
                flag = 1;
                cout << "\nTrack found\n";
                cout << temp->track_no << "\t" << temp->album << "\t" << temp->artist << "\t" << temp->year << endl;
                break;
            }
            temp = temp->next;
        }
    }

    if (flag == 0)
    {
        cout << "\nTrack not found";
    }
}
void MLS ::update() // Upadate the track
{
    int i, flag = 0;
    if (start == NULL)
    {
        cout << "\nNo Track are available";
    }
    else
    {
        cout << "\nEnter the Track id to be update : ";
        cin >> i;
        temp = start;
        while (temp != NULL)
        {
            if (temp->track_no == i)
            {
                flag = 1;
                cout << "\nTrack found\n";
                cout << "\nEnter new record";
                cout << "\nT_no\tAlbum\tArtist\tYear\n";
                cin >> temp->track_no >> temp->album >> temp->artist >> temp->year;
                break;
            }
            temp = temp->next;
        }
    }

    if (flag == 0)
    {
        cout << "\nTrack not found";
    }
}

int main() // main function
{
    MLS m;
    int choice;

    do
    {
        cout << "\n1.Accept\n2.Display\n3.count\n4.search\n5.Delete\n6.Update\n";
        cout << "\nEnter your choice:";
        cin >> choice;

        switch (choice)
        {

        case 1:
            m.accept();
            break;

        case 2:
            m.display();
            break;

        case 3:
            m.count();
            break;

        case 4:
            m.search();
            break;

        case 5:
            m.remove();
            break;

        case 6:
            m.update();
            break;
        }
    } while (choice != 0);
}
