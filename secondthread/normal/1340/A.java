import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer:for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			for (int i=0; i<n; i++) a[i]--;
			int[] indexOf=new int[n];
			for (int i=0; i<n; i++) indexOf[a[i]]=i;
			int nextEnd=n-1;
			int curEnd=n-1;
			int lastIndex=a[0];
			boolean free=true;
			for (int i=0; i<n; i++) {
				int pos=indexOf[i];
				if (free) {
					nextEnd=pos-1;
				}
				else {
					if (pos!=lastIndex+1) {
						out.println("No");
						continue outer;
					}
				}
				if (pos==curEnd) {
					free=true;
					curEnd=nextEnd;
				}
				else {
					free=false;
				}
				lastIndex=pos;
			}
			out.println("Yes");
		}
		out.close();
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}