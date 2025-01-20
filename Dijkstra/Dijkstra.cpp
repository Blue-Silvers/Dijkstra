#include <limits>
#define inf std::numeric_limits<int>::max()
#include <iostream>
#include <vector>

int graph[7][7] = {
0, 10, 15, inf, 30, inf, inf,
inf, 0, inf, inf, inf, 57, inf,
15, inf, 0, 16, inf, inf, 52,
inf, inf, 13, 0, inf, inf, inf,
30, inf, inf, inf, 0, 11, 34,
inf, 49, inf, inf, 12, 0, inf,
inf, inf, 63, inf, 35, inf, 0 };

int newGraph[12][12] = {
//A     B         C         D       E       F       G       H       I       J       K       L
0,      2,       inf,    inf,    13,     inf,    inf,    inf,    inf,    inf,    7,      10, //A
inf,    0,       inf,    inf,    inf,    inf,    1,      inf,    inf,    inf,    inf,    inf, //B
inf,    inf,     0,      inf,    1,      inf,    inf,    1,      inf,    2,      inf,    inf, //C
inf,    inf,     inf,    0,      inf,    8,      inf,    4,      inf,    inf,    inf,    inf, //D
inf,    inf,     inf,    inf,    0,      inf,    inf,    inf,    inf,    5,      inf,    inf, //E
inf,    inf,     inf,    inf,    inf,    0,      inf,    inf,    inf,    inf,    inf,    inf, //F
inf,    inf,     inf,    5,      inf,    inf,    0,      2,      3,      inf,    inf,    inf, //G
inf,    inf,     inf,    inf,    inf,    10,     inf,    0,      4,      7,      inf,    inf, //H
inf,    inf,     inf,    inf,    inf,    5,      inf,    inf,    0,      inf,    inf,    inf, //I
inf,    inf,     inf,    inf,    inf,    1,      inf,    inf,    9,      0,      inf,    inf, //J
inf,    inf,     inf,    inf,    8,      inf,    inf,    inf,    inf,    inf,    0,      5, //K
inf,    inf,     inf,    inf,    inf,    inf,    inf,    12,     inf,    inf,    inf,    0, //L
};

int result = 0;
std::string alph[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
void Dijkstra(int startPoint, int endPoint, int(&newGraph)[12][12]);

int main()
{
    std::cout << "Hello World!\n";
    Dijkstra(0, 9, newGraph);//AKCJ or ABGHJ
    
}


void Dijkstra(int startPoint, int endPoint, int(&newGraph)[12][12])
{
    int dist[12];
    int prev[12];

    std::vector<int> openNodes;

    for (int i = 0; i < 12; i++)
    {
        dist[i] = inf;
        prev[i] = -1;
        openNodes.push_back(i);
    }
    dist[startPoint] = 0;

    while (!openNodes.empty())
    {
        int currentNode = startPoint;
        for (int i = 0; i < openNodes.size(); i++)
        {
            if (dist[i] < dist[currentNode]) 
            {
                currentNode = i;
            }
        }
        int u = openNodes[currentNode];
        openNodes.erase(openNodes.begin() + currentNode);

        //for (int i = 0; i < openNodes.size(); i++)
        //{
            for (int j = 0; j < 12; j++)
            {
                if (newGraph[u][j] > 0 && newGraph[openNodes[u]][j] != inf)
                {
                    int alt = dist[currentNode] + newGraph[u][j];

                    if (alt < dist[j]) 
                    {
                        dist[j] = alt;
                        prev[j] = u;
                        
                    }
                }
            }
            
    }
            for (int i = 0; i < 12; i++)
            {
                std::cout << alph[dist[i]] + ", " + alph[prev[i]] + "\n";
            }
    result = dist[startPoint], prev[startPoint];
    std::cout << result + "\n";
    /*std::cout << alph[dist[startPoint]] + ", " + alph[prev[endPoint]];*/
}
