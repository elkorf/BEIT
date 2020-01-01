abstract class Dog{
	void bark(){
		System.out.print("Dog Barks.");
	}
	abstract void jump();
}
class Cat extends Dog{
	void jump() {	
		System.out.print("Cat Jumps.");
	}
}
public class AbstractClass extends Cat{
	void jump(){
		System.out.print("Dog also jumps.");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	Cat	d = new AbstractClass();
	d.jump();
	}

}
