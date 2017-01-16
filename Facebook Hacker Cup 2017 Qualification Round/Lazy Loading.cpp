#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("lazy_loading.txt" , "r", stdin);
    freopen("output.txt", "w",stdout);
    int T , N , input , counter ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d" , &N);
        counter = 0 ;
        priority_queue<int> D;

        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d", &input);

            D.push(input);
        }
        while(D.empty() != true)
        {
            int top = D.top();
            D.pop();
            bool possible = false ;
            for(int j = 1 ; j <= N ; j++)
            {
                if(top*j >= 50)
                {
                    possible = true ;
                    N -= j;
                    counter++;
                    break;
                }
            }
            if(!possible)
            {
                break;
            }
        }
        printf("Case #%d: %d\n",i+1 , counter);
    }
    return 0 ;
}
