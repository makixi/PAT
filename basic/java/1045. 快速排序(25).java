import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int v[]=new int[n];
		int a[]=new int[n];
		for(int i=0;i<n;++i) {
			v[i]=in.nextInt();a[i]=v[i];
		}
		Arrays.sort(a);
		List<Integer> list=new ArrayList<>();
		int maxn=Integer.MIN_VALUE;
		for(int i=0;i<n;++i) {
			if(a[i]==v[i]&&v[i]>maxn) 
				list.add(a[i]);
			if(maxn<v[i])maxn=v[i];
		}
		System.out.println(list.size());
		System.out.print(list.get(0));
		for (int i = 1; i < list.size(); i++) 
			System.out.print(" " + list.get(i));
	}
}