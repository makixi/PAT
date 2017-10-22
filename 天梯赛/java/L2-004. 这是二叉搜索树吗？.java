import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static LinkedList<Integer> pre=new LinkedList<>();
	public static LinkedList<Integer> post=new LinkedList<>();
	public static boolean isMirror;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		isMirror=false;
		for(int i=0;i<n;++i)
			pre.add(in.nextInt());
		getpost(0,n-1);
		if(post.size()!=n) {
			isMirror=true;
			post.clear();
			getpost(0,n-1);
		}
		if(post.size()==n) {
			System.out.printf("YES\n%d", post.get(0));
			for(int i=1;i<n;++i)System.out.print(" "+post.get(i));
		}else System.out.print("NO");
	}
	
	public static void getpost(int root,int tail) {
		if(root>tail)return;
		int i=root+1,j=tail;
		if(!isMirror) {
			while(i<=tail&&pre.get(root)>pre.get(i))++i;
			while(j>root&&pre.get(root)<=pre.get(j))--j;
		}else {
			while(i<=tail&&pre.get(root)<=pre.get(i))++i;
			while(j>root&&pre.get(root)>pre.get(j))--j;
		}
		if(i-j!=1)return;
		getpost(root+1,j);
		getpost(i,tail);
		post.addLast(pre.get(root));
	}
}

