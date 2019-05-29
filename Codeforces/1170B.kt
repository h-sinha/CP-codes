//kotlinc file.kt -include-runtime -d file.jar
//java -jar file.jar

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
// type of var var.javaClass.name
fun main(){
		var n = readInt()
		var numbers = readInts()
		var ans :Int = 0
		var mx1:Int = -1
		var mx2:Int = -1
		for(i in 0..n-1){
			if(mx1>numbers[i] && mx2> numbers[i]){
				ans++
			}
			if(numbers[i]>mx1){
				mx2 = mx1
				mx1 = numbers[i]
			}
			else if(numbers[i]>mx2){
				 mx2 = numbers[i]
			}
		}
		println(ans)
		
}