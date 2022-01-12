#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

int M(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    else
        return 1;
}

int XR(int a, int b)
{
    if (a == 1 && b == 1)
        return 1;
    else
        return 0;
}

int Min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int Size = 4;
    int* graph = new int[Size * Size];//remember element ixj is graph[j*Size + i]
    int* dist = new int[Size*Size];
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
            delete[] dist;
            graph = new int[Size*Size];
            dist = new int[Size * Size];
        }
    }

    if (Size == 4)
    {
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
    }
    else
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                if (i == j)
                {
                    graph[j * Size + i] = 0;
                }
                else {
                    if (rand() % 2 == 0)
                        graph[j * Size + i] = 1;
                    else
                        graph[j * Size + i] = -1;
                }
            }
        }
    }

    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if(graph[j * Size + i] == -1)
                cout << graph[j * Size + i] << " ";
            else
                cout << " " << graph[j * Size + i] << " ";
        }
        cout << endl;
    }

    //floyd-warshall algrithm
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            dist[j * Size + i] = graph[j * Size + i];
        }
    }

    for (int k = 0; k < Size; k++)
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                //dist[j * Size + i] = M(dist[j * Size + i], XR(dist[k * Size + i], dist[i * Size + k]));
                if(Min(dist[j * Size + i], dist[k * Size + i] + dist[i * Size + k]) && (dist[k * Size + i] != -1 && dist[i * Size + k] != -1))
                    dist[j * Size + i] = dist[k * Size + i] + dist[i * Size + k];
            }
        }

        //cout << endl;
        //for (int i = 0; i < Size; i++)
        //{
        //    for (int j = 0; j < Size; j++)
        //    {
        //        if (dist[j * Size + i] == -1)
        //            cout << dist[j * Size + i] << " ";
        //        else
        //            cout << " " << dist[j * Size + i] << " ";
        //    }
        //    cout << endl;
        //}
    }

    cout << endl;

    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (dist[j * Size + i] == -1)
                cout << dist[j * Size + i] << " ";
            else
                cout << " " << dist[j * Size + i] << " ";
        }
        cout << endl;
    }

    delete[] graph;
    delete[] dist;

    return 0;
}
