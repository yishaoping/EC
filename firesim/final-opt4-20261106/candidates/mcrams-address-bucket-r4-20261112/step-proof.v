// A word-selectable inductive transition lemma, including all conflicting
// enables. word is arbitrary; therefore no per-address cases are omitted.
module StepProof(input [7:0] word,retireIndex,
 input [63:0] oldValue,processData,
 input process,en,retire,resetStats,
 output equivalent,mutantEquivalent);
 reg [63:0] refNext;
 always @* begin
   refNext=oldValue;
   if(process && en) refNext=processData;
   if(retire && word==retireIndex) refNext=0;
   if(resetStats) refNext=0;
 end
 wire clear=resetStats||(retire&&word==retireIndex);
 wire writeEnable=clear||(process&&en);
 wire [63:0] writeData=clear?64'b0:processData;
 wire [63:0] memNext=writeEnable?writeData:oldValue;
 assign equivalent=refNext==memNext;
 // Reject a candidate accidentally giving processing higher priority.
 wire [63:0] mutant=(process&&en)?processData:(clear?64'b0:oldValue);
 assign mutantEquivalent=refNext==mutant;
endmodule
