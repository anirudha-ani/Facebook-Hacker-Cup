#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

struct co_ordinates
{
    int x;
    int y;
}points[2005];



int main()
{
    FILE *fin  = fopen ("boomerang_constellations.txt", "r");
    FILE *fout = fopen ("output.txt", "w");
    int T , N , x, y , count_boomerang;
    double length;

    vector <double> distance[2005];

    for(int i = 0 ; i < 2005 ; i++)
    {
        for (int j = 0 ; j < 2005 ; j++)
        {
            distance[i].push_back(j);
        }
    }


    fscanf(fin , "%d", &T);

    for(int  i = 0 ; i < T ; i++)
    {
        count_boomerang = 0;
        fscanf(fin ,"%d", &N);

        for(int j =0; j < N ; j++)
        {
            fscanf(fin,"%d %d", &x , &y);

            points[j].x = x;
            points[j].y = y;
            //cout << points[j].x <<"::::" << points[j].y<<endl;
        }
        for(int j = 0 ; j < N ; j++)
        {
            for(int k = j+1 ; k < N ; k++)
            {
                length = sqrt(1.0*(points[j].x - points[k].x)*(points[j].x - points[k].x) + 1.0*(points[j].y - points[k].y)*(points[j].y - points[k].y));
                //cout <<"Length = " <<length<< endl;
                distance[j][k] = length;
                distance[k][j] = length;

//                cout<< "JK::"<<distance[j][k]<<endl;
//                cout <<"KJ::" << distance[k][j]<<endl;
            }
        }

        for(int j = 0 ; j < N ; j++)
        {
            map<double , int> mark;

            for(int k = 0 ; k < N ; k++)
            {
                if(j!=k)
                {
                    mark[distance[j][k]] = mark[distance[j][k]]+1;

                    count_boomerang += (mark[distance[j][k]]-1);
                }
            }
        }
        fprintf(fout ,"Case #%d: %d\n", i+1 , count_boomerang);
    }
    return 0;
}
