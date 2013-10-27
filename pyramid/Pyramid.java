class Pyramid {
	public static void main(String[] args) {
		if (args.length != 1) {
			System.out.println("Usage: java Pyramid [n]");
			System.out.println("n - the number of levels of the pyramid to print out");
			System.exit(0);
		}
		int n = Integer.parseInt(args[0]);
		for(int i=0; i < n; i++) {
			for (int j=0; j < (n-i); j++) {
				System.out.print("_");
			}
			for (int j=0; j <= i; j++) {
				System.out.print("O");
				if (j+1 <= i) {
					System.out.print("_");
				}
			}
			System.out.print("\n");
		}
	}
}
