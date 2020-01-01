class MyException extends Exception{
	public MyException(String s) {
		super(s);
	}
}
public class UserDefException {

	public static void main(String[] args) {
		
		try {
			
			throw new MyException("here is a user defined exception");
		}catch(MyException e) {
			System.out.println("hello");
			System.out.println(e.getMessage());
		}
	}

}
