#include<stdio.h>
void main(){
   int pn,i,k,fsize,avail,pagefault=0;
   printf("Enter the no of pages :");
   scanf("%d",&pn);
   int refstr[pn];
   int frames[3]={-1,-1,-1};
   printf("Enter the reference string");
   for(i=0;i<pn;i++){
      scanf("%d",&refstr[i]);
   }
   printf("Reference string | Frame\n");
   int j=0;
   for(i=0;i<pn;i++){
   printf("            %d  | ",refstr[i]);
      avail=0;
      for(k=0;k<fsize;k++){
         if(frames[k]==refstr[i]){
           avail=1;
           break;
         }
      }
      if(avail==0){
        frames[j]=refstr[i];
        j=(i+1)%3;
        pagefault++;
      }
      for(k=0;k<3;k++){
        printf("%d ",frames[k]);
      }
      printf("\n");
   }
   printf("Page fault =%d",pagefault);
}

     
	

