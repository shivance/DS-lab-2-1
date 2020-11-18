#include <bits/stdc++.h>

//*******************************************************************************************************
template<typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template<typename T>
class LinkedList
{
    private:
        Node<T>* start;
        Node<T>* stop;
        int size;

       bool Contains(T data, Node<T>* temp)
        {

            if(temp == NULL)
                return false;

            if(temp->data == data)
                return true;
            
            return Contains(data, temp->next);
        }

    public:
        
        LinkedList()
        {

            start = NULL;
            stop = NULL;

            size = 0;            
        }

        void Insert(T data)
        {
            Node<T>* temp = new Node<T>();
            
            temp->data = data;
            temp->next = NULL;

            if (start == NULL)
            {
                start = temp;
                stop = temp;
            }
            else
            {
               stop->next = temp;
               stop = temp; 
            }
            

            size++;
        }

        void InsertAt(T data, int index)
        {
            Node<T>* trav = new Node<T>();
            Node<T>* temp = new Node<T>();
            Node<T>* prev = new Node<T>();

            temp->data = data;
            temp->next = NULL;

            trav = start; 
            for(int i = 1; i < index; i++)
            {
                prev = trav;
                trav = trav->next;
            }

            prev->next = temp;
            temp->next = trav;
            

            size++;
        }

        void Delete()
        {
            Node<T>* trav = new Node<T>();
            Node<T>* prev = new Node<T>();

            trav = start;

            while(trav->next != NULL)
            {
                prev = trav;
                trav = trav->next;  
            }

            stop = prev;
            prev->next = NULL;

            delete trav;

            size--;

        }
        
        void Delete(T data)
        {
            Node<T>* temp = new Node<T>();

            if(start->data == data)
            {
                if(start->next == NULL)
                {

                    return;
                }

                start->data = start->next->data;
                temp = start->next;
                start->next = start->next->next;

                delete temp;

                size--;
                return;

            }
            Node<T>* trav = new Node<T>();

            trav = start;


            while(trav->next != NULL && trav->next->data != data)
                trav = trav->next;

            temp = trav->next;
            trav->next = trav->next->next;

            delete temp;
            size--;

            return;

        }
        
        void DeleteAt(int index)
        {
          Node<T>* prev = new Node<T>();
          Node<T>* trav = new Node<T>();
          Node<T>* temp = new Node<T>();

          trav = start;
          for (int i = 1; i < index; i++)
          {
              prev = trav;
              trav = trav->next;
          }

          temp = prev->next;
          prev->next = trav->next;

          delete temp;
          size--;
          
        }

        void Display()
        {

            if(start == NULL) 
            {
                std::cout << "\nLinked List is empty" << std::endl;
                return;
            }

            if(start->next == NULL)
            {
                std::cout << "\n" << start->data << std::endl;
                return;
            }

            Node<T>* temp = start;
            
            while(temp != NULL)
            {
                std::cout << temp->data << ' ';
                temp = temp->next;
            }
        }

        int Size()
        {
            return size;
        }

        bool Seach(T data)
        {
             if(start == NULL) 
            {
                std::cout << "\nLinked List is empty" << std::endl;
                return false;
            }

            if(start->next == NULL)
            {
                if(start->data == data)                    
                {
                    std::cout << "\nElement is at " << 1 << "position";
                    return true;
                }
                else
                {
                    std::cout << "\nElement not found";
                    return false;
                }
                
            }

            Node<T>* trav = start;
            int pos, flag = 0;
            
            for(int i = 1; trav != NULL; i++)
            {
                if(trav->data == data)
                {
                    pos = i;
                    flag = 1;
                    break;
                }

                trav = trav->next;
            }

            if(flag == 1)
            {
                std::cout << "\nElement is at " << pos << " position";
                return true;
            }
            else
            {
                std::cout << "\nElement not found";
                return false;
            }
        }

        void Reverse()
        {
            if(start == NULL || start->next == NULL)
             return;

            std::cout << "\nList before reversal: "; Display(); std::cout << std::endl;
            Node<T> *trav = start, *prev = NULL, *next = NULL;

            while(trav != NULL)
            {
                next = trav->next;
                trav->next = prev;
                prev = trav;
                trav = next;
            }

            start = prev;
        }

        bool Contain(T data)
        {
            return Contains(data, start);
        }
};


class HashTable
{
    private:
        int size, capacity;
        int Hash(int element);
        LinkedList<int> *table[1000];
    public:
        HashTable();
        HashTable(int capacity);
        ~HashTable();

        void Insert(int data);
        void Delete(int data);
        bool Search(int data);
        void Display();
};

HashTable::HashTable()
{
    this->capacity = 1000;
    *table = new LinkedList<int>();
    for(int i = 0; i < this->capacity; i++)
        table[i] = NULL;
    size = 0;
}

HashTable::HashTable(int capacity)
{
    this->capacity = capacity;    
    *table = new LinkedList<int>();
    for(int i = 0; i < this->capacity; i++)
        table[i] = NULL;
    size = 0;
}

HashTable::~HashTable()
{
    delete *table;
}

int HashTable::Hash(int element)
{
    return element % this->capacity;
}

void HashTable::Insert(int data)
{
    int i = Hash(data);

    if(table[i] == NULL) table[i] = new LinkedList<int>();
    if(table[i]->Contain(data))
    {
        std::cout << "\nRedundant Data" << std::endl;
        return;
    }
    else
    {
        table[i]->Insert(data);
    }
    
}

void HashTable::Delete(int data)
{
    int i = Hash(data);

    if(table[i] == NULL) std::cout << "\nTable is empty" << std::endl;

    if(table[i]->Contain(data))
    {
        if(table[i]->Size() > 1)
            table[i]->Delete(data);

        else 
            table[i] = NULL;
    }

    else
    {
        std::cout << "\nData isn't present in this HashTable" << std::endl;
    }

    size++;
    
}

bool HashTable::Search(int data)
{
    int i = Hash(data);

    if(table == NULL) std::cout << "\nTable is empty" << std::endl;
    if(table[i] == NULL) return false;
    return table[i]->Contain(data);
}

void HashTable::Display()
{
    if(table == NULL)
    {
         std::cout << "\nHashTable is Empty" << std::endl;
         return;
    }
    for(int i = 0; i < capacity; i++)
    {
        if(table[i] == NULL)
            continue;
        
        table[i]->Display(); std::cout << std::endl;
    }
}




void ShowMenu()
{
    std::cout << "\nMENU";
    std::cout << "\n1)Insert Element" << std::endl;   
    std::cout << "\n2)Delete Element" << std::endl;
    std::cout << "\n3)Search for an Element" << std::endl;

}






int main()
{
    int n, data, opt;
    char ch;
    std::cout << "\nEnter the size of the Hashtable: "; std::cin >> n;
    HashTable hTable(n);

    do
    {
        ShowMenu();
        std::cout << "\nEnter your option: "; std::cin >> opt;

        switch(opt)
        {
            case 1: 
                std::cout << "\nEnter the Element to be Inserted: "; std::cin >> data;
                hTable.Insert(data);
                break;

            case 2:
                std::cout << "\nEnter the Element to be Deleted: "; std::cin >> data;
                hTable.Delete(data);
                break;

            case 3:
                std::cout << "\nEnter the Element to be searched: "; std::cin >> data;
                hTable.Search(data) ? std::cout << '\n' << data << " is present" : std::cout << "\n Element not present";
                break;

            default:
                break;
        }

        std::cout << "\nTable: " << std::endl;
        hTable.Display();

        std::cout << "\nDo you want to continue?[Y/N] "; std::cin >> ch;
    }while(ch == 'y' || ch == 'Y');

    return 0;
}
