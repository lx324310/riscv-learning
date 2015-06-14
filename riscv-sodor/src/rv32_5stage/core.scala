//**************************************************************************
// RISCV Processor 
//--------------------------------------------------------------------------
 
package Sodor
{

import Chisel._
import Node._
import Common._

class CoreIo(implicit conf: SodorConfiguration) extends Bundle 
{
   val host = new HTIFIO()
   val imem = new MemPortIo(conf.xprlen)
   val dmem = new MemPortIo(conf.xprlen)
}

class Core(resetSignal: Bool = null)(implicit conf: SodorConfiguration) extends Module(_reset = resetSignal)
{
   val io = new CoreIo()
   val c  = Module(new CtlPath())
   val d  = Module(new DatPath())
   
   c.io.ctl  <> d.io.ctl
   c.io.dat  <> d.io.dat
   
   c.io.imem <> io.imem
   d.io.imem <> io.imem
   
   c.io.dmem <> io.dmem
   d.io.dmem <> io.dmem
   
   d.io.host <> io.host
}

}
