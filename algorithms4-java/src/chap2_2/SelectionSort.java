package chap2_2;
import chap2_2.SortBase;

public class SelectionSort extends SortBase {
	public static void sort(Comparable a[]) {
		int N = a.length;
		for (int i=0;i<N;i++) {
			int min = i;
			for(int j=i;j<N;j++) {
				if (less(a[j], a[min])) min=j;
				exch(a, min, i);
			}
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
