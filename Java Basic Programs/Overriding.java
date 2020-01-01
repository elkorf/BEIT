class Show{
		void print() {
			System.out.print("Hello world");
		}
}
public class Overriding extends Show{
	void print() {
		System.out.print("Hiii");
	}	
	public static void main(String args[]) {
		Show s = new Show();
		s = new Overriding();
		s.print();
	}
}
