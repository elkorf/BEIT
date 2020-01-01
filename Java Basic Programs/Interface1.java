interface i1{
	default void show() {
		System.out.println("Interface 1 ");
	}
}

interface i2{
	default void show() {
		System.out.println("Interface 2 ");
	}
}

class Interface1 implements i1,i2{
	public void show() {
		i1.super.show();
		i2.super.show();
	}

	public static void main(String[] args) {
		Interface1 i = new Interface1();
		i.show();
	}

}
