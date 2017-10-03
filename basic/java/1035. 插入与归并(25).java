import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int ori[]=new int[n];
		int as[]=new int[n];
		int i,j;
		for(i=0;i<n;++i)ori[i]=in.nextInt();
		for(i=0;i<n;++i)as[i]=in.nextInt();
		for(i=1;i<n&&as[i-1]<=as[i];++i);
		for(j=i;j<n&&ori[j]==as[j];++j);
		if(j==n) {
			System.out.println("Insertion Sort");
			Arrays.sort(ori, 0, i+1);
		}else {
			System.out.println("Merge Sort");
			int k = 1;
			boolean flag = true;
			while (flag) {
				flag=false;
				for (i = 0; i < n; i++)
					if (ori[i] != as[i])
						flag = true;
				k *= 2;
				for (i = 0; i < n / k; i++)
					Arrays.sort(ori, i*k, (i + 1)*k);
				Arrays.sort(ori, k*(n / k), n);
			}
		}
		for(i=0;i<n;++i) {
			if(i!=0)System.out.print(" ");
			System.out.print(ori[i]);
		}
	}
	
	
}