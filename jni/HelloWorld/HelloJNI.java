
import gear.Gear;

public class HelloJNI {
	static {
		System.loadLibrary("hello");
		System.loadLibrary("gear");
	}

	private native void sayHello();

	public static void main(String[] args) {
		new HelloJNI().sayHello();
		new Gear().doSomething();
	}
}
