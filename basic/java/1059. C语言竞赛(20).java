import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		Map IdtoRank=new HashMap(); 
		boolean mark[]=new boolean[10000];
		int n=in.nextInt();
		for(int i=1;i<=n;++i) {
			int id=in.nextInt();
			IdtoRank.put(id, i);
		}
		int k=in.nextInt();
		for(int i=0;i<k;++i) {
			int id=in.nextInt();
			System.out.printf("%04d: ", id);
			if(IdtoRank.get(id)==null) {
				System.out.println("Are you kidding?");
				continue;
			}else if(mark[id]) {
				System.out.println("Checked");
				continue;
			}
			int rank=Integer.parseInt(IdtoRank.get(id).toString());
			if(rank==1) System.out.println("Mystery Award");
			else if(judge(rank))System.out.println("Minion");
			else System.out.println("Chocolate");
			mark[id]=true;
		}
	}
	
	public static boolean judge(int num) {
		if(num<=1)return false;
		for(int i=2;i*i<=num;++i)
			if(num%i==0)return false;
		return true;
	}
}
