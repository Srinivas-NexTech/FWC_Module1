module sevenseg(
input wire A,
input wire B,
output wire Y,
output reg a,
output reg b,
output reg c,
output reg d,
output reg e,
output reg f,
output reg g
);
assign Y=(~A)+B;
always@(*)
begin
if(y==1)
 {a,b,c,d,e,f,g}=7'b0110000;
else
 {a,b,c,d,e,f,g}=7'b0000001;
end
endmodule
