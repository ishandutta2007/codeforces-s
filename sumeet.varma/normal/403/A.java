import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R236qASearchingForGraph {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int t = in.nextInt();
		
		while(t-- > 0){
			int n = in.nextInt();
			int p = in.nextInt();
			
			boolean can[][] = new boolean[n + 1][n + 1];
			for(int i=1;i<=n;i++)
				Arrays.fill(can[i], true);
			
			for(int i=1;i<=n;i++){
				w.println(i + " " + g(i+1,n));
				w.println(i + " " + g(i+2,n));
				can[i][g(i+1,n)] = can[g(i+1,n)][i] = false;
				can[i][g(i+2,n)] = can[g(i+2,n)][i] = false;
				can[i][i] = false;
			}
			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(can[i][j] && can[j][i]){
						if(p > 0){
							p--;
							can[i][j] = can[j][i] = false;
							w.println(i + " " + j);
						}
					}
				}
			}
		}
		
		w.close();
	}
	
	static int g(int x,int n){
		return x <= n ? x : x - n;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}