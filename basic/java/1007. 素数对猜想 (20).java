import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		in.close();
		LinkedList<Integer> prime=new LinkedList<Integer>();
		for(int i=2;i<=n;++i)
			if(isPrime(i))prime.add(i);
		int cnt=0;
		for(int i=0;i<prime.size()-1;++i)
			if(prime.get(i)-prime.get(i+1)==-2)++cnt;
		System.out.println(cnt);
	}
	public static boolean isPrime(int n) {
		for(int i=2;i<=Math.sqrt(n);++i)
			if(n%i==0)return false;
		return true;
	}
}
