import Sudoku


if __name__ == "__main__":
    sudoku = Sudoku.sudoku("017903600000080000900000507072010430000402070064370250701000065000030000005601720")
    assert sudoku.get_grid()[0][0]==0
    assert sudoku.get_grid()[8][8]==0

    assert sudoku.get_row(0) == [0, 1, 7, 9, 0, 3, 6, 0, 0]
    assert sudoku.get_row(8) == [0, 0, 5, 6, 0, 1, 7, 2, 0]

    assert sudoku.get_column(0) == [0, 0, 9, 0, 0, 0, 7, 0, 0]
    assert sudoku.get_column(8) == [0, 0, 7, 0, 0, 0, 5, 0, 0]

    assert sudoku.get_box(0, 0) == [0, 1, 7, 0, 0, 0, 9, 0, 0]

    assert sudoku.solve() == True
    print("All tests passed!")