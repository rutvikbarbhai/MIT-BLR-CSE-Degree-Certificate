import myPackages.p1.Maximum;
public class findMax{
	public static void main(String[] args){
		Maximum mx = new Maximum();
		int a = mx.max(2,5,7);
		System.out.println(a);
		int[] b = {3,1,4,5,2};
		a = mx.max(b);
		System.out.println(a);
		int[][] c = {
				{2,4,7},
				{8,1,9},
				{3,5,6}};
		a = mx.max(c);
		System.out.println(a);
	}
}