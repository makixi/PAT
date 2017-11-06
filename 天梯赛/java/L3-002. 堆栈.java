import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static final int maxn=100001;
	public static int c[]=new int [maxn];
	public static Stack<Integer> s=new Stack<>();
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),a=0;
		for(int i=0;i<n;++i) {
			String str=in.next();
			if(str.charAt(1)=='o') {
				if(s.empty())System.out.println("Invalid");
				else {
					update(s.peek(),-1);
					System.out.println(s.peek());
					s.pop();
				}
			}else if(str.charAt(1)=='e') {
				if(s.empty())System.out.println("Invalid");
				else PeekMedian();
			}else {
				a=in.nextInt();
				s.push(a);
				update(a,1);
			}
		}
	}

	public static int lowbit(int i) {
		return (i)&(-i);
	}
	
	public static void update(int x,int v) {
		for(;x<maxn;x+=lowbit(x))c[x]+=v;
	}
	
	public static int getsum(int x) {
		int res=0;
		for(;x>=1;x-=lowbit(x))res+=c[x];
		return res;
	}
	
	public static void PeekMedian() {
		int left=1,right=maxn,mid,k=(s.size()+1)/2;
		while(left<right) {
			mid=(left+right)>>1;
			if(getsum(mid)>=k)right=mid;
			else left=mid+1;
		}
		System.out.println(left);
	}
}

