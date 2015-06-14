package TutorialExamples

import Chisel._
import java.io.File

class Echo extends Module {
  val io = new Bundle {
    val in  = Bits(INPUT,  8)
    val out = Bits(OUTPUT, 8)
  }

  val samples = 4096
  require(isPow2(samples))

  val inSigned = (io.in - UInt(128)).toSInt // convert to two's complement

  val history = Mem(SInt(width = 8), samples)
  val pos = Reg(init=UInt(0, log2Up(samples)))
  pos := pos + UInt(1)

  // y[n] = x[n] + 0.5 * y[n - samples]
  val out = inSigned + (history(pos) >> UInt(1))

  history(pos) := out

  val outUnsigned = out + UInt(128) // convert back to excess-128 format
  io.out := outUnsigned
}

class EchoTests(c: Echo, val infilename: String, val outfilename: String) extends Tester(c) {  
  val in  = WavIn(infilename)
  val out = WavOut(outfilename, in.getFormat)

  var sample = in.read
  while (sample != -1) {
    poke(c.io.in, sample)
    step(1)
    out += peek(c.io.out).toByte
    sample = in.read
  }

  out.flush
  out.close
  ok = true
}
