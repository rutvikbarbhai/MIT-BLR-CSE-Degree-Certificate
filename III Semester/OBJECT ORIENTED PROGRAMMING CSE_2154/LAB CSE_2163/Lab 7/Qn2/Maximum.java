package myPackages.p1;
public class Maximum{
	public static int max(int a, int b, int c){
		int d;
		d = a>b?(a>c?a:c):(b>c?b:c);
		System.out.println("The max is " + d);
		return d;
	}
	public static float max(float a, float b, float c){
		float d;
		d = a>b?(a>c?a:c):(b>c?b:c);
		System.out.println("The max is " + d);
		return d;
	}

	public static int max(int[] arr){
		int i, len, max = -1;
		len = arr.length;
		for(i = 0; i < len; i++){
			if(arr[i]>max)
				max = arr[i];
		}
		System.out.println("The max is " + max);
		return max;
	}

	public static int max(int[][] arr){
		int i, j, len, max = -1;
		len = arr.length;
		for(i = 0; i < len; i++){
			for(j = 0; j<len; j++){
				if(arr[i][j]>max)
					max = arr[i][j];
			}
		}
		System.out.println("The max is " + max);
		return max;
	}
}