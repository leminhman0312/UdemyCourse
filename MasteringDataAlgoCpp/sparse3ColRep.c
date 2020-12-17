#include <stdio.h>
#include <stdlib.h>

struct Element
{
  int i;
  int j;
  int x;
};

struct Sparse
{
  int m;			/* no. of rows */
  int n;			/* no. of col */
  int num;			/* no. of non zero */
  struct Element *e; 		/* pointer to create array of element */
};

void create(struct Sparse *s){
  int i;
  printf("Enter dimension:\n");
  scanf("%d%d", &s->m, &s->n);
  printf("Enter no. non zero elements:\n");
  scanf("%d", &s->num);
  s->e = (struct Element *)malloc(sizeof(struct Element) * s->num);


  printf("Enter all non zero elements:\n");
  for (i = 0; i < s->num ; i++) {
    scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
  }
}


void display(struct Sparse s){
  int i, j, k = 0;
  
  for (i = 0; i < s.m ; i++) {
    for (j = 0; j < s.n ; j++) {
      
      /* check if i, j are coordinates of i,j in Element i.e. non zero */
      if (i == s.e[k].i && j == s.e[k].j) {
	printf("%d ", s.e[k++].x);
      }
      else {
	printf("0 ");
      }
    }
    printf("\n");
  }
}

struct  Sparse *add(struct Sparse *s1, struct Sparse *s2){

  int i,j,k;
  i = 0; j = 0; k = 0;
  
  /* create object to store sum */
  struct Sparse *sum;	       
  sum = (struct Sparse *)malloc(sizeof(struct Sparse));


  /* array of element in sum */
  sum->e = (struct Element *)malloc(sizeof(struct Element) * (s1->num+s2->num));

  
  
  /* check if matrices can be added */
  if (s1->m != s2->m || s1->n != s2->n) {
    return 0;
  }

  while (i < s1->num && j < s2->num) {
    if (s1->e[i].i<s2->e[j].i) {
      /* sum->e[k++] = s1->e[i++]; */

      sum->e[k] = s1->e[i];
      i++;
      k++;
    }
    else if (s1->e[i].i>s2->e[j].i) {
      /* sum->e[k++] = s2->e[j++]; */
      sum->e[k] = s2->e[j];
      k++;
      j++;
    }

    /* if row are same */
    else {
      if (s1->e[i].j<s2->e[j].j) {
	/* sum->e[k++] = s1->e[i++]; */

	sum->e[k] = s1->e[i];
	k++;
	i++;
      }
      else if (s1->e[i].j>s2->e[j].j) {
	/* sum->e[k++] = s2->e[j++]; */

	sum->e[k] = s2->e[j];
	k++;
	j++;
      }
      /* both row and col match */
      else {
	/* sum->e[k]=s1->e[i]; */
	/* sum->e[k++].x = s1->e[i++].x + s2->e[j++].x; */


	sum->e[k]=s1->e[i];
	
	sum->e[k].x = s1->e[i].x + s2->e[j].x;
	k++; i++; j++;
      }
    }
  }

  for (; i < s1->num  ; i++) {
    /* sum->e[k++] = s1->e[i]; */

    sum->e[k] = s1->e[i];
    k++;
  }

  
  for (; j < s2->num  ; j++) {
    /* sum->e[k++] = s2->e[j]; */
    
    sum->e[k] = s2->e[j];
    k++;
  }

  sum->m = s1->m;
  sum->n = s1->n;
  sum->num = k;

  return sum;
  
  
}




int main(){
  struct Sparse s1, s2, *s3;

  create(&s1);
  create(&s2);

  s3 = add(&s1, &s2);

  printf("First matrix\n");
  display(s1);
  printf("Second matrix\n");
  display(s2);
  printf("Sum matrix\n");
  display(*s3);
  
  return 0;
}
