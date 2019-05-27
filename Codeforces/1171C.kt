private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
//fun f(x: Int): Int {
//    var cur = x + 1
//    while (cur % 10 == 0) cur /= 10
//    return cur
//}
//val a: Int? = 1 
fun main(){
	var t = readInt()
	while(t > 0){
		var s = readLn().toCharArray()
		s.sort()
		if(s[0] == s[s.size - 1]){
			println("-1")
		}
		else{
			println(s)
		}
		t--
	}	
}