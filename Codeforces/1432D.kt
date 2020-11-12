private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts(): List<Int> = readStrings().map { it.toInt() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        t--;
        var (n, a, b) = readInts();
        var arr = Array<Char>(n) { 'a' };
        for (i in 0 until b) {
            arr[i] = (i + 'a'.toInt()).toChar();
        }
        for (i in b until n) {
            arr[i] = arr[i - b];
        }
        for (x in arr) print(x);
        println();
    }
}