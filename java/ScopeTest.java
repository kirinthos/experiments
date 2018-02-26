class Test {
	int level = 10;

	public void doSomething(int level) {
		System.out.println(level);
		System.out.println(this.level);
	}
}

public class ScopeTest {
	
	public static void main(String[] args) {
		Test t = new Test();
		t.doSomething(1);
	}
}
