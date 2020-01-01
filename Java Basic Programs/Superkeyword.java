
class Parent{
	int a=10;
	void disp() {
		System.out.print("disp method in parent class");
	}
}

public class Superkeyword extends Parent{
	int a =100;
	void disp() {
		System.out.println("disp method in child class");
	}
	void show() {
		disp();
		super.disp();
		
		System.out.println("this is child class a : "+a+"\nthis is parent class a  : "+super.a);
	}
	public static void main(String[] args) {
		Superkeyword s=new Superkeyword();
		s.show();
	}	
}
