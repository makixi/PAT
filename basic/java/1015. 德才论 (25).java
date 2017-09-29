import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int l=in.nextInt();
		int h=in.nextInt();
		Set<Student> a=new TreeSet<>();
		Set<Student> b=new TreeSet<>();
		Set<Student> c=new TreeSet<>();
		Set<Student> d=new TreeSet<>();
		for(int i=0;i<n;++i) {
			int id=in.nextInt();
			int mo=in.nextInt();
			int talent=in.nextInt();
			if(mo>=l&&talent>=l) {
				Student tmp=new Student(id,mo,talent,h);
				switch (tmp.type) {
				case 1:a.add(tmp);break;
				case 2:b.add(tmp);break;
				case 3:c.add(tmp);break;
				case 4:d.add(tmp);break;
				}
			}
		}
		in.close();
		System.out.println(a.size()+b.size()+c.size()+d.size());
		for(Student s:a)System.out.printf("%08d %d %d\n", s.id,s.mo,s.talent);
		for(Student s:b)System.out.printf("%08d %d %d\n", s.id,s.mo,s.talent);
		for(Student s:c)System.out.printf("%08d %d %d\n", s.id,s.mo,s.talent);
		for(Student s:d)System.out.printf("%08d %d %d\n", s.id,s.mo,s.talent);
	}
}

class Student implements Comparable<Student>{
	int id;
	int mo;
	int talent;
	int score;
	int type;
	public Student(int id,int mo,int talent,int h) {
		this.id=id;
		this.mo=mo;
		this.talent=talent;
		this.score=talent+mo;
		if(mo>=h&&talent>=h)type=1;
		else if(mo>=h&&talent<h)type=2;
		else if(mo<h&&talent<h&&mo>=talent)type=3;
		else type=4;
	}
	public int compareTo(Student stu) {
		if(this.score<stu.score)return 1;
		else if(this.score>stu.score)return -1;
		else {
			if(this.mo<stu.mo)return 1;
			else if(this.mo>stu.mo)return -1;
			else {
				if(this.id>stu.id)return 1;
				else if(this.id<stu.id)return -1;
				else return 0;
			}
		}
	}
}
