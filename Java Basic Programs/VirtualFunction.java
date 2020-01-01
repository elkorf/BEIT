
class Shape{
	void area(){
		System.out.println("Calculate Area.");
	}
	
	void area(int radius){
		System.out.println("Area : "+radius*3.14*4.14);
	}
}
	
class MethodOverloading extends Shape{
	void area(int height,int breadth){
		System.out.println("Area : "+height*breadth);
	}
	public static void main(String args[]){
		Shape ob1 = new MethodOverloading();
		ob1.area();
	}
}


