import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt(),k=in.nextInt();
		Person[] p=new Person[n];
		for(int i=0;i<n;++i)p[i]=new Person(in.next(),in.nextInt());
		in.close();
		Arrays.sort(p);
		int per = n / k;
		for (int i = k; i >= 1; i--) {
			int len = 0;
			int index = 0;
			if (i == k) {
				len = n - k * per + per;
				index = n-1;
			} else {
				len = per;
				index = i * per - 1;
			}
			Person[] temp = new Person[len];
			int left = len / 2;
			int right = len / 2;
			temp[left] = p[index--];
			left--;right++;
			while (left >= 0 && right < len) {
				temp[left--] = p[index--];
				temp[right++] = p[index--];
			}
			if (left >= 0) temp[left] = p[index];
			else if (right < len) temp[right] = p[index];
			for (int j = 0; j < len - 1; j++) System.out.print(temp[j].name + " ");
			System.out.println(temp[len - 1].name);
		}
	}
}
class Person implements Comparable<Person>{
	String name;
	int height;
	public Person(String ss,int hh) {
		this.name=ss;
		this.height=hh;
	}
	@Override
	public int compareTo(Person a) {
		if(this.height<a.height)return -1;
		else if(this.height>a.height)return 1;
		else return -this.name.compareTo(a.name);
	}
}