import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
/*

0
1
4
9


0
1 0
4 3 2 1 0
  8 7 6 5 4 3 2 1
0 1 2 3 4 5 6 7 8
0 8 7 6 5 4 3 2 1

0
1 0
4 3 2 1 0
    7 6 5 4 3 2
0 1 2 3 4 5 6 7
1 0 7 6 5 4 3 2

0
1 0
4 3 2 1 0
      6 5 4 3
0 1 2 3 4 5 6
1 0 2 6 5 4 3 

0
1 0
4 3 2 1 0
9 8 7 6 5 4 3 2 1 0 
           10 9 8 7  6
0 1 2 3 4 5 6 7 8 9 10

Start with the first square number bigger than or equal to n



If the length is a perfect square, we can do it in reverse order




0
1 0
4 3 2 1 0
0 1 2

 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
//		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int start=0;
			int toPlace=n-1;
			while (start*start<toPlace) start++;
			int[] ans=new int[n];
			int earliestPlacedAt=n;
			int nextChainEnd=n;
			while (toPlace>=0) {
				int curIndex=start*start-toPlace;
//				System.out.println(curIndex+" "+start+" "+toPlace);
				if (curIndex>=earliestPlacedAt) {
					start--;
					earliestPlacedAt=nextChainEnd;
					if (start<0) throw null;
					continue;
				}
//				System.out.println("Placing "+toPlace+" at "+curIndex);
				ans[curIndex]=toPlace--;
				nextChainEnd=Math.min(nextChainEnd, curIndex);
			}
			for (int i:ans) out.print(i+" ");
			out.println();
		}
		out.close();
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}