
object TestCom {
  def hallo() { println("Hallo (object)") } // [2]
  def hello() { println("Hello (object)") } // [3]
}

class TestCom {
  def hello() { println("Hello (class)") } // [1]
}