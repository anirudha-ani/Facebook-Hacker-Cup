#include <bits/stdc++.h>

using namespace std ;

int price[305][305];
int taken[305][305];
int total_taken[305];




int main()
{
    freopen("pie_progress.txt" , "r" , stdin);
    freopen("outputOfA.txt", "w" , stdout);
  int T ;

  scanf("%d",&T);

  for(int i = 0 ; i < T ; i++)
  {
    int N , M ;

    long long int minimum_cost = 0;

    memset(price , 0 , sizeof(price));
    memset(taken , 0 , sizeof(taken));
    memset(total_taken , 0 , sizeof(total_taken));

    scanf("%d %d",&N , &M );

    for(int j = 0 ; j < N ; j++)
    {
      for(int k = 0 ; k < M ; k++)
      {
        scanf("%d", &price[j][k] );
      }
    }

    for(int j = 0 ; j < N ; j++)
    {
      long long int temp_min_cost = 1000000000000;
      int temp_taken_n = -1 ;
      int temp_taken_m = -1 ;
      int temp_total_taken_from = -1 ;

      for(int k = 0 ; k <= j ; k++)
      {
          if(total_taken[k] >= M)
          {
              continue;
          }

          for(int l = 0 ; l < M ; l++)
          {
              if(taken[k][l] == 0)
              {
                  if((minimum_cost - total_taken[k] * total_taken[k] + (total_taken[k] + 1) * (total_taken[k]+1)) + price[k][l] < temp_min_cost)
                  {
                      temp_min_cost = (minimum_cost - total_taken[k] * total_taken[k] + (total_taken[k] + 1) * (total_taken[k]+1)) + price[k][l]  ;
                      temp_taken_n = k;
                      temp_taken_m = l;
                      temp_total_taken_from = k;

                     // cout << temp_min_cost << " " << temp_taken_n << " " << temp_taken_m << " " << temp_total_taken_from << endl ;
                  }

              }
          }
      }

      minimum_cost = temp_min_cost;
      taken[temp_taken_n][temp_taken_m] = 1;
      total_taken[temp_total_taken_from]++;

    }

    printf("Case #%d: %lld\n", i+1 , minimum_cost );
  }



  return 0 ;
}
