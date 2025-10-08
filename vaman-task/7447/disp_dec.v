module disp_dec(
input wire A,
input wire B,
output reg a,
output reg b,
output reg c,
output reg d,
output reg e,
output reg f,
output reg g,
output reg led);
wire[1:0]ab;
assign ab={A,B};
wire Y;
assign Y=(~A)+B;
always@(*)
begin
led=Y;
case(ab)
2'b00:{a,b,c,d,e,f,g}=7'b1111110;
2'b01:{a,b,c,d,e,f,g}=7'b0110000;
2'b10:{a,b,c,d,e,f,g}=7'b1101101;
2'b11:{a,b,c,d,e,f,g}=7'b1111001;
default:{a,b,c,d,e,f}=7'b0000000;
endcase
end
endmodule

