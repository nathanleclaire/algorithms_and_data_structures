class Rotate {
	private static class MatrixRotater {
		// Prereq: matrix is NxN
		static public String[][] rotate90(String[][] matrix) {
			int n = matrix[0].length;
			for (int layer=0; layer < n / 2; layer++) {
				int first = layer;
				int last = n - 1 - layer;
				for(int i=first; i < last; i++) {
					int offset = i - first;
					// save top
					String top = matrix[first][i];

					// left -> top
					matrix[first][i] = matrix[last-offset][first];

					// bottom -> left
					matrix[last-offset][first] = matrix[last][last-offset];

					// right -> bottom
					matrix[last][last-offset] = matrix[i][last];

					// top -> right
					matrix[i][last] = top;
				}
			}
			return matrix;
		}

	}

	private static class MatrixPrinter {
		static public void printMatrix(String[][] matrix) {
			System.out.println("{");
			for(int i = 0; i < matrix.length; i++) {
				System.out.print("{");
				for(int j = 0; j < matrix[i].length; j++) {
					System.out.print("\"");
					System.out.print(matrix[i][j]);
					System.out.print("\" ");
				}
				System.out.print("}\n");
			}
			System.out.print("}\n");
		}
	}

	public static void main(String[] args) {
		String[][] matrix = new String[][]{
			{"11", "22", "33", "44", "55"},
			{"66", "77", "88", "99", "00"},
			{"AA", "BB", "CC", "DD", "EE"},
			{"FF", "A0", "B0", "C0", "D0"},
			{"E0", "F0", "A1", "A2", "A3"},
		};

		// MatrixRotater matrixRotater = new MatrixRotater();
		MatrixPrinter.printMatrix(matrix);
		System.out.println("Rotating...");
		MatrixPrinter.printMatrix(MatrixRotater.rotate90(matrix));
	}
}
