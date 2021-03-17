void towers(int number_of_disks, int b[ ][3], int from_col, int to_col, int spare) {
If(number of disks is >= 1)
Call Towers with (number_of_disks-1, b, from_ col, spare, to_ col) Move the disk
Print the board
Call Towers with (number_of_disks-1, b, spare, to_ col, from_ col)
}