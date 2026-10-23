package freechips

package object rocketchip {
  object config {
    type Field[T] = org.chipsalliance.cde.config.Field[T]
    type View = org.chipsalliance.cde.config.View
    type Parameters = org.chipsalliance.cde.config.Parameters
    val Parameters = org.chipsalliance.cde.config.Parameters
    type Config = org.chipsalliance.cde.config.Config
  }
}
