/*
----
1 0 0 1  -
0 0 1 0 
0 1 0 0
1 1 1 0

# of islands = 4
0 = water
1 = land


*/ 

#include <cstdio>
#include <cstdlib>
#include <cstring>

class island_counter
{
    public:
    int inital_count=0;
    int** dataset; 
    int icount = 0;
    int bottom_tracker = 0;
    int top_tracker = 0;
    int left_tracker = 0;
    int right_tracker = 0;
	int tot_rows = 0;
	int tot_col = 0;
    
    public:
    island_counter(int** rx, int r, int c) : tot_rows(r), tot_col(c)
    {
	  dataset = rx;/*(int**)malloc(sizeof(int) * r * c);
      memcpy(dataset, rx, sizeof(int) * r * c);*/
	  printf("hello\n");
      for(int row = 0 ; row < tot_rows ; row++)
      {
          for(int col = 0 ; col < tot_col ; col++)
          {
              //Check the top and the bottom
              int value = dataset[row][col];
			  printf("value: %d\n", value);
              if(value == 1) {
                //This means it could possibly be an island
                    //Check if its surrounded by zeroes
                    int top    = row == 0 ? 0 : dataset[row-1][col] ; //todo: make sure row-1 is valid if not then make it a zero
                    int bottom = row >= tot_rows - 1 ? tot_rows - 1 : dataset[row+1][col] ;
                    int left   = col == 0 ? 0 : dataset[row][col-1] ;
                    int right  = col >= tot_col - 1 ? tot_col - 1 : dataset[row][col+1] ;
					printf("yes\n");
                    
                    
                    //CaseA 
                    if(top==bottom==left==right==0)  {
						printf("gear: [ %d, %d, %d, %d ]\n", top, bottom, left, right);
                        icount++;
					}
                   
                    
                    
                    if(bottom!=0) 
                    {
                       //Keep on going down the column until a zero is reached
                       for(int i= bottom ; i<tot_rows ; i++) {
                         if(dataset[i][col]==0) {
                            bottom_tracker = i;
                            break;
                         }
                       }
                    }
                    
                    if(top!=0)     //Keep on going up the column until a zero is reached
                       for(int i= top ; i>=0 ; i--) {
                         if(dataset[i][col]==0) {
                            top_tracker = i;
                            break;
                         }
                      }
                   
                    if(right!=0)     //Keep on going right until a zero is reached
                       for(int i=left ; i<tot_col ; i++) {
                         if(dataset[i][row]==0) {
                            right_tracker =i;
                            break;
                         }
                         
                      }
                         
                     if(left!=0)     //Keep on going right until a zero is reached
                       for(int i=left ; i>=0 ; i--) {
                         if(dataset[i][row]==0) {
                            left_tracker =i;
                            break;
                         }
					}
                         
                      icount++;
                      
                      //Reloop with new indexes
                         
                      }
				  }
			}
	}
};

int main() {
	int **islands = (int**)malloc(sizeof(int*) * 2);
	islands[0] = (int*)malloc(sizeof(int) * 2);
	islands[1] = (int*)malloc(sizeof(int) * 2);
	islands[0][0] = islands[0][1] = islands[1][1] = 1;
	islands[1][0] = 0;
	island_counter c(islands, 2, 2);
	printf("islands: %d\n", c.icount);

	return 0;
}
