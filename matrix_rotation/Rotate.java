class Rotate {
	private class MatrixRotater {
		// Prereq: matrix is NxN
		public String[][] rotate90(String[][] matrix) {
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
	}
}
