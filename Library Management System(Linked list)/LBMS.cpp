//   A Library Management system using LINKED LIST Data Structure......
/***
 * Time complexity of functions used in Linked list(Worst cases)
 *      INSERT : TC = O(BOOKS); Optimized: can be done in order of O(1) ;
 *       
 *      SEARCH : TC = O(BOOKS)
 *      UPDATE : TC = O(BOOKS)
 *      DELETE : TC = O(BOOKS)
 *      SORT   : TC = O(BOOKS*BOOKS) (As Bubble sort was used)
 *      SHOW   : TC = O(BOOKS)
 * *///

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class library{
    private:
        struct Node{
            int id;
            string name,author,publisher;
            Node *next_add;
        };
        public:
            Node *head=NULL;
            void menu();
            void insert();
            void search();
            void update();
            void del();
            void sort();
            void show();
};

void library::menu(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n 1. INSERT NEW RECORD";
    cout<<"\n\n 2. SEARCH RECORD";
    cout<<"\n\n 3. UPDATE RECORD";
    cout<<"\n\n 4. DELETE RECORD";
    cout<<"\n\n 5. SHOW ALL RECORD";
    cout<<"\n\n 6. Exit";

    cout<<"\n\n       Hello USER!!!.. Welcome to the online Library Assistant System...";
    cout<<"\n\n Please Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            insert();
            cout<<"Press any key to go back...";
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            sort();
            show();
            break;
        case 6:
            exit(0);    
        default:
            cout<<"\n\n Invalid Choice..Please Try Again.....";
    }
    getch();
    goto p;
}

//Function to insert a Book in the Library collection
void library::insert(){
    system("cls");
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
    cout<<"\n\n\t\t\t**************************************************************************************************";
    Node *new_node=new Node;
    cout<<"\n\n Book ID : ";
    cin>>new_node -> id;
    cout<<"\n\n Name : ";
    getline(cin>>ws,new_node -> name);
    cout<<"\n\n Author Name : ";
    getline(cin>>ws,new_node -> author);
    cout<<"\n\n Publisher Name: ";
    getline(cin>>ws,new_node -> publisher);
    new_node-> next_add=NULL;
    if(head==NULL) {
        head=new_node;
    }
    else{
        Node *ptr=head;
        while(ptr->next_add!=NULL){
            ptr=ptr->next_add;
        }
        ptr->next_add = new_node;
    }
    cout<<"\n\n\t\t\t New Book Inserted Successfully...";
}

void library::search(){
    system("cls");
    int t_id,found=0;
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
    cout<<"\n\n\t\t\t**************************************************************************************************";
    if(head==NULL){
        cout<<"\n\n Linked List is empty.....";
    }
    else{
        cout<<"\n\n Book ID : ";
        cin>>t_id;
        Node *ptr=head;
        while(ptr !=NULL){
            if(t_id == ptr->id){
                system("cls");
                cout<<"\n\n\t\t\t**************************************************************************************************";
                cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
                cout<<"\n\n\t\t\t**************************************************************************************************";
                cout<<"\n\n Book ID : "<<ptr -> id;
                cout<<"\n\n Book Name : "<<ptr -> name;
                cout<<"\n\n Author Name : "<<ptr -> author;
                cout<<"\n\n Publisher Name : "<<ptr -> publisher;
                found++;
            }
            ptr = ptr->next_add;
        }
        if(found == 0){
            cout<<"\n\n Book ID is invalid......";
        }
    }

}

void library::update(){
    system("cls");
    int t_id,found=0;
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
    cout<<"\n\n\t\t\t**************************************************************************************************";
    if(head==NULL){
        cout<<"\n\n Linked List is empty.....";
    }
    else{
        cout<<"\n\n Book ID : ";
        cin>>t_id;
        Node *ptr=head;
        while(ptr !=NULL){
            if(t_id == ptr->id){
                system("cls");
                cout<<"\n\n\t\t\t**************************************************************************************************";
                cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
                cout<<"\n\n\t\t\t**************************************************************************************************";
                cout<<"\n\n Book ID : ";
                cin>>ptr -> id;
                cout<<"\n\n Book Name : ";
                cin>>ptr -> name;
                cout<<"\n\n Author Name : ";
                cin>>ptr -> author;
                cout<<"\n\n Publisher Name : ";
                cin>>ptr -> publisher;
                found++;
                cout<<"\n\n\t\t\t Book Updated successfully...";
            }
            ptr = ptr->next_add;   
        }
        if(found == 0){
            cout<<"\n\n Book ID is invalid......";
        }
    }
}

void library::del(){
    system("cls");
    int t_id,found=0;
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
    cout<<"\n\n\t\t\t**************************************************************************************************";
    if(head==NULL){
        cout<<"\n\n Linked List is empty.....";
    }
    else{
        cout<<"\n\n Book ID : ";
        cin>>t_id;
        if(t_id == head->id){
            Node *ptr=head;
            head = head->next_add;
            delete ptr;
            cout<<"\n\n Book Deletedd successfully......";
            found++;
        }
        else{
            Node *pre = head;
            Node *ptr = head;
            while(ptr != NULL){
                if(t_id == ptr->id){
                    pre -> next_add = ptr -> next_add;
                    delete ptr;
                    cout<<"\n\n Book Deleted successfully.......";
                    found++;
                    break;
                    pre=ptr;
                    ptr = ptr -> next_add;
                } 
            }
            if(found==0){
                cout<<"\n\n Book ID is INVALID........";
            }
        }
    }
}

void library::sort(){
    if(head==NULL){
        system("cls");
        cout<<"\n\n\t\t\t**************************************************************************************************";
        cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
        cout<<"\n\n\t\t\t**************************************************************************************************";
        cout<<"\n\n Linked list is empty.......";
        getch();
        menu();
    }
    int count=0,t_id;
    string t_name,t_author,t_publisher; 
    Node *ptr=head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next_add;
    }
    for(int i=1;i<=count;i++){
        Node *ptr = head;
        for(int j=1;j<=count-i;j++){
            if(ptr -> id >ptr->next_add->id){
                //save data into temporary variables
                t_id = ptr->id;
                t_name = ptr->name;
                t_author = ptr->author;
                t_publisher = ptr->publisher;
                //save data into current node
                ptr->id = ptr->next_add->id;
                ptr->name = ptr->next_add->name;
                ptr->author = ptr->next_add->author;
                ptr->publisher = ptr->next_add->publisher;
                //save data into next node
                ptr->next_add->id = t_id;
                ptr->next_add->name = t_name;
                ptr->next_add->author = t_author;
                ptr->next_add->publisher = t_publisher;
            }
            ptr = ptr->next_add;
        }
    }
}

void library::show(){
    system("cls");
    cout<<"\n\n\t\t\t**************************************************************************************************";
    cout<<"\n\n\t\t\t||                   ================LIBRARY MANAGEMENT SYSTEM==================                ||";
    cout<<"\n\n\t\t\t**************************************************************************************************";
    Node *ptr=head;
    while(ptr !=NULL){    
        cout<<"\n\n Book ID : "<<ptr -> id;
        cout<<"\n\n Book Name : "<<ptr -> name;
        cout<<"\n\n Author Name : "<<ptr -> author;
        cout<<"\n\n Publisher Name : "<<ptr -> publisher;
        cout<<"\n\n\n ===================================================================================================";
        ptr = ptr->next_add;
    }
}

main(){
    library obj;
    obj.menu();
}

