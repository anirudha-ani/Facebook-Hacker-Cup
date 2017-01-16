#include <bits/stdc++.h>

using namespace std;

struct points
{
    long long int x ;
    long long int y ;
    long long int index ;

    points(long long i , long long int a , long long int b)
    {
        index = i;
        x=a;
        y=b;
    }


};

inline bool operator<(const points& lhs, const points& rhs)
{
//    if(lhs.index == rhs.index)
//    {
//        if(lhs.x == rhs.x)
//        {
//            return lhs.y < rhs.y;
//        }
//        return lhs.x < rhs.x;
//    }
    return lhs.index < rhs.index;
}

vector <points> sortedBottomToTop;
vector <points> sortedLeftToRight;


bool BottomToTopSort(points a , points b)
{
    if(a.y == b.y)
    {
        return a.x < b.x;
    }
    return a.y < b.y;
}

bool LeftToRightSort(points a , points b)
{
    if(a.x == b.x)
    {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main()
{
    long long int T ;
    long long int N ;
    long long int x,  y ;
    long long int R;

    freopen("fighting_the_zombies.txt" , "r" ,stdin);
    freopen("ouputB.txt" , "w" , stdout);

    scanf("%lld", &T);

    for(long long int i = 0 ; i < T ; i++)
    {
        sortedBottomToTop.clear();
        sortedLeftToRight.clear();

        scanf("%lld %lld",&N, &R);

        for(long long int j = 0 ; j < N ; j++)
        {
            scanf("%lld %lld",&x , &y);

            sortedBottomToTop.push_back(points(j+1 , x, y));
            sortedLeftToRight.push_back(points(j+1 , x , y));
        }

        sort(sortedBottomToTop.begin() , sortedBottomToTop.end() , BottomToTopSort);
        sort(sortedLeftToRight.begin() , sortedLeftToRight.end() , LeftToRightSort);

        int ans = 0 ;

        for(long long int j = 0 ; j < N ; j++)
        {
            //set <points> uniqueElements ;

            deque<points> slidingWindow1 ;

            long long int counter[55];

            points bottomPoint1 = sortedBottomToTop[j];

            memset(counter , 0 , sizeof(counter));

            for(long long int k = 0 ; k < N ; k++)
            {
                if(sortedLeftToRight[k].y >= bottomPoint1.y && abs(sortedLeftToRight[k].x - bottomPoint1.x) <= R &&(sortedLeftToRight[k].y - bottomPoint1.y)<=R )
                {
                    slidingWindow1.push_back(sortedLeftToRight[k]);

                    //uniqueElements.insert(sortedLeftToRight[k]);

                    counter[sortedLeftToRight[k].index]++;
                   //cout << "Entering Point Box 1:: " << sortedLeftToRight[k].index << " x = " << sortedLeftToRight[k].x << " y = " << sortedLeftToRight[k].y << endl ;
                    while(abs(slidingWindow1.front().x - slidingWindow1.back().x) > R)
                    {
                        counter[slidingWindow1.front().index]--;
//                        //cout << "Deleting Point Box 1:: " << slidingWindow1.front().index << " x = " << slidingWindow1.front().x << " y = " << slidingWindow1.front().y << endl ;
//                        if(counter[slidingWindow1.front().index] == 0)
//                        {
//                            //cout << "Before Erase Size = " << uniqueElements.size() << endl;
//                            uniqueElements.erase(slidingWindow1.front());
//                            //cout << "After Erase Size = " << uniqueElements.size() << endl;
//                        }

                        slidingWindow1.pop_front();
                    }
                    for(long long int l = 0 ; l < N ; l++)
                        {
                            int counter2[55];
                            memset(counter2 , 0 , sizeof(counter2));

                            deque<points> slidingWindow2 ;

                            points bottomPoint2 = sortedBottomToTop[l];


                            for(long long int m = 0 ; m < N ; m++)
                            {
                                if(sortedLeftToRight[m].y >= bottomPoint2.y && abs(sortedLeftToRight[m].x - bottomPoint2.x) <= R&&(sortedLeftToRight[m].y - bottomPoint2.y)<=R)
                                {
                                    //cout << "Entering Point Box 2:: " << sortedLeftToRight[m].index << " x = " << sortedLeftToRight[m].x << " y = " << sortedLeftToRight[m].y << endl ;
                                    slidingWindow2.push_back(sortedLeftToRight[m]);

                                    //uniqueElements.insert(sortedLeftToRight[m]);

                                    counter2[sortedLeftToRight[m].index]++;

                                    while(abs(slidingWindow2.front().x - slidingWindow2.back().x) > R)
                                    {
                                        counter2[slidingWindow2.front().index]--;
                                        //cout << "Deleting Point Box 2:: " << slidingWindow2.front().index << " x = " << slidingWindow2.front().x << " y = " << slidingWindow2.front().y << endl ;
//                                        if(counter[slidingWindow2.front().index] == 0)
//                                        {
//                                            //cout << "Before Erase Size = " << uniqueElements.size() << endl;
//                                            uniqueElements.erase(slidingWindow2.front());
//                                            //cout << "After Erase Size = " << uniqueElements.size() << endl;
//                                        }

                                        slidingWindow2.pop_front();

                                    }

                                   // int sizes = uniqueElements.size();

                                    int unique_elements = 0 ;

                                    for(int t = 0 ; t< 55 ; t++)
                                    {
                                        if(counter[t] != 0 || counter2[t] != 0)
                                        {
                                            unique_elements++;
                                        }
                                    }
                                    //ans = max(sizes , ans );
                                    ans = max(unique_elements , ans);
//                                    cout << bottomPoint1.x <<" :: " << bottomPoint1.y << " :: " << bottomPoint2.x << " :: " << bottomPoint2.y <<" :: "<< sizes << endl;
//
//                                     if(1)
//                                    {
//                                        printf("Changed here\n");
//
//
//                                        set<points>::iterator iter;
//                                        cout<<uniqueElements.size()<<endl;
//                                        int ii=0;
//                                        for(auto iter=uniqueElements.begin(); iter!=uniqueElements.end();++iter)
//                                        {
//                                            //cout<<(*iter)<<endl;
//                                            points asd = *iter;
//                                            cout<< asd.x <<" " << asd.y <<endl;
//                                        }
//                                        printf("Change end\n");
//                                    }

                                }

                            }
                        }


                }
            }
        }
        printf("Case #%lld: %d\n", i+1 , ans);
    }

    return 0 ;

}
