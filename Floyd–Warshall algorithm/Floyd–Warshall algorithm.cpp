#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    int Size = 4;
    int* graph = new int[Size*Size];//remember element ixj is graph[j*Size + i]
    string el = "";

    srand(time(NULL));

    //constructing graph
    while (el != "N" && el != "n")
    {
        system("cls");
        cout << "Czy chcesz zmienić rozmiar grafu(" << Size << ")? T / N" << endl;
        cin >> el;
        if (el == "T" || el == "t")
        {
            cout << "Podaj rozmiar: ";
            cin >> el;
            Size = atoi(el.c_str());
            delete[] graph;
            graph = new int[Size*Size];
        }
    }

    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (i == j)
            {
                graph[j * Size + i] = 0;
            }
            else {
                system("cls");
                cout << "Czy chcesz połączyć wierzchołek " << i << " do " << j << " T/N?";
                cin >> el;
                if (el == "T" || el == "t")
                    graph[j * Size + i] = 1;
                else
                    graph[j * Size + i] = -1;
            }
        }
    }

    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            cout << graph[j * Size + i];
        }
        cout << endl;
    }

    //floyd-warshall algrithm

    delete[] graph;

    return 0;
}
