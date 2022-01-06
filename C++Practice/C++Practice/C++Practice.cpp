#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include "LinkedList.h"

int main()
{
    LinkedList<int> list;
    list.Insert(0);
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(5);

    list.Print();

    cout << endl << endl;
    list.Delete(0);
    list.Delete(2);
    list.Delete(5);
    list.Delete(3);
    list.Delete(1);

    list.Print();

    list.Delete(2);
    list.Print();
}

