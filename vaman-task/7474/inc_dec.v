module inc_dec(
input wire clk, 
input wire A,
input wire B,
output reg led,
output reg[6:0]seg
);
reg a,b;
always@(posedge clk)
begin
a<=A;
b<=B;
end
wire Y;
assign Y=(~a)|b;
wire[1:0]ab={a,b};
always@(*)
begin
led=Y;
case(ab)
2'b00:seg=7'b1111110;
2'b01:seg=7'b0110000;
2'b10:seg=7'b1101101;
2'b11:seg=7'b1111001;
default:seg=7'b0000000;
endcase
end
endmodule
