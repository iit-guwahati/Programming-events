#include<stdio.h>
#include<math.h>
static unsigned int MAX=1000000000;
int main(){
unsigned int t, N, next, i, left, right, min=0, max=MAX;
scanf("%d", &t);
while(t--){
	scanf("%d", &N);
	scanf("%d", &left);
	right=left;
	min=0, max=MAX;
	for(i=1;i<N;i++){
		scanf("%d", &next);
		if(next>=right){
			max=((left+next)/2)>max?max:((left+next)/2);
			if(min>max)	min=-1;
			right=next;
		}
		else if(next<=left){
			min=((right+next)/2+(right+next)%2)<min?min:((right+next)/2+(right+next)%2);
			if(min>max)	min=-1;
			left=next;
		} else {
			min=-1;
		}
		//printf("Next: %d\tMin max: %d %d\n", next, min, max);
		if(min==-1)	break;
	}
	if(min==-1)	{ printf("-1\n"); }
	else { printf("%d %d\n", min, max); }
}
return 0;
}
