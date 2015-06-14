package TutorialExamples

import Chisel._

class VecSearch extends Module {
  val io = new Bundle {
    val out = UInt(OUTPUT,  4)
  }
  val index = Reg(init = UInt(0, width = 3))
  val elts  = Vec(UInt(0), UInt(4), UInt(15), UInt(14),
                  UInt(2), UInt(5), UInt(13))
  // val elts  = Vec.fill(8){ Reg(UInt(width = 4)) }
  // elts(index) := index
  index := index + UInt(1)
  io.out := elts(index)
}

class VecSearchTests(c: VecSearch) extends Tester(c) {
  val list = c.elts.map(int(_)) 
  for (elt <- list) {
    expect(c.io.out, elt)
    step(1)
  }
}
