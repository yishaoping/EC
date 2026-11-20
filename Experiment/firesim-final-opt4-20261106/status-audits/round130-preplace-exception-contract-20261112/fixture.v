// Diagnostic primitive netlist only; never part of the host or target design.
module exception_contract_fixture(input clk, input rst, output [3:0] out);
  wire c0, c1;
  BUFG b0 (.I(clk), .O(c0));
  BUFG b1 (.I(clk), .O(c1));
  FDRE r0 (.C(c0), .CE(1'b1), .R(rst), .D(out[1]), .Q(out[0]));
  FDRE r1 (.C(c0), .CE(1'b1), .R(rst), .D(out[0]), .Q(out[1]));
  FDRE r2 (.C(c1), .CE(1'b1), .R(rst), .D(out[3]), .Q(out[2]));
  FDRE r3 (.C(c1), .CE(1'b1), .R(rst), .D(out[2]), .Q(out[3]));
endmodule
