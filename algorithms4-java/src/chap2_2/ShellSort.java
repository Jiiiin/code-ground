package chap2_2;
import chap2_2.SortBase;
import edu.princeton.cs.algs4.In;

public class ShellSort extends SortBase{
	public static void sort(Comparable a[]) {
		int N = a.length;
		int h = 1;
		while (h < N / 3) {
			h = 3 * h + 1;
		}
		while (h >= 1) {
			for (int i = h; i < N; i++) {
				for (int j = i; j >= h && less(a[j], a[j - h]); j -= h) {
					exch(a, j, j - h);
				}
			}
			h = h / 3;
		}
	}
	
	
	public static void main(String[] args) {
		String[] a = {"s", "h", "e", "l", "l", "s", "o", "r", "t", "e", "x", "a", "m", "p", "l", "e"};
//		String[] a = new In().readAllStrings();
		sort(a);
		assert isSorted(a);
		show(a);
	}

}
