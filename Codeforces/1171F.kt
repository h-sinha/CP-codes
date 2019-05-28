// kotlinc file.kt -include-runtime -d file.jar
// java -jar file.jar

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
// for (x in 1..10 step 2) {
// type of var var.javaClass.name
class Segment(val pair: Pair<Int, Int>, val index: Int, var group: Int)

fun main(){
	var t = readInt()
	while(t > 0){
		var n = readInt()
	    var numbers = ArrayList<Triple<Int,Int,Int>>()
	    var ans = ArrayList<Int>()
		for (x in 0..n-1) {
			var(l,r) = readInts()
			numbers.add(Triple(l,r,x))
			ans.add(0)
		}

	    var sortedList = numbers.sortedWith(compareBy({ it.first }))
	    var r :Int = sortedList[0].second
		for(i in 0..n-1){
			if(r >= sortedList[i].first){
				ans[sortedList[i].third] = 1
				if(sortedList[i].second > r){
					r = sortedList[i].second
				}
			}
		}
		var co = mutableListOf(0,0)
		for(i in 0..n-1){
			co[ans[i]]++
		}
		if(co[0] == n || co[1] == n){
			println(-1)
		}
		else{
			for(i in 0..n-1){
				print(ans[i]+1)
				print(" ")
			}
			println()
		}
		t--;
	}	
}
