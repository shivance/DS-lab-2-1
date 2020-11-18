#include <bits/stdc++.h>


//This HashTable acts as an ADT in order to make it convenient to implement the three forms of Open Addressing easier
class HashTable
{
    protected:

        int size, capacity;
        int Hash(int element);
        int virtual Rehash(int, int) { };
        int *table;
    
    public:

        HashTable();
        HashTable(int capacity);
        ~HashTable();
        
        bool IsFull() {  return ( size >= capacity); }
        bool IsEmpty() { return (size == 0); }
        int Capacity() { return this->capacity; }
        int Size() { return this->size; }


        void Insert(int data);
        void Delete(int data);
        bool Search(int data);
        void Display();

};

int HashTable::Hash(int element)
{
    return element % capacity;
}

HashTable::HashTable() 
{
    this->capacity = 1000;
    table = new int;
    for(int i = 0; i < this->capacity; i++)
        table[i] = -1;
    size = 0;
}

HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    table = new int;
    for(int i = 0; i < this->capacity; i++)
        table[i] = -1;
    size = 0;
}

HashTable::~HashTable()
{
    delete table;
}


void HashTable::Insert(int data)
{
    if(IsFull())
    {
        std::cout << "\nTable is Full" << std::endl;
        return;
    }
    int k, j = 1;
    int i = k = Hash(data);

    if(table[i] == -1)
    {
        table[i] = data;
    }
    else
    {
        while(table[i] != -1)
        {
            //std::cout << "\nNew Index " << i << std::endl;
            i = Rehash(data , j);
            j++; 
            if(k == i) return; // To prevent the key from cycling 
        }
        
        table[i] = data;
    }
    size++;
}

void HashTable::Delete(int data)
{
    if(IsEmpty())
    {
        std::cout << "\nTable is Empty" << std::endl;
        return;
    }
    int k, j = 1;
    int i = k = Hash(data);

    if(table[i] == data)
        table[i] = -1;

    else
    {
        while(table[i] != data)
        {
            //std::cout << "\nNew Index " << i << std::endl;
            i = Rehash(data , j);
            j++; 
            if(k == i)
            {
                std::cout << "\nElement Not Found" << std::endl; 
                return; // To prevent the key from cycling 
            }
        }
        
        table[i] = -1;
    }
    size--;
}

bool HashTable::Search(int data)
{
    if(IsEmpty())
    {
        std::cout << "\nTable is Empty" << std::endl;
        return false;
    }

    int k, j = 1;
    int i = k = Hash(data);

    if(table[i] == data)
        return true;        

    else
    {
        while(table[i] != data)
        {
            //std::cout << "\nNew Index " << i << std::endl;
            i = Rehash(data , j);
            j++; 
            if(k == i) return false; // To prevent the key from cycling 
        }
        
        if(table[i] == data)
            return true;

        return false;
    }

}

void HashTable::Display()
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << table[i] << " ";
    }
    
}


//Quadratic Probing
class QuadTable : public HashTable
{

    private:
        int Rehash(int, int);
    public:
        QuadTable();
        QuadTable(int _capacity);
        ~QuadTable();
        

};

QuadTable::QuadTable()
    : HashTable() { }

QuadTable::QuadTable(int _capacity)
    : HashTable(_capacity) { }

QuadTable::~QuadTable()
{
    delete table;
}

int QuadTable::Rehash(int element , int k)
{ 
    if(IsFull())
    {
        std::cout << "\nTable is Full" << std::endl;
        return INT32_MIN;
    }
        int index = Hash(element);
        return Hash(index + (k*k));
}


//Linear Probing
class LinearTable : public HashTable
{

    private:
        int Rehash(int, int);
    public:
        LinearTable();
        LinearTable(int _capacity);
        ~LinearTable();
        

};

LinearTable::LinearTable()
    : HashTable() { }

LinearTable::LinearTable(int _capacity)
    : HashTable(_capacity) { }

LinearTable::~LinearTable()
{
    delete table;
}

int LinearTable::Rehash(int element, int k)
{ 
    if(IsFull())
    {
        std::cout << "\nTable is Full" << std::endl;
        return INT32_MIN;
    }
    int index = Hash(element);
    return Hash(index + k);
}


//Double Hashing
class DoubleTable : public HashTable
{

    private:
        int Rehash(int, int);
        int Hash2(int element) { return (7 - (element % 7));}
    public:
        DoubleTable();
        DoubleTable(int _capacity);
        ~DoubleTable();
};

DoubleTable::DoubleTable()
    : HashTable() { }

DoubleTable::DoubleTable(int _capacity)
    : HashTable(_capacity) { }

DoubleTable::~DoubleTable()
{
    delete table;
}

int DoubleTable::Rehash(int element, int k)
{
    if(IsFull())
    {
        std::cout << "\nTable is Full" << std::endl;
        return INT32_MIN;
    }
    int index = Hash(element);
    return Hash(index + (k * Hash2(element)));
}

//*******************************************************************************************************

void ShowMenu()
{
    std::cout << "\nMENU";
    std::cout << "\n1) Insert Element" << std::endl;   
    std::cout << "\n2) Delete Element" << std::endl;
    std::cout << "\n3) Search for an Element" << std::endl;
    std::cout << "\n4) Capacity of the Table" << std::endl;
    std::cout << "\n5) Size of the Table " << std::endl;
}

void ModeSelection()
{
    std::cout << "\nSELECT THE ADDRESSING MODE: " << std::endl;
    std::cout << "\n1)Linear Probing " << std::endl;
    std::cout << "\n2)Quadratic Probing " << std::endl;
    std::cout << "\n3)Double Hashing " << std::endl;
    std::cout << "\n4)Exit " << std::endl;

}

void Operation(HashTable *hTable)
{
    char ch;
    int opt, data;
    do
    {
        ShowMenu();
        std::cout << "\nEnter your option: "; std::cin >> opt;

        switch(opt)
        {
            case 1: 
                std::cout << "\nEnter the Element to be Inserted: "; std::cin >> data;
                hTable->Insert(data);
                break;

            case 2:
                std::cout << "\nEnter the Element to be Deleted: "; std::cin >> data;
                hTable->Delete(data);
                break;

            case 3:
                std::cout << "\nEnter the Element to be searched: "; std::cin >> data;
                hTable->Search(data) ? std::cout << "\nElement Found" : std::cout << "\nElement not found" << std::endl;
                break;

            case 4:
                std::cout << "\nCapacity = " << hTable->Capacity();
                break;

            case 5:
                std::cout << "\nSize = " << hTable->Size();
                break;
            default:
                break;
        }

        std::cout << "\nTable: " << std::endl;
        hTable->Display();
        std::cout << "\nDo you want to continue?[Y/N] "; std::cin >> ch;
    }while(ch == 'y' || ch == 'Y');

    delete hTable;
}


//*******************************************************************************************************


int main()
{
    int n, data, opt;
    char ch;
    LinearTable *lTable = NULL;
    QuadTable *qTable = NULL;
    DoubleTable *dTable = NULL;
    
    do
    {
        ModeSelection();

        std::cout << "\nEnter your Choice: "; std::cin >> opt;
        
        switch (opt)
        {
            case 1:
                std::cout << "\nEnter the size of the Hashtable: "; std::cin >> n;
                std::cout << "\n\t\t LINEAR PROBING " << std::endl; 
                lTable = new LinearTable(n);
                Operation(lTable);
                break;

            case 2:
                std::cout << "\nEnter the size of the Hashtable: "; std::cin >> n;
                std::cout << "\n\t\t QUADRATIC PROBING " << std::endl; 
                qTable = new QuadTable(n);
                Operation(qTable);
                break;

            case 3:
                std::cout << "\nEnter the size of the Hashtable: "; std::cin >> n;
                std::cout << "\n\t\t DOUBLE HASHING " << std::endl; 
                dTable = new DoubleTable(n);
                Operation(dTable);
                break;

            default:
                exit(0);
                break;
        }
    }while(true);

    return 0;
}
