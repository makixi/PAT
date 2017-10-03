import java.util.Arrays;
import java.util.Scanner;

public class Main{
  public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    int ad=in.nextInt();
    int n=in.nextInt();
    int k=in.nextInt();
    int []nex=new int[100005];
    int []val=new int[100005];
    int []list=new int[100005];
    int index=0;
    for(int i=0;i<n;++i) {
      int tmp=in.nextInt();
      val[tmp]=in.nextInt();
      nex[tmp]=in.nextInt();
    }
    in.close();
    for(;ad!=-1;ad=nex[ad]) list[index++]=ad;
    for(int i=0;i<(index-index%k);i+=k) {
      for(int j=i;j-i<k*1.0/2;++j) {
        //System.out.println(j+" "+(2*i-j+k-1));
        int tmp=list[j];
        list[j]=list[2*i-j+k-1];
        list[2*i-j+k-1]=tmp;
        
      }
    }
    for(int i=0;i<index-1;++i)
      System.out.printf("%05d %d %05d\n", list[i],val[list[i]],list[i+1]);
    System.out.printf("%05d %d -1\n", list[index-1],val[list[index-1]]);
  }
  
}