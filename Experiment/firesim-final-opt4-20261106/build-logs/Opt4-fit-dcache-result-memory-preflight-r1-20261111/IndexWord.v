module IndexWord(input [5:0] set,writeSet,input [2:0] way,writeWay,
 input [63:0] oldWord,newWord,data,input enable,reset,
 output indexEquivalent,nextEquivalent,mutantEquivalent);
 wire refHit=(set==writeSet)&&(way==writeWay);
 wire newHit=({set,way}=={writeSet,writeWay});
 wire [63:0] oldNext=(enable&&refHit)?data:oldWord;
 wire [63:0] newNext=(enable&&newHit)?data:newWord;
 wire [63:0] mutant=(enable&&newHit)?(data^64'h8000000000000000):newWord;
 assign indexEquivalent=(refHit==newHit);
 assign nextEquivalent=(oldWord!=newWord)||(oldNext==newNext);
 assign mutantEquivalent=(oldWord!=newWord)||(oldNext==mutant);
 endmodule
