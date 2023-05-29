/*
BLOOM FILER 
It is a probablistic data structure that uses hashing
to store stuff in an array. 
It doest store the values perse but it stores stuff in
the form of 0 and 1 to tell weather a thing is absent or 
present.

Note: It is a false postitive DS.

Algo:-

1. Make a function to hash and return an index value
2. Make a function to prepare the array for insertion
3. Make a function to check and insert value 
4. A function to search if the value is present or not
5. In Main 
    * Switch case to check which command the user
    wants to run 
    * Add insert function which inserts the value
    into the bloom filter
    * Add search function which checks if a perticular
    element is present or not
    * add a while loop to incoporate an exit function
*/

#include <iostream>
using namespace std;

#define MAX 10

int hash_fun(int x)
{
    int temp;
    temp = (x + 4)/3 + 1;
    return temp%MAX;  
}

bool search(int x, int arr[])
{
    int temp;
    temp = hash_fun(x);
    if(arr[temp]==1)
    {
        return true;
    }
    return false;
}

int bloom(int x,int arr[])
{
    int temp;
    temp = hash_fun(x);
    if(arr[temp]==0)
    {
        arr[temp] = 1;
        return 1;
    }

    return -1;
}

void arr_create(int arr[])
{
    for(int i = 0;i<MAX;i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    int arr[MAX];
    arr_create(arr);
    int choice;

    do
    {
    cout << "\n" << "1.INSERT" << "\t" << "2.SEARCH" << "\t" << "3.RESET FILTER" << "\t" << "4.EXIT\n";
    cout << ">> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        {
            int val,temp;
            cout << "Enter number: ";
            cin >> val;
            temp = bloom(val,arr);
            if(temp == 1)
            {
                cout << "Element Inserted" << "\n";
            }
            else
            {
                cout << "Element Already Present" << "\n";
            }
        }    
        break;
    case 2:
        {
            int temp;
            cout << "Enter element to search: ";
            cin >> temp;

            if(search(temp,arr) == true)
            {
                cout << "Present\n";
            }
            else
            {
                cout << "Absent\n";
            }
        }
        break;
    case 3:
        {
            arr_create(arr);
            cout << "Array reinitialized \n";
        }
        break;
    case 4:
        {
            cout << "Exiting.. \n";
        }
        break;
    default:
        cout << "Enter appropriate choice! \n";
        break;
    }

    } while (choice!=4);
    
    return 0;
}

