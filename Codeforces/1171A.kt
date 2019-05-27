private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
//fun f(x: Int): Int {
//    var cur = x + 1
//    while (cur % 10 == 0) cur /= 10
//    return cur
//}
fun main(){
	var z = 0
	var t = readInt()
	while (t > z)
	{
		var n = readInt()
		if(n%2 == z){
			println(n/2)
		}
		else{
			println(1 + (n-3)/2)
		}
		t--
	}
}