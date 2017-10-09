import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;++i)a[i]=in.nextInt();
		in.close();
		Arrays.sort(a);
		int p=n-1,day=0;
		while(day<=n&&a[p]>n-p) {
			++day;--p;
		}
		System.out.print(day);
	}
}
