import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s=in.nextLine();
		in.close();
		int a[]=new int[10];
		for(int i=0;i<11;++i)a[s.charAt(i)-'0']++;
		Vector<Integer> arr=new Vector<>();
		for(int i=9;i>=0;--i)if(a[i]!=0)arr.add(i);
		Vector<Integer> index=new Vector<>();
		for(int i=0;i<=10;++i)
			for(int j=0;j<arr.size();++j)
				if((s.charAt(i)-'0')==arr.get(j))index.add(j);
		System.out.print("int[] arr = new int[]{"+arr.get(0));
		for(int i=1;i<arr.size();++i)System.out.print(","+arr.get(i));
		System.out.print("};\nint[] index = new int[]{"+index.get(0));
		for(int i=1;i<index.size();++i)System.out.print(","+index.get(i));
		System.out.print("};");
	}
}