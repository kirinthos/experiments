
public class Statics
{
	static {
		System.loadLibrary("statics");
	}

	public static void main(String[] args)
	{
		System.out.println("testing statics...");
		SomeClass s = new SomeClass();
		s.doSomething();
	}
}
