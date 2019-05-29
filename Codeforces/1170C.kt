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
	var t = readInt()
	while(t>0){
		var s1 = readLn()
		var s2 = readLn()
		var len1:Int = s1.length
		var len2:Int = s2.length
		var f:Int = 0
		var i:Int = 0
		var j:Int = 0
		while(i<len1 && j<len2){
			if(s1[i] == s2[j]){
				i++
				j++
				continue
			}
			if(s1[i] == '-' && s2[j] == '+'){
				if(i<len1-1 && s1[i+1] == '-'){
					i++
					// j++
				}
				else{
					f=1
					break
				}
			}
			else{
				f = 1
				break
			}
			i++
			j++
		}
		if(f == 1 || i<len1 ||j<len2){
			println("NO")
		}
		else{
			println("YES")
		}
		t--
	}	
}